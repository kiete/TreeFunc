#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"
#define T_MAX 80

int main(){
    int j;
    arbre b;
// On cree l'exemple de la figure 1
    arbre a,p ;
    a = creer_arbre() ;
    set_value(a,'a') ;
    p = a ;
    p = ajoute_gauche(p);
    set_value(p, 'b');
    p = ajoute_gauche(p);
    set_value(p, 'c');
    p = ajoute_droit(a);
    set_value(p, 'd');
    p = ajoute_droit(p);
    set_value(p, 'y');
    p = ajoute_gauche(droit(a));
    set_value(p, 'x');
    

    char* fin = malloc(sizeof(char)*T_MAX);
    
    j = serialisation_plus(a, fin);
    printf("Etape 1 : %s\n", fin);
    fin[j] = 0;
    
    b = deserialisation(fin);

    
    j = serialisation_plus(a, fin);
    printf("Etape 2 : %s\n", fin);

    return 0;
}