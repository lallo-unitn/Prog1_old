using namespace std;
#include <iostream>
#include <cstdlib>
#include <fstream>

const int NMaxL{81};

bool is_address(char stringa[]);
bool is_at(char c);
bool perm_ch(char c);
bool is_number(char c);
bool is_alpha(char c);

int main(int argc, char* argv[]){

    if(argc != 3){
        cerr << "Error, usage : ./a.out <sourcefile> <targetfile>" << endl;
        exit(EXIT_FAILURE);
    }

    fstream myin, myout;
    myin.open(argv[1], ios:: in);
    myout.open(argv[2], ios::out);

    if(myin.fail()){
        cerr << "Error : file does not exist";
    }

    char stringa[NMaxL];

    while(myin >> stringa){

        if(is_address(stringa)){
            myout << stringa << endl;
            cout << stringa << endl;
        }

    }

    myin.open(argv[1], ios:: in);
    myout.open(argv[2], ios::out);

    return 0;

}

bool is_address(char stringa[]){

    bool res{true};
    int at_count{0};

    for(int i{0}; stringa[i] != '\0' && res == true; i++){
        if(!perm_ch(stringa[i])) res = false;
        if(is_at(stringa[i])) {
            at_count++;
            if(i == 0 || stringa[i+1] == '\0') res = false;
            if(at_count > 1)res = false;
        }
        else if(i == 0 || stringa[i+1] == '\0'){
            if(stringa[i] == '.') res = false;
        }
    }

    if(at_count != 1) res = false;

    return res;

}

bool perm_ch(char c){

    bool res{false};

    if(is_alpha(c)) res = true;
    else if(is_number(c)) res = true;
    else if(c == '.' || c == '_' || c == '@') res = true;

    return res;

}

bool is_at(char c){

    bool res{false};
    if(c == '@') res = true;

    return res;

}

bool is_alpha(char c){

    bool res{false};
    if((c >='a' && c <='z') || (c >= 'A' && c <='Z')) res = true;

    return res;

}

bool is_number(char c){

    bool res{false};
    if(c >= '0' && c <= '9') res = true;

    return res;

}