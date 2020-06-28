#include "menu.h"

void menu()
{
    int userChoise;
    bool isMenu = true;
    std::string pause;

    std::string text;
    std::vector<std::string> words;

    std::cout << "Добро пожаловать в программу Alphabet\n\n";

    while (isMenu) {
        std::cout << "1. Информация о программе\n";
        std::cout << "2. Взять текст из файла\n";
        std::cout << "3. Ввести текст вручную\n";
        std::cout << "4. Информация о авторе\n";
        std::cout << "5. Выход из программы\n";
        std::cout << ">> ";
        std::cin >> userChoise;

        switch (userChoise) {
        case 1: {
            std::cout << "\nДанная программа предназначена для сортировки слов "
                         "текста в алфавитном порядке.\n"
                      << "Текст для сортировки можно поместить в файл Text.txt "
                         "в папке res или ввести вручную.\n"
                      << "Также, текст должен быть написан на английском "
                         "языке.\nВ противном случае на экран выведется "
                         "соответствующая ошибка.\n\n";
            break;
        }
        case 2: {
            break;
        }
        case 3: {
            std::cin.ignore();
            std::cout << "\nВведите текст:\n";
            std::getline(std::cin, text);
            std::cout << "\n";

            parse(text, words);

            break;
        }
        case 4: {
            std::cout
                    << "\nКурсовой проект по предмету \"Технологии разработки "
                       "программного обеспечения\"\n";
            std::cout << "Выполнен Екатериной Ильиных\n\n";
            break;
        }
        case 5: {
            isMenu = false;
            std::cout << "Нажмите Enter чтобы продолжить\n";
            std::cin.ignore();
            std::getline(std::cin, pause);
            break;
        }
        default: {
            std::cout << "\nОшибка\n";
            break;
        }
        }
    }
}
