#include <iostream>
#include <cstring>
using namespace std;

const char SEGNAPOSTO = '!';
const int DIMMAX = 40;

void reverse_array(char input[],int dim);
void reverse_array_rec(char input[], int dim, int index);
bool is_voc_lower(char input[], int index);
void up(char input[], int index);
void scambia(char input[], int dim, int index);


int main (int argc, char* argv[]) {
    
    char input[DIMMAX];
    char p[] = "p";

    cout << strlen(p);
    
    cout << "Introdurre stringa da invertire: ";
    cin >> input;                                     // Assumiamo che sia sempre strlen(input) < DIMMAX
    
    reverse_array(input, strlen(input));
    
    cout << "Array invertito: " << input << endl;
    
    return 0;
    
}

void reverse_array(char input[],int dim){

    cout << "primo : " << input[dim] << endl;

    reverse_array_rec(input, dim, 0);

}

void reverse_array_rec(char input[], int dim, int index){

    if(index < (dim / 2)){

        if(is_voc_lower(input, index)){
            cout << "DEBUG1" << input[index]<< endl;
            up(input, index);
        };

        if(is_voc_lower(input, ((dim-1)-index))){
            cout << "DEBUG2" << input[index]<< endl;
            up(input, (dim-1)-index);
        };

        if(index != ((dim-1)-index)){
            cout << "DEBUG3" << endl;
            scambia(input,dim,index);
            
        }

        cout << input << endl;

        index++;
        
        reverse_array_rec(input, dim, index);

    };

}

bool is_voc_lower(char input[], int index){

    cout << input[index] << endl;

    bool res{false};

    if(input[index] == 'a' || input[index] == 'e' || input[index] == 'i' || input[index] == 'o' || input[index] == 'u'){
        cout << "prova" <<input[index] << endl;
        res = true;
    }

    return res;

}

void up(char input[], int index){

    cout << "In up :" << input[index] << endl;

    input[index] = SEGNAPOSTO;

}

void scambia(char input[], int dim, int index){

    char temp;

    temp = input[index];
    input[index] = input[(dim-1)-index];
    input[(dim-1)-index] = temp;

}