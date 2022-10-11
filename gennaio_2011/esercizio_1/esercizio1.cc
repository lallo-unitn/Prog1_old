using namespace std;
#include <iostream>
#include <fstream>
#include <cstring>

void leggiECalcolaMedia(char nome_file[], float& media);

int main(){

    char nomeFile[] = "input1.txt";
    float result = 0;

    leggiECalcolaMedia(nomeFile, result);

    cout << "La media calcolata in " << nomeFile << " e' " << result << endl;

    return 0;

}

void leggiECalcolaMedia(char nome_file[], float& media){

    fstream myin, myapp;
    char c;
    int count{0};
    int somma{0};
    int n_stringhe{0};

    myin.open(nome_file, ios::in);
    myapp.open(nome_file, ios::app);

    while(!myin.eof()){

        while(myin.get(c)){
            if(c == '*') count++;
            else{
                somma = somma + count;
                cout << somma << endl;
                n_stringhe++;
                cout << n_stringhe << endl;
                count = 0;
            }
        }
    }

    if(n_stringhe != 0){

        media = (float)somma / float(n_stringhe);
        cout << media << endl;
        if((media - (int)media) != 0){
            media = (int)media + 1;
            cout << "DEBUG" << endl;
        }

        for(int i{0}; i < media; i++){
            myapp << '*';
        }

        myapp << endl;

    }

    myin.close();
    myapp.close();

}