using namespace std;
#include <iostream>
// Inserire qui sotto la dichiarazione della funzione shift

int* shift(int vector[], int dim, int n_shift);
void shift_rec(int vector[], int* vett, int dim, int n_shift, int index);

int main(){

    int J = 0;
    const int N = 15;
    int vector[] = {2, 17, 44, 202, 5, 13, 26, 7, 9, 131, 51, 79, 88, 96, 32};
    
    cout <<"Array iniziale: ";
    
    for(int i=0; i < N; i++) {
        cout<< vector[i] << " ";
    }
    
    cout << endl;
    cout << "Numero spostamenti a sinistra: ";
    cin >> J;
    
    int* new_vect = shift(vector, N, J);
    
    cout <<"Nuovo array: ";

    for(int i=0; i<N; i++) {
        cout<< new_vect[i] << " ";
    }
    
    cout <<endl;
    
    delete[] new_vect;
    
    return 0;

}

// Inserire qui sotto la definizione della funzione shift

int* shift(int vector[], int dim, int n_shift){

    int* vett = new int [dim];

    shift_rec(vector, vett, dim, n_shift,0);

    return vett;

}

void shift_rec(int vector[], int* vett, int dim, int n_shift, int index){

    if(index < dim){

        if(index >= n_shift){
            vett[index - n_shift] = vector[index];
        }
    
        index++;

        shift_rec(vector, vett, dim, n_shift,index);

    }
    else if(index < dim + n_shift) {
        vett[index - n_shift] = 0;

        index++;

        shift_rec(vector, vett, dim, n_shift,index);

    }

}