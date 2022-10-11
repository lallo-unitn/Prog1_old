using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

const int NMaxL{256};

int main(int argc, char* argv[]){

    if(argc != 4){
        cerr << "Error, usage : ./a.out <sourcefile_1> <sourcefile_2> <targetfile>" << endl;
        exit(0);
    };

    fstream myin_1, myin_2, myout;
    char stringa[NMaxL];
    char stringa2[NMaxL];
    const char* key = "INCLUDI";

    myin_1.open(argv[1], ios::in);
    myout.open(argv[3], ios::out);

    while(!myin_1.eof()){

        myin_1.getline(stringa,NMaxL);
        //cout << stringa << endl;  
        myout << stringa << endl;       
        cout << key << endl << stringa << endl;
        cout << strcmp(stringa, key) << endl;
        if(strcmp(stringa,key) == 0){
            
            myin_2.open(argv[2], ios::in);

            cout << "prova2" << endl;
            
            while(!myin_2.eof()){
            
                myin_2.getline(stringa2,NMaxL);
                cout << stringa2 << endl;
                myout << stringa2 << endl;
                myin_2.close();
            
            }
        }
    }

    myin_1.close();
    myout.close();

    return 0;

}