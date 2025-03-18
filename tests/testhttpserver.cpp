#include "testhttpserver.h"

#include <QString>
#include <QByteArray>
#include <QFile>
#include <QIODevice>

#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

//QByteArray readFromFile(const QString& filename)
//{
//    QFile file(filename);
//    if(!file.exists()) {
//        throw std::runtime_error("No file with name " + filename.toStdString());
//    }
//    file.open(QIODevice::ReadOnly | QIODevice::Text);
//    QByteArray arr = file.readAll();
//    return arr;
//}

//QJsonObject readJsonFile(const char* filename){
//    // Получаем данные для обмена на iamToken из конфига
//    QFile configFile;
//    configFile.setFileName(filename);
//    if(!configFile.open(QIODevice::ReadOnly)){
//        qDebug() << "Json config file couldn't be opened/found";
//    }
//
//    QByteArray byteArray;
//    byteArray = configFile.readAll();
//    configFile.close();
//
//    // парсим
//    QJsonParseError parseError;
//    QJsonDocument jsonConfDoc;
//    jsonConfDoc = QJsonDocument::fromJson(byteArray, &parseError);
//
//    // получаем объект json
//    QJsonObject jsonConfObj = jsonConfDoc.object();
//
//    return jsonConfObj;
//}

TestHttpServer::TestHttpServer(QObject *parent) :
    QObject(parent)
{}

void TestHttpServer::setUpHttpServer(){}


void TestHttpServer::sendPromptToYaGpt(){
    HttpServer ts;
    auto prompt = QString("Расскажи мне про ежей");
    ts.sendPrompt(prompt);
}

void TestHttpServer::promptRequestBodyFilledCorrectly() {
//    HttpServer testServer;
//
//    auto prompt = QString("Как добраться до Пекина?");
//    testServer.sendPrompt(prompt);
//
//    auto etData = readFromFile("./prompt_body_after_first_request_etalon.json");

}


