#include "menu.h"

void menu()
{
    int userChoise;
    bool isMenu = true;
    std::string pause;

    std::string text;
    std::vector<std::string> words;

    std::cout << "����� ���������� � ��������� Alphabet\n\n";

    while (isMenu) {
        words.clear();

        std::cout << "1. ���������� � ���������\n";
        std::cout << "2. ����� ����� �� �����\n";
        std::cout << "3. ������ ����� �������\n";
        std::cout << "4. ���������� � ������\n";
        std::cout << "5. ����� �� ���������\n";
        std::cout << ">> ";
        std::cin >> userChoise;

        switch (userChoise) {
        case 1: {
            std::cout << "\n������ ��������� ������������� ��� ���������� ���� "
                         "������ � ���������� �������.\n"
                      << "����� ��� ���������� ����� ��������� � ���� Text.txt "
                         "� ����� res ��� ������ �������.\n"
                      << "�����, ����� ������ ���� ������� �� ���������� "
                         "�����.\n� ��������� ������ �� ����� ��������� "
                         "��������������� ������.\n\n";
            break;
        }
        case 2: {
            if (getText(text, TEXT)) {
                std::cout << "\n���� ������� ������.\n\n";
            } else {
                std::cout << "\n������\n\n";
                isMenu = false;
                std::cout << "������� Enter ����� ����������\n";
                std::cin.ignore();
                std::getline(std::cin, pause);
                break;
            }

            parse(text, words);
            textSort(words);

            std::cout << "��������� ����������:\n";
            for (auto it : words) {
                std::cout << it << "\n";
            }

            if (!writeResults(words, RESULT)) {
                std::cout << "\n������, ���� �� ������.\n\n";
                isMenu = false;
                std::cout << "������� Enter ����� ����������\n";
                std::cin.ignore();
                std::getline(std::cin, pause);
                break;
            } else {
                std::cout << "\n��������� ���������� ������� � ����.\n\n";
            }

            break;
        }
        case 3: {
            if (!getText(text)) {
                std::cout << "������\n\n";
                isMenu = false;
                std::cout << "������� Enter ����� ����������\n";
                std::getline(std::cin, pause);
                break;
            }

            parse(text, words);

            textSort(words);

            std::cout << "��������� ����������:\n";
            for (auto it : words) {
                std::cout << it << "\n";
            }

            if (!writeResults(words, RESULT)) {
                std::cout << "\n������, ���� �� ������.\n\n";
                isMenu = false;
                std::cout << "������� Enter ����� ����������\n";
                std::cin.ignore();
                std::getline(std::cin, pause);
                break;
            } else {
                std::cout << "\n��������� ���������� ������� � ����.\n\n";
            }

            break;
        }
        case 4: {
            std::cout
                    << "\n�������� ������ �� �������� \"���������� ���������� "
                       "������������ �����������\"\n";
            std::cout << "�������� ���������� �������\n\n";
            break;
        }
        case 5: {
            isMenu = false;
            std::cout << "������� Enter ����� ����������\n";
            std::cin.ignore();
            std::getline(std::cin, pause);
            break;
        }
        default: {
            std::cout << "\n������\n";
            break;
        }
        }
    }
}
