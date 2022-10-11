using namespace std;
#include <iostream>

const int DIM = 81;

// Dichiarare qui sotto la funzione estrai

char* estrai(char stringa[]);
void estrai_rec(char stringa[],char res[], int index, int index2);
bool is_up(char c);

int main () {
    char stringa[DIM], *estratta, risposta;
    
    do {
        cout << "Inserisci la stringa da controllare: ";
        cin >> stringa;
        
        estratta = estrai(stringa);
        
        cout << "La stringa estratta e’: " << estratta << endl;
        cout << "Vuoi inserire un’altra stringa? [s/n] ";
        cin >> risposta;
    } while (risposta != 'n' && risposta != 'N');
        
return 0;

}

char* estrai(char stringa[]){

    char* res = new char [DIM];

    estrai_rec(stringa, res, 0, 0);

    return res;

}

void estrai_rec(char stringa[], char res[], int index, int index2){

    if(stringa[index] != '\0'){
        if(is_up(stringa[index])){
            res[index2] = stringa[index];
            index2++;
        }
        index++;
        estrai_rec(stringa, res, index, index2);
    }

}

bool is_up(char c){

    bool res{false};

    if(c >= 'A' && c<= 'Z'){
        res = true;
    }

    return res;

}