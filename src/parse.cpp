#include "parse.h"

void parse(const std::string text, std::vector<std::string>& words)
{
    char* buffer = new char[text.length() + 1];
    strcpy(buffer, text.c_str());

    char delim[] = " ,.!?;:-\n";
    char* token = nullptr;

    token = strtok(buffer, delim);

    while (token != NULL) {
        if (token != NULL) {
            words.push_back(token);
            token = strtok(NULL, delim);
        }
    }

    delete[] buffer;
    delete token;
}
