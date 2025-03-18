#include "httpserver.h"
#include <QApplication>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    HttpServer server;
    return app.exec();
}