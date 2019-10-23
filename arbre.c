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
    return malloc(sizeof(noeud));
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
    
    int i,val;
    i = 0;
    int* p_i = &i;
    
    serialisation(a,str,p_i);
    
    val = i;

    return val;
}


void serialisation(arbre a, char*str, int*i){
    if (a==NULL){
        str[*i] = '0';
        (*i)++;
    }else{
        str[*i] = '1';
        (*i)++;
        str[*i] = valeur(a);
        (*i)++;
        serialisation(gauche(a), str, i);
        serialisation(droit(a), str, i);
    }
}
arbre deserialisation_sup(char *chaine){
    
    int i;
    arbre a;

    i=0;
    return deserialisation(chaine,&i);
}


arbre deserialisation (char* chaine, int*i){
    if (chaine[*i]=='0'){
        (*i)++;
        return NULL;
    }
    if (chaine[*i]=='1'){
        (*i)++;
        arbre pointeur = creer_arbre();
        set_value(pointeur,chaine[*i]);
        (*i)++;
        pointeur->fils_gauche = (deserialisation(chaine,i));
        pointeur->fils_droit = (deserialisation(chaine,i));
        return pointeur;
    }
}