using namespace std;
#include <iostream>
#include "array.h"

void leggi(int array[], int& dim){

    cout << "Dimensione array : ";
    cin >> dim;
    cout << endl;

    for(int i{0}; i < dim; i++){
        cout << "v[" << i << "] = ";  
        cin >> array[i];
        cout << endl;
    }

}

void stampa(double* normalizzato, int dim){

    for(int i{0}; i < dim; i++){
        cout << "v[" << i << "] = " << normalizzato[i] << endl;
    }

    delete[] normalizzato;

}