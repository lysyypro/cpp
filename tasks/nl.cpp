#include <iostream>
using namespace std;

int main() {
    int liczby[] = {4, 2, 9, 1, 7};
    int max = liczby[0];

    for(int i = 1; i < 5; i++) {
        if(liczby[i] > max) {
            max = liczby[i];
        }
    }

    cout << "Największa liczba to: " << max << endl;

    return 0;
}
