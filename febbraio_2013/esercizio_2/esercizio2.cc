#include <iostream>
#include <cmath>
using namespace std;

double fatt(double x);
double pot_rec(double x, int n, int index);
double pot(double x, int n);
double my_sin_rec(double res, double x, int n, int index);
double my_sin(double x, int n);

int main(){
    double x, esp;
    int n;

    cout << "Inserisci il valore di x in cui vuoi calcolare sin(x) :  \n";
    cin >> x;
    cout << "Inserisci il numero di termini dell' appreossimazione : \n";
    cin >> n;
    cout << "L' approssimazione di sin(x) è : " << my_sin(x,n) << endl;
    cout << "Per confronto, il valore di sin(x) è : " << sin(x) << endl;
    
    return 0;

}

double fatt(double x){

    if(x > 0){
        x = x * fatt(x - 1);
    }
    else if(x == 0){
        x = 1;
    }

    return x;

}

double pot(double x, int n){

    double res{0};
    res = pot_rec(x,n,0);

    return res;

}

double pot_rec(double x, int n, int index){

    if(x == 0) x = 0;
    else if(x == 1 || n == 0) x = 1;
    else{

        if(index < n-1){
            index++;
            x = x * pot_rec(x,n,index);
        }
    }

    return x;

}

double my_sin(double x, int n){

    double res{0};

    res = my_sin_rec(res,x,n,0);

    return res;

}

double my_sin_rec(double res, double x, int n, int index){

    if(index <= n){

        res = res + ((pot(-1,index)/(fatt((2*index)+1))) * pot(x,((2*index)+1)));
        index++;
        res = my_sin_rec(res,x,n,index);

    }

    return res;

}