# HTTP Server Project

## Описание

Проект httpserver представляет собой HTTP-сервер, который взаимодействует с внешним API для обработки запросов. Сервер использует JSON-файлы для конфигурации и формирования тела запроса.

## Особенности

- Использует библиотеку Qt для работы с сетью и JSON.
- Для работы требуются два конфигурационных файла:
    - `config.json` — содержит настройки подключения к API.
    - `prompt_request_body.json` — шаблон тела запроса, который отправляется на сервер.

## Требования

- Qt 5 (или выше)
- Компилятор с поддержкой C++17
- CMake (версия 3.21 или выше)

## Сборка проекта

1. Клонируйте репозиторий:
```
   git clone git@github.com:HitryDmitry/httpserver.git
   cd repo_name
```
2. Создайте директорию для сборки:
```
   mkdir build
   cd build
```
3. Запустите CMake:
```
   cmake ..
```
4. Соберите проект:
```
   cmake --build .
```
После успешной сборки исполняемый файл будет находиться в директории build.

## Запуск проекта

1. Скопируйте конфигурационные файлы в директорию с исполняемым файлом:
```
   cp ../config.json .
   cp ../prompt_request_body.json .
```
2. Запустите тестовое приложение:
```
   ./testhttpserver
```
## Конфигурационные файлы

### config.json

Файл config.json должен содержать настройки для подключения к API. Пример содержимого:
```json
{
  "OAuthToken" : <token>,
  "getIamTokenUrl" : "https://iam.api.cloud.yandex.net/iam/v1/tokens",
  "modelUrl" : "https://llm.api.cloud.yandex.net/foundationModels/v1/completion"
}
```
### prompt_request_body.json

Файл prompt_request_body.json содержит шаблон тела запроса, который отправляется на сервер. Пример содержимого:

```json
{
  "modelUri": "gpt://b1gkbj5m380bv0hq7c0u/yandexgpt",
  "completionOptions": {
      "stream": false,
      "temperature": 0.6,
      "maxTokens": "2000"
  },
  "messages": [
      {
          "role": "system",
          "text": "Ты умный ассистент"
      }
  ]
}
```

## Структура проекта
```
project/
├── build/                  # Директория для сборки
├── source/                 # Исходные файлы
│   ├── main.cpp            # Основной файл программы
│   └── httpserver.cpp      # Реализация HTTP-сервера
├── include/                # Заголовочные файлы
│   ├── httpserver.h        # Заголовочный файл HTTP-сервера
│   └── jsonutils.h         # Файл с функциями для работы с json
├── tests/                  # Юнит-тесты
│   ├── main.cpp            # Оконное приложение для тестов
│   ├── testhttpserver.cpp  # Тесты для HTTP-сервера
│   └── testhttpserver.h    # Тесты для HTTP-сервера
├── config.json             # Конфигурационный файл (необходимо скопировать в build/)
├── prompt_request_body.json # Шаблон тела запроса (необходимо скопировать в build/)
└── CMakeLists.txt          # Файл для сборки с помощью CMake
```

---

### Примечания

- Убедитесь, что конфигурационные файлы (`config.json` и `prompt_request_body.json`) находятся в одной директории с исполняемым файлом после сборки.
- Если вы используете Docker или другую среду для развёртывания, добавьте копирование этих файлов в Dockerfile или скрипт развёртывания.