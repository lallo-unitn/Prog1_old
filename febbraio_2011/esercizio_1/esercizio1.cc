using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

const int NMaxL{256};

int main(int argc, char* argv[]){

    if(argc != 4){
        cerr << "Error, usage : ./a.out <source1> <source2> <target>" << endl;
        exit(EXIT_FAILURE);
    }

    fstream myin1,myin2,myout;

    myin1.open(argv[1], ios::in);
    myin2.open(argv[2], ios::in);
    myout.open(argv[3], ios::out);

    if(myin1.fail() || myin2.fail()){
        cerr << "Error : file cannot be opened" << endl;
        exit(EXIT_FAILURE);
    }

    char stringa1[NMaxL];
    char stringa2[NMaxL];
    bool flag{false};
    myin2.getline(stringa2, NMaxL);

    while(!myin1.eof()){
        myin1.getline(stringa1, NMaxL);
        flag = false;

        while(!myin2.eof() && flag == false){

            if(strcmp(stringa1,stringa2) < 0){
                flag = true;
            }

            else if(strcmp(stringa1,stringa2) > 0){
                myin2.getline(stringa2, NMaxL);
            }
            
            else if(strcmp(stringa1,stringa2) == 0){
                flag = true;
                myout << stringa1 << endl; 
            }
        }
    }

    myin1.close();
    myin2.close();
    myout.close();

    return 0;

}