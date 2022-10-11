using namespace std;
#include <iostream>
#include "albero.h"

void inizializza(Albero &t){

    t = NULL;

}

boolean vuoto(const Albero &t){

    boolean res{FALSO};

    if(t == NULL) res = VERO;

    return res;

}

boolean inserisci(Albero &t, int val){

    boolean res{FALSO};

    if(t == NULL){
        t = new (nothrow) Nodo;
        if(t != NULL){
            t->sx = NULL;
            t->dx = NULL;
            t->val = val;
            res = VERO;
        }
    }

    else{

        if(t->val < val) res = inserisci(t->dx, val);
        else if(t->val >= val) res = inserisci(t->sx, val);

    }

    return res;

}

/*boolean cerca(const Albero &t, int val){

    boolean res{FALSO};

    if(t != NULL && res == FALSO){
        if(t->val < val) res = cerca(t->dx,val);
        else if(t->val > val) res = cerca(t->sx,val);
        else if(t->val == val) res = VERO;
    }

    return res;

}*/

boolean/* {aka nodo*} */cerca(const Albero& t, int val){

    boolean res{FALSO}; 

    if(t != NULL){

        if(val > t->val){
            res = cerca(t->dx, val);
            cout <<"DEBUG 1" << endl;
        }
        else if(val < t->val){
            res = cerca(t->sx, val);
            cout <<"DEBUG 2" << endl;
        }
        else if(val == t->val){
            res = VERO;
            cout <<"DEBUG 3" << endl;
        };

    };

    return res;
    
}

void stampa(const Albero &t){

    if(t != NULL){

        stampa(t->sx);
        cout << t->val << "      ";
        stampa(t->dx);
    
    }

}