using namespace std;
#include <iostream>
#include <cstdlib>
#include <fstream>

void sort_array(int* vect, int DIM);

const int NMaxV{3};

int main(int argc, char* argv[]){

    if(argc != 4){
        cerr << "Error, usage : ./a.out <sourcefile> <n_voti> <n_max_voti>" << endl;
        exit(EXIT_FAILURE);
    }

    fstream myin,myout;

    myin.open(argv[1], ios::in);
    myout.open("output.txt", ios::out);

    if(myin.fail()){
        cerr << "Error : cannot open source file" << endl;
        exit(EXIT_FAILURE);
    }

    int DIM{atoi(argv[2])};
    int N{atoi(argv[3])};
    char stringa[NMaxV];

    int* vect = new int[DIM];

    for(int i{0}; i < DIM; i++){
        myin >> stringa;
        vect[i] = atoi(stringa);
    }

    sort_array(vect,DIM);

    for(int i{0}; i < N; i++){
        myout << vect[i] << endl;
        cout << vect[i] << endl;
    }

    delete[] vect;

    myin.close();
    myout.close();

    return 0;

}

void sort_array(int* vect, int DIM){

    bool flag{true};
    int temp;

    for(int i = 1; (i <= DIM) && flag; i++)
     {
          flag = false;
          for (int j=0; j < (DIM -1); j++)
         {
               if (vect[j+1] > vect[j])      // ascending order simply changes to <
              { 
                    temp = vect[j];             // swap elements
                    vect[j] = vect[j+1];
                    vect[j+1] = temp;
                    flag = true;               // indicates that a swap occurred.
               }
          }
     }

}