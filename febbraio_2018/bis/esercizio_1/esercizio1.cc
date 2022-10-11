using namespace std;
#include <iostream>
#include <fstream>

const int NMaxL{82};

bool is_address(char stringa[]);
bool is_dot(char c);
bool is_at(char c);
bool is_permitted_ch(char c);

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

    char stringa[NMaxL];

    while(myin >> stringa){

        if(is_address(stringa)){
            myout << stringa << endl;
            cout << stringa << endl;
        }

    }

    myin.close();
    myout.close();

    return 0;

}

bool is_address(char stringa[]){

    bool res{true};
    int at_count{0};
    int count{0};

    for(int i{0}; stringa[i] != '\0' && res == true; i++){

        //cout << stringa[i] << "  " << i << "   " << at_count << endl;

        if(is_at(stringa[i])){
            at_count++;
            if(i <= 1 || at_count > 1){
                //cout << "debug" << endl;
                res = false;
            }
            else{
                count = 0;
                for(int test{i}; stringa[test] != '\0'; test++){
                    count++;
                }
                //cout << count << endl;
                if(count <= 2) res = false;
            }
        }
        else if (is_dot(stringa[i]) && (i == 0 || stringa[i+1] == '\0')){
            res = false;
        }
        else if(!is_permitted_ch(stringa[i])){
            res = false;
        }

    }

    if(at_count != 1) res = false;

    return res;

}

bool is_at(char c){

    bool res{false};

    if(c == '@'){
        res = true;
    }

    return res;

}

bool is_permitted_ch(char c){

    bool res{false};

    if(c >= 'a' && c <= 'z') res = true;
    else if(c >= 'A' && c <= 'Z') res = true;
    else if(c >= '0' && c <= '9') res = true;
    else if(c == '_') res = true;
    else if(c == '.') res = true;

    return res;

}

bool is_dot(char c){

    bool res{false};

    if(c == '.'){
        res = true;
    }

    return res;

}