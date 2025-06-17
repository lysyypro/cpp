#include "analyzefile.hpp"
#include <sstream>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <fstream>

int AnalyzedFile::countWords()
{
    if (_lines.empty())
        return 0;

    int wordCount = 0;
    for (const std::string& line : _lines)
    {
        std::istringstream iss(line);
        std::string word;
        while (iss >> word)
        {
            wordCount++;
        }
    }

    return wordCount;
}

int AnalyzedFile::countOccurrences(const std::string &word)
{
    if (_lines.empty() || word.empty())
        return 0;

    int count = 0;
    for (const auto &line : _lines)
    {
        std::istringstream iss(line);
        std::string w;
        while (iss >> w)
        {
            if (w == word)
                ++count;
        }
    }
    return count;
}

int AnalyzedFile::countFileLines()
{
    return _lines.size();
}

void AnalyzedFile::toUpperCase()
{
    for (auto &line : _lines)
    {
        std::transform(line.begin(), line.end(), line.begin(), ::toupper);
    }
}

void AnalyzedFile::toLowerCase()
{
    for (auto &line : _lines)
    {
        std::transform(line.begin(), line.end(), line.begin(), ::tolower);
    }
}

void AnalyzedFile::showStats()
{
    std::cout << "Liczba wierszy: " << countFileLines() << std::endl;
    std::cout << "Liczba slow: " << countWords() << std::endl;

    // Liczba bajtów pliku
    std::ifstream file(_fileName, std::ios::binary | std::ios::ate);
    if (file.is_open())
    {
        std::streamsize size = file.tellg();
        std::cout << "Rozmiar pliku: " << size << " bajtow" << std::endl;
    }
    else
    {
        std::cout << "Nie mozna otworzyc pliku do odczytu rozmiaru." << std::endl;
    }
}

std::vector<std::string> AnalyzedFile::split(const std::string &str, char delimiter)
{
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;

    while (std::getline(ss, token, delimiter))
    {
        tokens.push_back(token);
    }

    return tokens;
}

std::vector<std::string> AnalyzedFile::split2(const std::string &str, char delimiter)
{
    std::vector<std::string> result;
    size_t start = 0;
    size_t end = 0;

    while ((end = str.find(delimiter, start)) != std::string::npos)
    {
        result.emplace_back(str.substr(start, end - start));
        start = end + 1;
    }

    result.emplace_back(str.substr(start));
    return result;
}
