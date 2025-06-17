#include "AnalyzeFile.hpp"
#include <iostream>
#include <sstream>

// Liczy wszystkie słowa w pliku
int AnalyzedFile::countWords() {
    int wordCount = 0;
    for (const auto& line : _lines) {
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            wordCount++;
        }
    }
    return wordCount;
}

// Liczy ile razy występuje dane słowo
int AnalyzedFile::countOccurrences(const std::string &word) {
    int count = 0;
    for (const auto& line : _lines) {
        std::istringstream iss(line);
        std::string w;
        while (iss >> w) {
            if (w == word)
                count++;
        }
    }
    return count;
}

// Liczy ilość linii w pliku
int AnalyzedFile::countFileLines() {
    return _lines.size();
}

// Zamienia wszystkie litery na wielkie
void AnalyzedFile::toUpperCase() {
    for (auto& line : _lines) {
        std::transform(line.begin(), line.end(), line.begin(), ::toupper);
    }
}

// Zamienia wszystkie litery na małe
void AnalyzedFile::toLowerCase() {
    for (auto& line : _lines) {
        std::transform(line.begin(), line.end(), line.begin(), ::tolower);
    }
}

// Wyświetla podstawowe statystyki
void AnalyzedFile::showStats() {
    std::cout << "Lines: " << countFileLines() << std::endl;
    std::cout << "Words: " << countWords() << std::endl;
}

// Funkcja pomocnicza do rozdzielania stringa po znaku (split)
std::vector<std::string> AnalyzedFile::split(const std::string &str, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Druga wersja split (może ignorować puste tokeny)
std::vector<std::string> AnalyzedFile::split2(const std::string &str, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    for (char c : str) {
        if (c != delimiter)
            token += c;
        else if (!token.empty()) {
            tokens.push_back(token);
            token.clear();
        }
    }
    if (!token.empty())
        tokens.push_back(token);
    return tokens;
}
