#include <iostream>
#include <cmath> 
#include "array.h"     /* leggi, stampa, MAX_DIM */

using namespace std;
// Inserire qui sotto le DICHIARAZIONI delle funzioni

double* normalizza(int array[], int dim);
void normalizza_rec(int array[], double* res, double norma, int dim, int index);
double calcola_norma_ricorsivo(int array[],int dim);
double calcola_norma(int array[],double res, int dim, int index);

int main() {
    
    int array[MAX_DIM];
    int dim;
    
    leggi(array, dim);
    
    double* normalizzato = normalizza(array, dim);
    cout << "Array normalizzato: " << endl;
    
    stampa(normalizzato, dim);
    
    return 0;
    
}

double* normalizza(int array[], int dim){

    double* res = new double[dim];
    double norma;
    norma = calcola_norma_ricorsivo(array,dim);
    normalizza_rec(array,res,norma,dim,0);
    return res;

}

double calcola_norma_ricorsivo(int array[],int dim){

    double res{0};
    res = calcola_norma(array,res,dim,0);
    cout << res << endl;
    return res;

}

double calcola_norma(int array[],double res, int dim, int index){

    if(index < dim){
        res = res + (array[index] * array[index]);
        index++;
        res = calcola_norma(array,res,dim,index);
    }

    else{
        res = sqrt(res);
    }

    return res;

}

void normalizza_rec(int array[], double* res, double norma, int dim, int index){
        
    if(index < dim){
        
        if(norma != 0){
            res[index] = array[index] / norma;
        }
        else{
            res[index] = array[index];
        }
        index++;
        normalizza_rec(array,res,norma,dim,index);

    }

}