using namespace std;
#include <iostream>

const int DIM{81};

char* estrai(char stringa[]);
char* estrai_rec(char*res, char stringa[], int index1, int index2);

int main(){
    char stringa[DIM];
    char* estratta;
    char risposta{'n'};

    do{

        cout << "Inserisci la stringa da controllare :";
        cin >> stringa;

        estratta = estrai(stringa);

        cout << "La stringa estratta è :";
        cout << estratta;
        cout << endl;
        cout << "Vuoi inserire un' altra stringa? [s/n]";
        cin >> risposta;

    }while(risposta != 'n');

    return 0;

}

char* estrai(char stringa[]){

    char* res = new char[DIM];

    estrai_rec(res,stringa,0,0);

    return res;

}

char* estrai_rec(char*res, char stringa[], int index1, int index2){

    if(stringa[index1] != '\0'){
        if(stringa[index1] >= 'A' && stringa[index1] <= 'Z'){
            res[index2] = stringa[index1];
            index2++;
        }
        index1++;
        res = estrai_rec(res,stringa,index1,index2);
    }

    return res;

}