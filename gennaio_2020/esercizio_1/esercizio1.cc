using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

const int MaxD{256};

bool compara(char stringa1[], char** stringa2, int index);

int main(int argc, char* argv[]){

    if(argc != 4){
        cerr << "Error, usage : ./a.out <source1> <source2> <target>" << endl;
        exit(0);
    }
    fstream myin1, myin2, myout;

    myin1.open(argv[1], ios::in);
    myin2.open(argv[2], ios::in);
    myout.open(argv[3], ios::out);

    if(myin1.fail() || myin2.fail()){
        cerr << "Error : <source1> or <source2> does not exist" << endl;
        exit(0);
    }

    char stringa1[MaxD];
    char stringa_c[MaxD];
    char** stringa2;

    if(myin1.getline(stringa1,MaxD));
    int n_lines1 = atoi(stringa1);
    if(myin2.getline(stringa_c,MaxD));
    int n_lines2 = atoi(stringa_c);

    stringa2 = new char* [n_lines2];

    for(int i{0}; i < n_lines2; i++){
        stringa2[i] = new char[MaxD];
        myin2.getline(stringa2[i], MaxD);
    };

    while(!myin1.eof()){
        myin1.getline(stringa1,MaxD);
        if(compara(stringa1,stringa2,n_lines2)){
            myout << stringa1 << endl;
        }
    }

    for(int i{0}; i < n_lines2; i++){

        delete[] stringa2[i];

    };

    delete stringa2;

    myin1.close();
    myin2.close();
    myout.close();

    return 0;
}

bool compara(char stringa1[], char** stringa2, int n_lines2){

    bool res{false};

    for(int i{0}; i < n_lines2; i++){
        if(strcmp(stringa1,stringa2[i]) == 0) res = true;
    }

    return res;

}