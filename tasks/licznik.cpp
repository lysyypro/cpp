#include <iostream>
using namespace std;

class Licznik {
public:
    int wartosc;

    Licznik() {
        wartosc = 0;
    }

    void zwieksz() {
        wartosc++;
    }

    void zmniejsz() {
        wartosc--;
    }

    int pobierzWartosc() {
        return wartosc;
    }
};

int main() {
    Licznik l;

    l.zwieksz();
    l.zwieksz();
    l.zmniejsz();

    cout << "Aktualna wartość licznika: " << l.pobierzWartosc() << endl;

    return 0;
}
