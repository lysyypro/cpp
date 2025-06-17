#include <iostream>
using namespace std;

int silnia(int n) {
    if(n <= 1)
        return 1;
    else
        return n * silnia(n - 1);
}

int main() {
    int x;
    cout << "Podaj liczbę: ";
    cin >> x;

    cout << "Silnia z " << x << " wynosi: " << silnia(x) << endl;

    return 0;
}
