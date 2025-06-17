#include<iostream>
using namespace std;

int main(){
    float waga;
    float wzrost;
    float bmi; 

    cout << "Podaj wage w kg: ";
    cin >> waga; 

    cout << "Podaj wzrost w metrach: ";
    cin >> wzrost;

    bmi = waga / (wzrost * wzrost); 

    cout << "Twoje BMI to: " << bmi << endl; 

    return 0; 
}
