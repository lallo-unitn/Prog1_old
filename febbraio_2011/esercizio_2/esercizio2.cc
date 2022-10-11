#include <iostream>
using namespace std;

#define SIZE 20

void inizializza_array(int testo[], int& n);
bool pattern_matcher(int testo[], int n, int pattern[], int m);

int main(){

    int testo[SIZE];
    int pattern[SIZE];
    int n, m;

    cout << "Creazione del testo ( <= " << SIZE << ")" << endl;
    inizializza_array(testo, n);

    cout << "Creazione del pattern ( <= " << SIZE << ")" << endl;
    inizializza_array(pattern, m);

    if(m > n){
        cout << "Pattern piu' lungo del testo!" << endl;
        return 0;
    }

    bool res = pattern_matcher(testo, n, pattern, m);

    if(res){
        cout << "Il pattern occorre nel testo!";
    }
    else{
        cout << "Il pattern NON occorre nel testo!";
    }

    cout << endl;

    return 0;

}

void inizializza_array(int testo[], int& n){
    cout << "Inserisci la lunghezza dell' array" << endl;
    cin >> n;
    for(int i{0}; i < n; i++){
        cout << "Posizione " << i+1 << " : ";
        cin >> testo[i];
        cout << endl;
    }
}

bool pattern_matcher(int testo[], int n, int pattern[], int m){

    bool match{false};
    int count{0};

        for(int j{0}; j < n && count != m; j++){
            if(pattern[count] == testo[j]){
                count++;
            }
            else if(pattern[count] != testo[j] && count != 0){
                j--;
                count = 0;
            }
        }

    if(count == m)match = true;

    return match;

}