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
        words.clear();

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
            if (getText(text, TEXT)) {
                std::cout << "\nФайл успешно открыт.\n\n";
            } else {
                std::cout << "\nОшибка\n\n";
                isMenu = false;
                std::cout << "Нажмите Enter чтобы продолжить\n";
                std::cin.ignore();
                std::getline(std::cin, pause);
                break;
            }

            parse(text, words);
            textSort(words);

            std::cout << "Результат сортировки:\n";
            for (auto it : words) {
                std::cout << it << "\n";
            }

            if (!writeResults(words, RESULT)) {
                std::cout << "\nОшибка, файл не открыт.\n\n";
                isMenu = false;
                std::cout << "Нажмите Enter чтобы продолжить\n";
                std::cin.ignore();
                std::getline(std::cin, pause);
                break;
            } else {
                std::cout << "\nРезультат сортировки записан в файл.\n\n";
            }

            break;
        }
        case 3: {
            if (!getText(text)) {
                std::cout << "Ошибка\n\n";
                isMenu = false;
                std::cout << "Нажмите Enter чтобы продолжить\n";
                std::getline(std::cin, pause);
                break;
            }

            parse(text, words);

            textSort(words);

            std::cout << "Результат сортировки:\n";
            for (auto it : words) {
                std::cout << it << "\n";
            }

            if (!writeResults(words, RESULT)) {
                std::cout << "\nОшибка, файл не открыт.\n\n";
                isMenu = false;
                std::cout << "Нажмите Enter чтобы продолжить\n";
                std::cin.ignore();
                std::getline(std::cin, pause);
                break;
            } else {
                std::cout << "\nРезультат сортировки записан в файл.\n\n";
            }

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
