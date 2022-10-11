using namespace std;
#include <iostream>
#include <fstream>

const int NMaxStr{81};


bool is_address(char s[]);

bool is_letter(char c);

bool is_dot(char c);

bool not_permitted_char(char c);

bool is_number(char c);


int main(int argc, char* argv[]){

    char s[NMaxStr];
    char c;

    if(argc != 2){
        cerr << "Usage : './a.out <sourcefile>'" << endl;
        exit(0);
    };

    fstream myin;

    myin.open(argv[1], ios::in);

    while(!myin.eof()){
        myin >> s;
        if(is_address(s)){
            cout << s << endl;
        }
    };

    myin.close();
    return 0;

}

bool is_address(char s[]){

    int lunghezza{0};
    bool is_address{true};
    int at_count{0};
    bool res{false};
    char c;

    for(int i{0}; s[i] != '\0'; i++){
        c = s[i];
        lunghezza = i;
        if(is_dot(c) && (i == 0 || (s[i+1] == '\0' ))){
            is_address = false;
        }
        else if(c == '@') at_count++;
        else if(not_permitted_char(c) == true){
            is_address = false;
        }

    }

    if(lunghezza >= 1 && is_address == true && at_count == 1) res = true;

    return res;

}

bool is_letter(char c){
    bool res{false};
    if((c >='A' && c <='Z') || (c >='a' && c <='z')) res = true;
    return res;
}

bool is_dot(char c){
    bool res{false};
    if(c == '.') res = true;
    return res;
}

/*bool not_permitted_char(char c){
    bool res{false};
    if((!is_letter(c)) /* && (!is_number(c))  && (!is_point(c)) && (c != '_') && (c != '@')) res = true;
    return res;
}*/

bool is_number(char c){
    bool res{false};
    if(c >='0' && c <='9') res = true;
    return res;
}

bool not_permitted_char(char c){
    bool res{false};
    if((!is_letter(c)) && (!is_number(c)) && (c != '_') && (!is_dot(c)) && (c!='@')) res = true;
    return res;
}