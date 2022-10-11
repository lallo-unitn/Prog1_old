using namespace std;
#include <iostream>

bool pal_rec(bool res, int array[], int dim, int index);

bool array_palindromo(int array[], int dim);

int main(){
    
    int dim;
    int array[100];

    do{
        cout << "Inserisci il numero (0 < ... < 100) di elementi da memorizzare nell' array" << endl;
        cin >> dim;
    }while(dim <= 0);

    if(dim > 100){
        cout << "Puoi inserire solo 100 elementi" << endl;
        dim = 100;
    }

    for(int i{0}; i < dim; i++){
        cout << "Inserire intero" << i+1 << " : ";
        cin >> array[i];
    }

    if(array_palindromo(array, dim)) 
        cout << "La sequenza inserita e' palindroma." << endl;
    else
        cout << "La sequenza inserita NON e' palindroma." << endl;

    return 0;

}

bool array_palindromo(int array[], int dim){

    bool res{true};

    if(!pal_rec(res,array,dim,0)) res = false;

    return res;

}

bool pal_rec(bool res, int array[], int dim, int index){

    if(res == true && index < (dim/2)){cout << "DEBUG" << endl;
        if(array[index] != array[(dim-1) - index]){
            cout << "DEBUG" << endl;
            res = false;
        }
        index++;
        res = pal_rec(res,array,dim,index);
    }

    return res;

}