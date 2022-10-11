using namespace std;
#include <iostream>
#include <iomanip>
#include "stampamatrice.h"

void stampa_matrice(int** selezione, int n_righe, int n_colonne){

    for(int i{0}; i < n_righe; i++){
        for (int j{0};j < n_colonne;j++){
            cout << setw(4) << selezione[i][j];
        }
        cout << endl;
    }
}