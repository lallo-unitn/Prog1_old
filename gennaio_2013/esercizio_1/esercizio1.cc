using namespace std;
#include <iostream>
#include <cstdlib>
#include <fstream>

const int scarto = 'a' - 'A';
const int NAlf{scarto};
char alfabeto[NAlf];

void riempi_alf(char alfabeto[]);
int is_alfa(char c);
char succ_low(char c);
char succ_up(char c);
bool is_blank(char c);

int main(int argc, char* argv[]){

    if(argc != 4){
        cerr << "Error, usage : ./a.out <sourcefile> <targetfile> <num>" << endl;
        exit(EXIT_FAILURE);
    }

    fstream myin, myout;

    myin.open(argv[1], ios::in);
    myout.open(argv[2], ios::out);

    if(myin.fail()){
        cerr << "Error : sourcefile does not exist" << endl;
        exit(EXIT_FAILURE);
    }

    char c;
    int max = atoi(argv[3]);
    int count{0};

    riempi_alf(alfabeto);

    while(myin.get(c) && count < max){
        if(is_alfa(c) == 1){
            c = succ_up(c);
            myout.put(c);
            cout.put(c);
            //count++;
        }
        else if(is_blank(c)) {
            myout.put(c);
            cout.put(c);
        }
        else if(is_alfa(c) == 0){
            myout.put(c);
            cout.put(c);
            //count++;
        }
        else if(is_alfa(c) == -1){
            c = succ_low(c);
            myout.put(c);
            cout.put(c);
            //count++;
        }
        count++;
    }
    cout << endl;

    myin.close();
    myout.close();

    return 0;
}

void riempi_alf(char alfabeto[]){

    char lett{'a'};
    for(int i{0}; i < NAlf; i++){
        alfabeto[i] = lett;
        lett++;
    }

}

int is_alfa(char c){

    int res{0};

    if(c >= 'a' && c <= 'z') res = -1;
    else if(c >= 'A' && c <= 'Z') res = 1;

    return res;

}

char succ_low(char c){

    char res;
    bool found{false};

    for(int i{0}; i < NAlf && found == false; i++){
        if(alfabeto[i] == c){
            res = alfabeto[(i+3) % NAlf];
            found = true;
        }
    }

    return res;

}

char succ_up(char c){

    char res;
    bool found{false};
    c = c + scarto;

    for(int i{0}; i < NAlf && found == false; i++){
        if(alfabeto[i] == c){
            res = alfabeto[(i+3) % NAlf];
            found = true;
        }
    }

    res = res - scarto;

    return res;

}

bool is_blank(char c){

    bool res{false};
    if(c == ' ' || c == '\n') res = true;

    return res;

}