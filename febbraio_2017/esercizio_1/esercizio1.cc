using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

const int NMaxL{55};

int main(int argc, char* argv[]){

    if(argc != 3){
        cerr << "Error, usage : ./a.out <sourcefile> <targetfile>" << endl;
        exit(0);
    }

    fstream myin, myout;
    bool stop{false};
    int count{0};
    char string[NMaxL];

    myin.open(argv[1], ios::in);
    myout.open(argv[2], ios::out);

    while(!myin.eof() && stop == false){

        myin >> string;

        if(!strcmp(string, "STOP")) {stop = true;}
        else{
            count++;
        }

    }

    char** parole = new char*[count];

    myin.close();
    myin.open(argv[1], ios::in);

    for(int i{0}; i < count; i++){
       
        parole[i] = new char[NMaxL];
        myin >> parole[i];

    }

    for(int i{count-1}; i >= 0; i--){
        myout << parole[i] << " ";
    }

    myin.close();
    myout.close();

    return 0;

}