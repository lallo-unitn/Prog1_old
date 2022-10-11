using namespace std;
#include <iostream>
#include <fstream>

int main(int argc, char* argv[]){

    if(argc != 2){
        cerr << "Error, usage : ./a.out <sourcefile>" << endl;
        exit(0);
    }
    fstream myin;

    char stringa[20];

    myin.open(argv[1], ios::in);

    if(myin.fail()){
        cerr << "Error : file does not exist" << endl;
        exit(0);
    }

    myin >> stringa;
    cout << stringa;
    myin >> stringa;
    cout << stringa;

    myin.close();

    return 0;

}