using namespace std;
#include <iostream>
#include <fstream>

const int NMaxL{256};

int main(int argc, char* argv[]){
    if(argc != 3){
        cerr << "Error, usage : ./a.out <source> <target>" << endl;
        exit(0);
    }
    fstream myin, myout;
    myin.open(argv[1],ios::in);
    myout.open(argv[2],ios::out); 

    char stringa[NMaxL];
    int count{0};

    while(myin >> stringa){

        count = 0;

        for(int i{0}; stringa[i] != '\0'; i++){
            if(stringa[i] == 'a')count ++;
        }

        myout << count << "   ";

    }

    myin.close();
    myout.close();

    return 0;

}