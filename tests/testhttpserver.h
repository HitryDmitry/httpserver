#ifndef TEST_HTTP_SERVER_H
#define TEST_HTTP_SERVER_H

#include <QTest>
#include <QDebug>
#include <QCoreApplication>
#include "httpserver.h"

class QJsonObject;

class TestHttpServer : public QObject
{
    Q_OBJECT
public:
    explicit TestHttpServer(QObject *parent = 0);

private slots:
    void setUpHttpServer();
    void sendPromptToYaGpt();
    void promptRequestBodyFilledCorrectly();
};

#endif // TEST_HTTP_SERVER_H