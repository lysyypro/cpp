#include "file.hpp"
#include "analyzefile.hpp"

int main()
{
    AnalyzedFile af("file_test.txt"); // Używamy klasy AnalyzedFile, która ma więcej funkcji

    af.readFile();    // Wczytanie zawartości z pliku
    af.showFile();    // Wyświetlenie pliku

    std::cout << "Liczba linii: " << af.countFileLines() << std::endl;
    std::cout << "Liczba słów: " << af.countWords() << std::endl;
    std::cout << "Liczba wystąpień słowa 'test': " << af.countOccurrences("test") << std::endl;

    std::cout << "\nPlik po zmianie na WIELKIE LITERY:\n";
    af.toUpperCase();
    af.showFile();

    std::cout << "\nPlik po zmianie na male litery:\n";
    af.toLowerCase();
    af.showFile();

    // Zapisanie zmian do pliku (opcjonalne)
    af.saveFile();

    return 0;
}
