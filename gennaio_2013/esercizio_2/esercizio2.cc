#include <iostream>
#include <fstream>
#include "stampamatrice.h"

using namespace std;

const int NUMERO_RIGHE = 6;
const int NUMERO_COLONNE = 5;

void dealloca_matrice(int** selezione, int n_righe);
int** seleziona(int matrice[][NUMERO_COLONNE], int n_riga, int n_colonna, int n_righe, int n_colonne);

int main (){
    int matrice[][NUMERO_COLONNE] = {{1, 2, 3, 4, 5},
                                    {6, 7, 8, 9, 10},
                                    {11, 12, 13, 14, 15},
                                    {16, 17, 18, 19, 20},
                                    {21, 22, 23, 24, 25},
                                    {26, 27, 28, 29, 30}};

    int n_riga, n_colonna, n_righe, n_colonne;// Posizione del primo elemento della selezionec

    cout << "Posizione primo elemento della selezione; riga e colonna: ";
    cin >> n_riga >> n_colonna;// Dimensione della selezione
    cout << "Dimensione della selezione; righe e colonne: ";
    cin >> n_righe >> n_colonne;// Selezione della sotto-matrice

    int** selezione = seleziona(matrice, n_riga, n_colonna, n_righe, n_colonne);

    cout << "Matrice di output: " << endl;
    
    stampa_matrice(selezione, n_righe, n_colonne);
   
    dealloca_matrice(selezione, n_righe); // Deallocazione della matrice

    return 0;
    
}

int** seleziona(int matrice[][NUMERO_COLONNE], int n_riga, int n_colonna, int n_righe, int n_colonne){

    int** res = new int*[n_righe];

    for(int i{0}; i < n_righe; i++){
        res[i] = new int[n_colonne];
        for(int j{0}; j < n_colonne; j++){
            res[i][j] = matrice[n_riga+i][n_colonna+j];
        }
    }

    return res;

}

void dealloca_matrice(int** selezione, int n_righe){

    for(int i{0}; i < n_righe; i++){
        delete[] selezione[i];
    }

    delete selezione;

}