#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class Statystyka {
private:
    std::vector<float> dane;

    float policzsrednia(const std::vector<float>& vec) {
        float suma = 0.0;
        for(const float &wartosc : vec){
            suma += wartosc;
        }
        return vec.empty() ? 0 : suma / vec.size();
    }

public:
    Statystyka() {}

    void dodajelement(float wartosc){
        dane.push_back(wartosc);
    }

    void wypiszelementy(){
        for(const float &s : dane){
            std::cout << s << std::endl;
        }
    }

    float srednia(){
        return policzsrednia(dane);
    }

    float odchyleniestandardowe(){
        if(dane.size() < 2) return 0;

        float sr = srednia();
        float suma = 0.0;
        for(const float &wartosc : dane){
            suma += pow(wartosc - sr, 2);
        }
        return sqrt(suma / (dane.size() - 1));
    }

    float mediana(){
        if(dane.empty()) return 0;

        std::vector<float> temp = dane;
        std::sort(temp.begin(), temp.end());

        int n = temp.size();
        if(n % 2 == 0){
            return (temp[n/2 - 1] + temp[n/2]) / 2.0;
        } else {
            return temp[n/2];
        }
    }

    void filtrujOutliers(float progOdchylen){
        float sr = srednia();
        float odchylenie = odchyleniestandardowe();
        std::vector<float> noweDane;

        for(const float &wartosc : dane){
            if(std::abs(wartosc - sr) <= progOdchylen * odchylenie){
                noweDane.push_back(wartosc);
            }
        }
        dane = noweDane;
    }
};

int main(){
    Statystyka s1;
    int liczbaElementow;

    std::cout << "Ile wartosci chcesz wprowadzic? ";
    std::cin >> liczbaElementow;

    std::cout << "Podaj " << liczbaElementow << " wartosci (float):" << std::endl;
    for(int i = 0; i < liczbaElementow; i++){
        float wartosc;
        std::cin >> wartosc;
        s1.dodajelement(wartosc);
    }

    std::cout << "\nElementy:" << std::endl;
    s1.wypiszelementy();

    std::cout << "Srednia: " << s1.srednia() << std::endl;
    std::cout << "Odchylenie standardowe: " << s1.odchyleniestandardowe() << std::endl;
    std::cout << "Mediana: " << s1.mediana() << std::endl;

    s1.filtrujOutliers(2.0); 
    std::cout << "\nPo odrzuceniu outliers:" << std::endl;
    s1.wypiszelementy();

    return 0;
}
