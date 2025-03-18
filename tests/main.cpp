#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include "httpserver.h"
#include <QFile>

QByteArray readFromFile(const QString& filename)
{
    QFile file(filename);
    if(!file.exists()) {
        throw std::runtime_error("No file with name " + filename.toStdString());
    }
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray arr = file.readAll();
    return arr;
}

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr) : QMainWindow(parent) {
        // Создаем центральный виджет
        QWidget* centralWidget = new QWidget(this);
        setCentralWidget(centralWidget);

        // Создаем вертикальный layout
        QVBoxLayout* layout = new QVBoxLayout(centralWidget);

        // Поле для ввода запроса
        QLineEdit* inputLineEdit = new QLineEdit(this);
        inputLineEdit->setPlaceholderText("Введите ваш запрос...");
        layout->addWidget(inputLineEdit);

        // Кнопка для отправки запроса
        QPushButton* sendButton = new QPushButton("Отправить", this);
        layout->addWidget(sendButton);

        // Поле для вывода результата
        QTextEdit* outputTextEdit = new QTextEdit(this);
        outputTextEdit->setReadOnly(true); // Запрещаем редактирование
        layout->addWidget(outputTextEdit);

        // Создаем объект HttpServer
        httpServer = new HttpServer(this);

        // Соединяем кнопку с методом отправки запроса
        connect(sendButton, &QPushButton::clicked, this, [this, inputLineEdit, outputTextEdit]() {
            QString prompt = inputLineEdit->text();
            if (!prompt.isEmpty()) {
                outputTextEdit->append("Отправка запроса: " + prompt);
                httpServer->sendPrompt(prompt);
            }
        });

        // Соединяем сигнал ответа от HttpServer с выводом в QTextEdit
        connect(httpServer, &HttpServer::responseReceived, this, [outputTextEdit](const QString& response) {
            outputTextEdit->append("Ответ: " + response);
        });
    }

private:
    HttpServer* httpServer;
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.setWindowTitle("HTTP Server Client");
    mainWindow.resize(400, 300);
    mainWindow.show();

    return app.exec();
}

#include "main.moc"