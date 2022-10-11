using namespace std;
#include <iostream>
#include <cstdlib>
#include <ctime>

void gioca(int& num_lanci, int& somma_max);
void gioca_rec(int& num_lanci, int& somma_max, int& dado1,int& dado2);

int main(){

    srand(time(NULL));
    int num_lanci, somma_max;
    gioca(num_lanci, somma_max);

    cout    << "Il programma è terminato al lancio numero "
            << num_lanci << " con un puntaggio massimo di "
            << somma_max << endl;

    return 0;

}

void gioca(int& num_lanci, int& somma_max){

    num_lanci = 0;
    somma_max = 0;
    int dado1{0};
    int dado2{0};
    gioca_rec(num_lanci,somma_max,dado1,dado2);

}

void gioca_rec(int& num_lanci, int& somma_max, int& dado1,int& dado2){

    if(somma_max < 12 && num_lanci < 5){
        dado1 = ((rand() % 6) + 1);
        dado2 = ((rand() % 6) + 1);
        if((dado1 + dado2) > somma_max) somma_max = dado1+dado2;
        num_lanci++;
        gioca_rec(num_lanci,somma_max,dado1,dado2);
    }

}