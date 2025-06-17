#include <iostream>
using namespace std;

bool czyParzysta(int liczba) {
    return liczba % 2 == 0;
}

int main() {
    int x;
    cout << "Podaj liczbę: ";
    cin >> x;

    if(czyParzysta(x))
        cout << "Liczba jest parzysta." << endl;
    else
        cout << "Liczba jest nieparzysta." << endl;

    return 0;
}
