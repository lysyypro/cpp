#include <iostream>
using namespace std;

class Punkt2D {
public:
    int x, y;

    Punkt2D(int _x, int _y) {
        x = _x;
        y = _y;
    }

    void wyswietl() {
        cout << "Punkt ma współrzędne: (" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Punkt2D p(3, 4);
    p.wyswietl();

    return 0;
}
