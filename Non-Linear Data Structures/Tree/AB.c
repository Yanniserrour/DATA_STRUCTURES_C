#include <stdio.h>
#include <stdlib.h>

// declaration dynamique d'un AB a l'aide des listes chainer 
typedef struct AB{
    int cle ; 
    struct AB *fg;
    struct AB *fd;
} AB ; 


//procedure 1 : parcours prefixe d'un AB
void prefixe ( AB *T){
    if (T!=NULL){
        printf("%d",T->cle);
        prefixe(T->fg);
        prefixe(T->fd);
    }
}

//procedure 2 : parcours infixe d'un AB
void infixe (AB *T){
    if (T!=NULL){
    infixe(T->fg);
    printf("%d",T->cle);
    infixe(T->fd);
    }
}

//procedure 3 : parcours postfixe d'un AB
void postfixe (AB *T){
    if (T!=NULL){
    postfixe(T->fg);
    postfixe(T->fd);
    printf("%d",T->cle);
    }
}

//fonction 4 : calculer la hauteurs d'un AB
int max (int a , int b){
    if (a>b){
        return a ;
    }else 
        return b;
}
int Hauteur (AB *T){
    if (T==NULL){
        return 0;
    }
    return (max(1+Hauteur(T->fg), 1+Hauteur(T->fd)));
}

//fonction 5 : calcule le nombre de noeud d'AB
int Nb_noeud (AB *T){
    if (T==NULL){
        return 0;
    }
    return (1+ Nb_noeud(T->fg) + Nb_noeud(T->fd));
}

//fonction 6 : calculer le nombre de feuilles d'un AB 
int Nb_feuilles (AB *T){
    if (T==NULL){
        return 0;
    }
    if (T->fg == NULL && T->fd == NULL){
        return 1;
    }
    return (Nb_feuilles(T->fg) + Nb_feuilles(T->fd));
}

//procedure 7 : liberer un AB
void liberer (AB **T){
    if(*T!=NULL){
        liberer(&(*T)->fg);
        liberer(&(*T)->fd);
        free(*T);
    }
}