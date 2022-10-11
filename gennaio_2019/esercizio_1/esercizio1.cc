using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

const int NMaxS{30};

void upper(char c[]);
bool controllo_utente(int argc);
bool ispunt(char c[]);

int main(int argc, char* argv[]){

    if(!controllo_utente(argc)){
        cerr << "Usage : './a.out ingresso.txt uscita.txt'" << endl;
    }

    else{

        char c[NMaxS];
        bool nextup{true};

        fstream myin, myout;

        myin.open(argv[1], ios::in);
        myout.open(argv[2], ios::out);

        while(!myin.eof()){
            myin >> c;
            if(nextup == true){
                if(c[0] >= 'a' && c[0] <= 'z'){
                    upper(c);
                };
            };
            if(ispunt(c)){
                myout << endl;
                nextup = true;
            }
            else{
                nextup = false;
            };
            myout << c;
            myout << ' ';
        };

        myin.close();
        myout.close();

    };

    return 0;

}

void upper(char c[]){
    const int scarto = ('A' - 'a');
    c[0] = c[0] + scarto;
}

bool ispuntr(char c[]){
    bool res{false};
    if(c[strlen(c)-1] == '!' || c[strlen(c)-1] == '?' || c[strlen(c)-1] == '.' ){
        res = true;
    };
    return res;
}

bool controllo_utente(int argc){
    bool res{true};
    if(argc != 3){
        res = false;
    };

    return res;

}