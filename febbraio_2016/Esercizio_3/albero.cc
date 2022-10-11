#include <iostream>
#include "albero.h"

using namespace std;

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

    if(vuoto(t) == VERO){
        Nodo* temp = new (nothrow) Nodo;

        if(temp != NULL){

            temp->val = val;
            temp->sx = NULL;
            temp->dx = NULL;
            t = temp;
            res = VERO;

        }

    }
    
    else{
        if(val <= t->val) inserisci(t->sx,val);
        else if(val > t->val) inserisci(t->dx,val);
    }

    return res;

}

boolean cerca(const Albero &t, int val){

    boolean res{FALSO};

    if(vuoto(t) == FALSO && res == FALSO){
        if(val < t->val){cout << "prova1"<<endl;cerca(t->sx,val);};
        if(val > t->val) {cout << "prova2"<<endl;cerca(t->dx,val);};
        if(t->val == val){ 
            cout << "prova3" << endl;
            res = VERO;
        }
    }

    return res;

}

void stampa(const Albero &t){

    if(t != NULL){

        stampa(t->sx);
        cout << t->val << "     ";
        stampa(t->dx);
    
    }

}