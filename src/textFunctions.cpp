#include "textFunctions.h"

bool checkPath(const std::string path)
{
    std::ifstream file(path);

    if (file.is_open()) {
        file.close();
        return true;
    }
    file.close();
    return false;
}

bool getText(std::string& text)
{
    std::cin.ignore();
    std::cout << "\n¬ведите текст:\n";
    std::getline(std::cin, text);
    std::cout << "\n";

    if (!isEnglish(text)) {
        return false;
    }

    return true;
}

bool getText(std::string& text, const std::string path)
{
    if (!checkPath(path)) {
        return false;
    }

    std::ifstream readFile(path, std::ios_base::beg);
    getline(readFile, text, '\0');

    readFile.close();

    if (!isEnglish(text)) {
        return false;
    }

    return true;
}

void textSort(std::vector<std::string>& words)
{
    auto cmp = [](const std::string& a, const std::string& b) {
        return _strcmpi(a.c_str(), b.c_str()) < 0;
    };

    std::stable_sort(words.begin(), words.end(), cmp);
}

bool writeResults(const std::vector<std::string> words, const std::string path)
{
    if (!checkPath(path)) {
        return false;
    }

    std::ofstream writeFile(path, std::ios_base::trunc);

    for (auto it : words) {
        writeFile << it << "\n";
    }

    return true;
}

bool isEnglish(const std::string text)
{
    int textSize = text.length() + 1;
    char* buffer = new char[textSize];
    strcpy(buffer, text.c_str());

    for (int i = 0; i < text.length() + 1; i++) {
        if (!isascii(buffer[i])) {
            return false;
        }
    }

    delete[] buffer;
    return true;
}
