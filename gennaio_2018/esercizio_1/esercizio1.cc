using namespace std;
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>

const int NMaxL{255};

int main(int argc, char* argv[]){

    if(argc != 4){
        cerr << "Usage : <sourcefile> <n_lines> <output>" << endl;
        exit(0);
    };

    fstream myin, my_numb, myout;

    int n_lines{0};
    char** string;

    myin.open(argv[1], ios::in);
    my_numb.open(argv[2], ios::in);
    myout.open(argv[3], ios::out);

    n_lines = atoi(argv[2]);

    string = new char* [n_lines];

    for(int i = 0; (i < n_lines); i++){

        string[i] = new char [NMaxL];
        myin.getline(string[i],NMaxL);
        if(string[i][0] != '\0'){
            string[i][(strlen(string[i]))] = '\n';
        }

        else{
            i++;
            n_lines = i;
        }
    
    };

    for(int i = n_lines-1; i >= 0; i--){


        for(int j{0}; string[i][j] != '\0'; j++){

            if(((j % 2) == 0) && (string[i][j] != ' ') && (string[i][j] != '\n') && (string[i][j] != '\t')){

                myout.put('*');
                //myout.put(string[i][j]);

            }

            else if(((j % 2) != 0) && (string[i][j] != ' ') && (string[i][j] != '\n') && (string[i][j] != '\t')){

                myout.put('+');
                //myout.put(string[i][j]);

            }

            else if((string[i][j] == ' ') || (string[i][j] == '\n') || (string[i][j] == '\t')){

                myout.put(string[i][j]);

            }

        }

    };

    for(int i{0}; i < n_lines; i++){
        delete[] string[i];
    };

    delete string;

    myin.close();
    my_numb.close();
    myout.close();

    return 0;

}