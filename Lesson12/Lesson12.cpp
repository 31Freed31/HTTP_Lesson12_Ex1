#include <iostream>
#include <cpr/cpr.h>

void handleGet() {
    auto response = cpr::Get(cpr::Url{ "http://httpbin.org/get" });
    std::cout << response.text << std::endl;
}

void handlePost() {
    auto response = cpr::Post(cpr::Url{ "http://httpbin.org/post" }, cpr::Body{ "key=value" });
    std::cout << response.text << std::endl;
}

void handlePut() {
    auto response = cpr::Put(cpr::Url{ "http://httpbin.org/put" }, cpr::Body{ "key=value" });
    std::cout << response.text << std::endl;
}

void handleDelete() {
    auto response = cpr::Delete(cpr::Url{ "http://httpbin.org/delete" });
    std::cout << response.text << std::endl;
}

void handlePatch() {
    auto response = cpr::Patch(cpr::Url{ "http://httpbin.org/patch" }, cpr::Body{ "key=value" });
    std::cout << response.text << std::endl;
}

int main() {
    setlocale(LC_CTYPE, "rus");
    std::string command;

    while (true) {
        std::cout << "Введите команду (get, post, put, delete, patch, exit): ";
        std::cin >> command;

        if (command == "get") {
            handleGet();
        }
        else if (command == "post") {
            handlePost();
        }
        else if (command == "put") {
            handlePut();
        }
        else if (command == "delete") {
            handleDelete();
        }
        else if (command == "patch") {
            handlePatch();
        }
        else if (command == "exit") {
            std::cout << "Завершение программы." << std::endl;
            break;
        }
        else {
            std::cout << "Неверная команда. Попробуйте снова." << std::endl;
        }
    }

    return 0;
}
