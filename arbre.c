#include <stdlib.h>
#include <stdio.h>
#include "arbre.h"

arbre gauche (arbre a){
    return a->fils_gauche;
}

arbre droit (arbre a){
    return a->fils_droit;
}

int valeur(arbre a){
    return a->elt;
}

arbre creer_arbre(void){
    return malloc(sizeof(arbre));
}

arbre ajoute_gauche(arbre a){
    a->fils_gauche = creer_arbre() ;
    return gauche(a);
}

arbre ajoute_droit(arbre a){
    a->fils_droit = creer_arbre();
    return droit(a);
}

void set_value (arbre a , char value){
    a->elt = value ;
}

int serialisation_plus(arbre a , char* str){
    int *p_i;
    int val;
    p_i = serialisation(a,str);
    val = *p_i;
    *p_i = 0;
    return val;
}


int* serialisation(arbre a, char*str){
    static int i = 0;
    if (a==NULL){
        str[i] = '0';
        i++;
    }else{
        str[i] = '1';
        i++;
        str[i] = valeur(a);
        i++;
        serialisation(gauche(a), str);
        serialisation(droit(a), str);
        return &i;
    }
}

arbre deserialisation (char* chaine){
    static int i = 0;
    if (chaine[i]=='0'){
        i++;
        return NULL;
    }
    if (chaine[i]=='1'){
        i++;
        arbre pointeur = creer_arbre();
        set_value(pointeur,chaine[i]);
        i++;
        pointeur->fils_gauche = (deserialisation(chaine));
        pointeur->fils_droit = (deserialisation(chaine));
        return pointeur;
    }
}