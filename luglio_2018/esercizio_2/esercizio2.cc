using namespace std;
#include <iostream>

int* crea_vettore(int n);
void crea_vett_rec(int res[], int n, int index);

int main(){
    int N;
    cout << "Dimensione: ";
    cin >> N;
    if (N < 0) {
        cout << "Attenzione: inserire intero positivo!\n";
        return 1;
    }
    int* vector = crea_vettore(N);
    cout << "Array creato: ";
    for(int i=0; i<N; i++) {
        cout << vector[i] << " ";
    }
    cout << endl;

    delete[] vector;

    return 0;
    
}

int* crea_vettore(int n){

    int* res = new int[n];

    crea_vett_rec(res,n,0);

    return res;

}

void crea_vett_rec(int res[], int n, int index){

    if(index < n){
        res[index] = index * index;
        index++;
        crea_vett_rec(res,n,index);
    }

}