#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> liczby;
    int x;

    cout << "Podawaj liczby (0 kończy):" << endl;
    while(true) {
        cin >> x;
        if(x == 0)
            break;
        liczby.push_back(x);
    }

    int suma = 0;
    for(int i = 0; i < liczby.size(); i++) {
        suma += liczby[i];
    }

    cout << "Suma liczb wynosi: " << suma << endl;

    return 0;
}
