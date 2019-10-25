# ifndef ARBRE_H
#define ARBRE_H

struct znoeud {
    char elt ;
    struct znoeud *fils_gauche ;
    struct znoeud *fils_droit ;
};

typedef struct znoeud noeud ;
typedef struct znoeud * arbre ;

// Retourne l'adresse de la branche a gauche
arbre gauche(arbre a);

// Retourne l'adresse de la branche a droite
arbre droit(arbre a);

// Retourne la valeur du noeud de a
int valeur(arbre a);

// Rencoie un pointeur sur un arbre vide
arbre creer_arbre(void);

// Ajoute un arbre a gauche du neoud a
arbre ajoute_gauche(arbre a);

// Ajoute un arbre a droite du neoud a
arbre ajoute_droit(arbre a);

// Fixe la vaaleur de l'enlement du noeud
void set_value(arbre a, char value);

// Transforme un arbre en chaine de caractere
void serialisation(arbre a, char *str, int* i);

// Transforme une str en arbre
arbre deserialisation(char *chaine, int *i);

char* serialisation_plus(arbre a);

arbre deserialisation_sup(char *chaine);

#endif