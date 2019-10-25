#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"
#define T_MAX 80

int main(){
    int j;
    char *str1, *str2;
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
    
    
    str1 = serialisation_plus(a);
    printf("Etape 1 : %s\n", str1);
    
    b = deserialisation_sup(str1);
    
    str2 = serialisation_plus(b);
    printf("Etape 2 : %s\n", str2);

    return 0;
}