using namespace std;
#include <iostream>
#include <cstring> 
#include <fstream>
#include <cstdlib>

const int NMaxL{81};

int main(int argc, char* argv[]){

    if(argc != 4){
        cerr << "Error, usage : ./a.out <sourcefile> <n_lines> <targetfile>" << endl;
        exit(0);
    }

    fstream myin,myout;
    int count{0};
    int n_lines = atoi(argv[2]);
    char temp[NMaxL];
    char** stringa = new char*[n_lines];
    int i{0};

    myin.open(argv[1], ios::in);
    myout.open(argv[3], ios::out);

    if(myin.fail()){
        cerr << "Error while resading " << argv[1] << endl;
        exit(0);
    }

    while(count < n_lines){

        if((count % 2  != 0) && count != 0){
            stringa[i] = new char[NMaxL];
            myin.getline(stringa[i],NMaxL);
            i++;
        }
        else{
            myin.getline(temp,NMaxL);
        }
        count++;
    }

    for(int j{i-1}; j >= 0; j--){
        cout << "DEBUG" << endl;
        myout << stringa[j];
        if(stringa[j][0] != '\0'){
            myout << '\n';
        }
    }

    for(int i{0}; i < n_lines; i++){
        delete[] stringa[i];
    }

    delete stringa;

    myin.close();
    myout.close();

}