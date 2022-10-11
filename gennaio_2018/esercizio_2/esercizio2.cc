#include <iostream>
using namespace std;

int somma_prodotto_incrociato(int a[], int b[], int dim);
int somma_prod_ric(int a[], int b[], int dim, int indice);

int main() {

    int primo[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int secondo[10] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};

    cout << "La somma dei prodotti incrociati dei due array e’ " << somma_prodotto_incrociato(primo, secondo, 10) << endl;

    return 0;

}

int somma_prodotto_incrociato(int a[], int b[], int dim){

    int somma{0};

    somma = somma_prod_ric(a,b,dim,0);

    return somma; 

}

int somma_prod_ric(int a[], int b[], int dim, int indice){

    int somma{0};

    if(indice < dim){

        somma = a[indice] * b[(dim - indice) - 1];
        indice++;

        somma = somma + somma_prod_ric(a,b,dim,indice);

    }

    return somma;

}