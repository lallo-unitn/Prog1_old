using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

const char KEY[] = "STOP";
const int NMaxL{51};

void leggi_stampa(fstream& myin, fstream& myout);

int main(int argc, char* argv[]){

    if(argc != 3){
        cerr << "Error, usage : ./a.out <sourcefile> <targetfile>" << endl;
        exit(EXIT_FAILURE);
    }

    fstream myin, myout;

    myin.open(argv[1], ios::in);
    myout.open(argv[2], ios::out);

    if(myin.fail()){
        cerr << "Error : cannot read source file" << endl;
        exit(EXIT_FAILURE);
    }

    leggi_stampa(myin,myout);

    myin.close();
    myout.close();

    return 0;

}

void leggi_stampa(fstream& myin, fstream& myout){

    char stringa[NMaxL];
    myin >> stringa;
    
    if(!myin.eof()){

        if(strcmp(stringa, KEY) != 0 && !myin.eof()){
            leggi_stampa(myin,myout);
            myout << stringa << " ";
        }
    }
}