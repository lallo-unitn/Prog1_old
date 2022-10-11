#include <iostream>
using namespace std;
const int MAX_PRIMI = 100;
const int CENTO_PRIMI[MAX_PRIMI] ={  2,   3,   5,   7,  11,  13,  17,  19,  23,  29,31,  37,  41,  43,  47,  53,  59,  61,  67,  71
                                    ,73,  79,  83,  89,  97, 101, 103, 107, 109, 113,127, 131, 137, 139, 149, 151, 157, 163, 167, 173
                                    ,179, 181, 191, 193, 197, 199, 211, 223, 227, 229,233, 239, 241, 251, 257, 263, 269, 271, 277, 281,283,
                                    293, 307, 311, 313, 317, 331, 337, 347, 349,353, 359, 367, 373, 379, 383, 389, 397, 401, 409,419, 421,
                                    431, 433, 439, 443, 449, 457, 461, 463,467, 479, 487, 491, 499, 503, 509, 521, 523, 541};

int primo(int n);
int primo_rec(int n,int res, int index);

int main() {
    
    int n,ris;
    
    do {
        cout << "Introdurre un numero intero > 1: ";
        
        cin >> n;
        if (n < 1)cerr << "Il numero e’ troppo piccolo." << endl;
        
        else {
            ris = primo(n);
        
            if (ris < 0)cout << "Non sono riuscito a stabilire se " << n << " e’ primo\n";
        
            else cout << n << ((ris > 0) ? "" : " non") << " e’ primo." << endl;}
    } while (n > 1);
    
    return (0);

}

int primo(int n){

    int res{-1};

    res = primo_rec(n,res,0);

    return res;

}

int primo_rec(int n,int res, int index){

    if(index < MAX_PRIMI){

        if(n == CENTO_PRIMI[index]) res = 1;

        else if(n % CENTO_PRIMI[index] == 0) res = 0;

        else{
            index++;
            res = primo_rec(n,res,index);
        };

    };

    return res;

}