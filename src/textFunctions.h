#ifndef TEXT_PROCESSING_H
#define TEXT_PROCESSING_H

#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool checkPath(const std::string path);

bool getText(std::string& text);
bool getText(std::string& text, const std::string path);

void textSort(std::vector<std::string>& words);

bool writeResults(const std::vector<std::string> words, const std::string path);

bool isEnglish(const std::string text);

#endif