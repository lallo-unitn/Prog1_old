using namespace std;
#include <iostream>
#include <fstream>
#include <cstdlib>

typedef double** matrix;

const int NMaxL{25};

matrix leggiMatrice(fstream& myin, int& righe, int& colonne);

int main(int argc, char* argv[]){

    if(argc != 2){
        cerr << "Error, usage : ./a.out <sourcefile>" << endl;
        exit(EXIT_FAILURE);
    }
    fstream myin;
    int righe{0};
    int colonne{0};
    myin.open(argv[1], ios::in);

    if(myin.fail()){
        cerr << "Error : file does not exist or is not usable" << endl;
        exit(EXIT_FAILURE);
    }
 
    matrix M = leggiMatrice(myin,righe,colonne);

    myin.close();

    for(int i{0}; i < righe; i++){
        delete[] M[i];
    }
    delete M;

    return 0;

}

matrix leggiMatrice(fstream& myin, int& righe, int& colonne){

    char stringa[NMaxL];
    double elem{0};

    myin >> stringa;
    righe = atof(stringa);
    
    myin >> stringa;
    colonne = atof(stringa);

    matrix res = new double*[righe];

        for(int i{0}; i < righe; i++){
            res[i] = new double[colonne];
            
            for(int j{0}; j < colonne; j++){
                myin >> stringa;
                elem = atof(stringa);
                res[i][j] = elem;
            }
        }

    return res;

}