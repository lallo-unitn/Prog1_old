using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

const int NMaxL{31};
const int scarto = 'A' - 'a';

int main(int argc, char* argv[]){

    if(argc != 3){
        cerr << "Error, usage : ./a.out <sourcefile> <targetfile>" << endl;
        exit(0);
    }

    fstream myin, myout;

    myin.open(argv[1], ios::in);
    myout.open(argv[2], ios::out);

    if(myin.fail()){
        cerr << "Error : sourcefile do not exist" << endl;
        exit(0);
    }

    char c[NMaxL];
    bool nextup = true;

    while(myin >> c){

        if(nextup == true){
            if(c[0] >= 'a' && c[0] <= 'z'){
                c[0] = c[0] + scarto;
            }
        }

        if(c[strlen(c)-1] == '!' || c[strlen(c)-1] == '.' || c[strlen(c)-1] == '?'){
            myout << c << ' ';
            nextup = true;
        }

        else{
            myout << c << ' ';
            nextup = false;
        };

    }

    myin.close();
    myout.close();

    return 0;

}