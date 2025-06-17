#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, x;
    vector<int> liczby;

    cout << "Ile liczb chcesz podać? ";
    cin >> n;

    cout << "Podaj " << n << " liczb:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> x;
        liczby.push_back(x);
    }

    cout << "Liczby w odwrotnej kolejności:" << endl;
    for(int i = n - 1; i >= 0; i--) {
        cout << liczby[i] << " ";
    }
    cout << endl;

    return 0;
}
