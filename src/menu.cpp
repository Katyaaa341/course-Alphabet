#include "menu.h"

void menu()
{
    int userChoise;
    bool isMenu = true;
    std::string pause;

    std::cout << "����� ���������� � ��������� Alphabet\n\n";

    while (isMenu) {
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
            break;
        }
        case 3: {
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
