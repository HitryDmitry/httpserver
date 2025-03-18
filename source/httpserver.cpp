#include "httpserver.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
#include <QByteArray>
#include <QString>

//json specific
#include <QJsonParseError>
#include <QJsonObject>

#include "jsonutils.h"


HttpServer::HttpServer(QObject* parent) : QObject(parent) {
    netManager = new QNetworkAccessManager(this);

    auto jsonConfObj = JsonUtils::readJsonFile("./config.json");
    
    QUrl requestUrl = jsonConfObj["getIamTokenUrl"].toString();
    this->modelUrl = jsonConfObj["modelUrl"].toString();

    QNetworkRequest requestOAuthToken(requestUrl);
    requestOAuthToken.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject dataJson;
    dataJson["yandexPassportOauthToken"] = jsonConfObj["OAuthToken"];
    QJsonDocument dataDoc(dataJson);
    QByteArray dataBytes = dataDoc.toJson(); 

    // Обменяем OAuth-токен на IAM-токен:
    auto replyWithIam = netManager->post(requestOAuthToken, dataBytes);

    QObject::connect(replyWithIam, &QNetworkReply::finished, this, [replyWithIam, this]() {
        if (replyWithIam->error())
        {
            qDebug() << "ERROR in constructor!";
            qDebug() << replyWithIam->errorString();
        }
        else
        {
            auto yandexReplyWithIam = replyWithIam->readAll();
            auto yandReplyJson = QJsonDocument::fromJson(yandexReplyWithIam).object();
            this->iamToken = yandReplyJson["iamToken"].toString();
            qDebug() << "IamToken received successfully.";
        }
        replyWithIam->deleteLater();
    });
}

void HttpServer::sendPrompt(const QString& prompt)
{
    const char* filepath = "./prompt_request_body.json";
    auto promptJson = JsonUtils::addMsgToPromptHistory(JsonUtils::readJsonFile(filepath), "user", prompt);

    QNetworkRequest promptRequest(this->modelUrl);
    promptRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    promptRequest.setRawHeader(QByteArray("Authorization"), QString(QString("Bearer ") + iamToken).toUtf8());

    qDebug() << "Authorization: " << QString(QString("Bearer ") + this->iamToken);

    QJsonDocument promptJsonDoc(promptJson);
    QByteArray promptInBytes = promptJsonDoc.toJson();

    // отправляем промпт и iamToken
    auto reply = netManager->post(promptRequest, promptInBytes);

    // получаем ответ
    QObject::connect(reply, &QNetworkReply::finished, this, [this, reply, promptJson, filepath]() {
     if (reply->error())
     {
         qDebug() << "ERROR while making request!";
         qDebug() << reply->errorString();
     }
     else
     {
         auto replyToPrompt = reply->readAll();

         this->currentReplyToPromptJson = QJsonDocument::fromJson(replyToPrompt).object();

         QString replyText = this->currentReplyToPromptJson.value("result").toObject().value("alternatives").toArray().at(0).toObject().value("message").toObject().value("text").toString();
         auto jsonToDump = QJsonDocument(JsonUtils::addMsgToPromptHistory(promptJson, "assistant", replyText)).toJson();
         JsonUtils::writeToJson(jsonToDump, filepath);

         emit responseReceived(replyText);
     }
     reply->deleteLater();
    });
}
