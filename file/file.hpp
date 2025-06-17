#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class File
{
protected:
    std::string _fileName;            // nazwa pliku
    std::vector<std::string> _lines;  // zawartość pliku (linie)

public:
    // Konstruktor z parametrem jako const ref (wydajniej)
    File(const std::string& argFileName) : _fileName(argFileName) {}

    // Wirtualny destruktor dla poprawnego dziedziczenia
    virtual ~File() = default;

    // Zapisuje _lines do pliku
    void saveFile();

    // Odczytuje plik do _lines
    void readFile();

    // Wyświetla zawartość _lines na ekranie
    void showFile();
};

#endif // FILE_HPP
