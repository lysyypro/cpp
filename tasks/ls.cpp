#include <iostream>
#include <vector>
using namespace std;

class Student {
public:
    string imie;
    int wiek;

    Student(string i, int w) {
        imie = i;
        wiek = w;
    }

    void wyswietl() const {
        cout << "Imie: " << imie << ", Wiek: " << wiek << endl;
    }
};

int main() {
    vector<Student> studenci;

    studenci.push_back(Student("Anna", 20));
    studenci.push_back(Student("Kamil", 22));
    studenci.push_back(Student("Ola", 19));

    for(const auto& s : studenci) {
        s.wyswietl();
    }

    return 0;
}
