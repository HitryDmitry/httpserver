#ifndef TEST_HTTP_SERVER_H
#define TEST_HTTP_SERVER_H

#include "httpserver.h"

#include <QTest>
#include <QDebug>
#include <QCoreApplication>
#include <memory>
#include <gtest/gtest.h>

class QJsonObject;

class TestHttpServer : public testing::Test
{
public:
    TestHttpServer();
    std::unique_ptr<HttpServer> httpServer;
};

#endif // TEST_HTTP_SERVER_H