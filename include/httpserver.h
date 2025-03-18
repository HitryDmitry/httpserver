#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include <QObject>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <iostream>


class QString;
class QUrl;

class HttpServer : public QObject {
    Q_OBJECT
public:
    explicit HttpServer(QObject* parent = nullptr);
    void sendPrompt(const QString& prompt);

signals:
    void responseReceived(const QString& response);

private:
    QString iamToken;
    QUrl modelUrl;
    QNetworkAccessManager* netManager;
    QJsonObject currentReplyToPromptJson;
};


#endif // HTTPSERVER_H
