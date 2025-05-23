Praca klasowa 16.05

#include <iostream>

int main() {
    const int size = 7;
    int i;
    int j;
    int tablica[7][7];
    
    for (i=0; i < size; i++){
        for(j=0; j < size; j++){
            if (i == j){
                tablica[i][j] = 1;}
            else {
                tablica[i][j] = 0;}
    }}
    
    for (i=0; i < size; i++){
        for(j=0; j < size; j++){
            if (i + j == 6){
                tablica[i][j] = 1;}
        }}
     for (i=0; i < size; i++){
        for(j=0; j < size; j++){
            std::cout << tablica[i][j] << " ";
     }
         std::cout << std::endl;}
    return 0;
}
