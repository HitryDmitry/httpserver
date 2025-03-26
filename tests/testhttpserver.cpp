#include "testhttpserver.h"
#include "jsonutils.h"

#include <QString>
#include <QByteArray>

TestHttpServer::TestHttpServer() : httpServer(std::make_unique<HttpServer>()) {}

TEST_F(TestHttpServer, SendPrompt_promptRequestBodyFilledCorrectly){

    auto prompt = QString("Как добраться до Пекина?");
    httpServer->sendPrompt(prompt);
    auto etData = JsonUtils::readJsonFile("./prompt_body_after_first_request_etalon.json");
}



