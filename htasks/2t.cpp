#include <iostream>
#include <vector>
#include <string>

class KontoBankowe {
private:
    int numerKonta;
    std::string imieWlasciciela;
    float saldo;
    std::vector<std::string> historia;

    static int liczbaKont;

public:
    KontoBankowe(std::string imie, float poczatkoweSaldo) {
        imieWlasciciela = imie;
        saldo = poczatkoweSaldo;
        numerKonta = ++liczbaKont;

        historia.push_back("Konto utworzone z saldem: " + std::to_string(saldo));
    }

    void wplata(float kwota) {
        saldo += kwota;
        historia.push_back("Wplata: +" + std::to_string(kwota));
    }

    void wyplata(float kwota) {
        if (kwota <= saldo) {
            saldo -= kwota;
            historia.push_back("Wyplata: -" + std::to_string(kwota));
        } else {
            historia.push_back("Nieudana wyplata: brak srodkow");
        }
    }

    void pokazHistorie() {
        std::cout << "Historia konta nr " << numerKonta << " (" << imieWlasciciela << "):" << std::endl;
        for(const std::string &zdarzenie : historia) {
            std::cout << zdarzenie << std::endl;
        }
    }

    int getNumerKonta() const {
        return numerKonta;
    }

    std::string getImieWlasciciela() const {
        return imieWlasciciela;
    }

    float getSaldo() const {
        return saldo;
    }

    void odbierzPrzelew(float kwota) {
        saldo += kwota;
        historia.push_back("Otrzymano przelew: +" + std::to_string(kwota));
    }

    void wykonajPrzelew(float kwota, KontoBankowe &odbiorca) {
        if(kwota <= saldo) {
            saldo -= kwota;
            historia.push_back("Przelew wyslany: -" + std::to_string(kwota) + " do konta nr " + std::to_string(odbiorca.getNumerKonta()));
            odbiorca.odbierzPrzelew(kwota);
        } else {
            historia.push_back("Nieudany przelew: brak srodkow");
        }
    }

    static int getLiczbaKont() {
        return liczbaKont;
    }
};

int KontoBankowe::liczbaKont = 0;

class Bank {
private:
    std::vector<KontoBankowe> konta;

public:
    void dodajKonto(std::string imie, float saldoStart) {
        KontoBankowe noweKonto(imie, saldoStart);
        konta.push_back(noweKonto);
    }

    void pokazKonta() {
        for(KontoBankowe &konto : konta) {
            std::cout << "Konto nr " << konto.getNumerKonta()
                      << ", Wlasciciel: " << konto.getImieWlasciciela()
                      << ", Saldo: " << konto.getSaldo() << std::endl;
        }
    }

    KontoBankowe* znajdzKonto(int numer) {
        for(KontoBankowe &konto : konta) {
            if(konto.getNumerKonta() == numer) {
                return &konto;
            }
        }
        return nullptr; 
    }

    void przelew(int od, int doKogo, float kwota) {
        KontoBankowe* kontoOd = znajdzKonto(od);
        KontoBankowe* kontoDo = znajdzKonto(doKogo);

        if(kontoOd != nullptr && kontoDo != nullptr) {
            kontoOd->wykonajPrzelew(kwota, *kontoDo);
        } else {
            std::cout << "Przelew nieudany: nie znaleziono kont." << std::endl;
        }
    }
};

int main() {
    Bank bank;

    bank.dodajKonto("Ala", 1000.0);
    bank.dodajKonto("Ola", 500.0);

    KontoBankowe* kontoAla = bank.znajdzKonto(1);
    KontoBankowe* kontoOla = bank.znajdzKonto(2);

    if(kontoAla != nullptr) {
        kontoAla->wplata(200.0);
        kontoAla->wyplata(150.0);
    }

    if(kontoOla != nullptr) {
        kontoOla->wplata(300.0);
    }

    bank.przelew(1, 2, 250.0);

    if(kontoAla != nullptr) kontoAla->pokazHistorie();
    if(kontoOla != nullptr) kontoOla->pokazHistorie();

    std::cout << "\nLista wszystkich kont w banku:" << std::endl;
    bank.pokazKonta();

    std::cout << "\nLiczba zalozonych kont: " << KontoBankowe::getLiczbaKont() << std::endl;

    return 0;
}
