using namespace std;
#include <iostream>

int* crea_vettore(const int N);
void crea_vett_rec(const int N,int vett[], int index);

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
    
    for(int i=0; i < N; i++) {
        cout << vector[i] << " ";
    }
            
    cout << endl;
    delete[] vector;
    return 0;
    
}

int* crea_vettore(const int N){

    int* vett;
    vett = new int[N];
    crea_vett_rec(N,vett,0);
    return vett;

}

void crea_vett_rec(const int N,int vett[], int index){

    if(index < N){
        vett[index] = index * index;
        index++;
        crea_vett_rec(N,vett,index);
    };

}