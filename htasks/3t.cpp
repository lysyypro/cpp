#include <iostream>
#include <vector>

class SalaKina {
private:
    std::vector<std::vector<char>> miejsca;
    int liczbaRzedow;
    int liczbaMiejscWRzedzie;
    float sumaSprzedazy;

public:
    SalaKina(int rzedow = 10, int miejsc = 15) {
        liczbaRzedow = rzedow;
        liczbaMiejscWRzedzie = miejsc;
        sumaSprzedazy = 0.0;
        miejsca.resize(liczbaRzedow, std::vector<char>(liczbaMiejscWRzedzie, 'O'));
    }

    bool zarezerwujMiejsce(int rzad, int miejsce) {
        if (rzad < 0 || rzad >= liczbaRzedow || miejsce < 0 || miejsce >= liczbaMiejscWRzedzie) {
            std::cout << "Niepoprawne miejsce." << std::endl;
            return false;
        }
        if (miejsca[rzad][miejsce] == 'X') {
            std::cout << "Miejsce zajete!" << std::endl;
            return false;
        }
        miejsca[rzad][miejsce] = 'X';
        float cena = obliczCene(rzad);
        sumaSprzedazy += cena;
        std::cout << "Zarezerwowano. Cena: " << cena << " zl" << std::endl;
        return true;
    }

    void pokazMiejsca() {
        for (int i = 0; i < liczbaRzedow; i++) {
            for (int j = 0; j < liczbaMiejscWRzedzie; j++) {
                std::cout << miejsca[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }

    float obliczCene(int rzad) {
        if (rzad >= 3 && rzad <= 6) return 25.0;
        else return 20.0;
    }

    void podsumowanieSprzedazy() {
        std::cout << "Suma sprzedazy: " << sumaSprzedazy << " zl" << std::endl;
    }
};

int main() {
    SalaKina kino;
    kino.pokazMiejsca();
    kino.zarezerwujMiejsce(4, 7);
    kino.zarezerwujMiejsce(0, 0);
    kino.zarezerwujMiejsce(9, 14);
    kino.pokazMiejsca();
    kino.podsumowanieSprzedazy();
    return 0;
}
