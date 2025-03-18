#ifndef HTTPSERVER_JSONUTILS_H
#define HTTPSERVER_JSONUTILS_H

#include <QFile>
#include <QByteArray>
#include <QString>
#include <QDebug>

#include <QDebug>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonValue>

class JsonUtils{
public:
    static QJsonObject readJsonFile(const char* filename){
        // Получаем данные для обмена на iamToken из конфига
        QFile configFile;
        configFile.setFileName(filename);
        if(!configFile.open(QIODevice::ReadOnly)){
            qDebug() << "Json config file couldn't be opened/found";
        }

        QByteArray byteArray;
        byteArray = configFile.readAll();
        configFile.close();

        // парсим
        QJsonParseError parseError;
        QJsonDocument jsonConfDoc;
        jsonConfDoc = QJsonDocument::fromJson(byteArray, &parseError);

        // получаем объект json
        QJsonObject jsonConfObj = jsonConfDoc.object();

        return jsonConfObj;
    }

    static void writeToJson(QByteArray& doc, const char* filepath){
        QFile outFile(filepath);
        outFile.open(QIODevice::WriteOnly);
        outFile.write(doc);
    }

    static QJsonObject addMsgToPromptHistory(QJsonObject promptJson, const QString& role, const QString& msg){
        // Добавляем промпт в запрос
        QJsonObject newMsg;
        newMsg["role"] = role;
        newMsg["text"] = msg;

        auto newMsgArr = promptJson["messages"].toArray();
        newMsgArr.append(newMsg);
        promptJson.insert("messages", newMsgArr);
        return promptJson;
    }
};

#endif //HTTPSERVER_JSONUTILS_H
