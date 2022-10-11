using namespace std;
#include <iostream>
#include <iomanip>

double calcola (double x, int n, double epsilon);
double pot(double base, int esp);
double ass(double diff);

int main () {
    
    double epsilon, x;
    int n;
    cout << "Inserisci il numero di termini dell’approssimazione: ";
    cin >> n;
    cout << "Inserisci l’errore massimo epsilon: ";
    cin >> epsilon;
    char c;
    
    do {
        cout << "Inserisci il valore x in cui vuoi calcolare f(x) = 1 / (1 - x) ^ 2: ";
        cin >> x;
        
        while(x >= 1 || x <= -1) {
            cout << "Valore errato, prego reintrodurre (-1 < x < 1):";
            cin >> x;
        }
        cout << "L’approssimazione di f(x) e’: ";
        cout << setprecision(10) << calcola(x, n, epsilon);
        cout << endl;
        cout << "Continuare (s/n)? ";
        cin >> c;
        cout << pot(4,4);
    } while(c != 'n' && c != 'N');
    
    return(0);
    
}

double calcola (double x, int n, double epsilon){

    double somma{0};
    double prec{0};
    int i{0};
    do{
        prec = somma;
        i++;
        somma = prec + i*(pot(x, i-1));
    }while(i < n && (ass(somma - prec) >= epsilon));

    return somma;

}

double ass(double diff){

    if(diff < 0) diff = diff*(-1);

    return diff;

}

double pot(double base, int esp){
    
    double res{1};

    if(esp == 0) base = 1;

    else{
        for(int i{0}; i < esp; i++){
            res = res*base;
        }
    }
    return res;

}