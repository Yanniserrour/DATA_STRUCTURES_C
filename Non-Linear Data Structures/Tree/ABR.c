#include <stdio.h>
#include <stdlib.h>

// declaration dynamique avec des listes chainer 
typedef struct ABR {
    int cle ; 
    struct ABR *fg;
    struct ABR *fd;
}ABR ; 

//procedure 1 : insertion dans un ABR
void Insert_Abr (ABR **T, int x){
    if (*T == NULL){
        (*T)=(struct ABR*)malloc(sizeof(struct ABR));
        (*T)->cle = x; 
        (*T)->fg  = NULL;
        (*T)->fd  = NULL;
    }else if (x<(*T)->cle){
        Insert_Abr(&((*T)->fg), x);
    }else if (x>(*T)->cle){
        Insert_Abr(&((*T)->fd), x);
    }
}

//procedure 1 : insertion dans un ABR (version itérative)
void Insertion (ABR **arbre, int x) {

    ABR *tmparbre = *arbre ; //celui qui avance
    ABR *pereNode ; //celui qui sauvgarde le pere
    ABR *E = malloc (sizeof (ABR)) ; //le noeud lui meme 

    E->cle = x ; 
    E-> fg = NULL ; 
    E->fd = NULL ; 
    
    if (tmparbre) 
        do { 
            pereNode = tmparbre; 
            if (x > tmparbre->cle ) { 
                tmparbre = tmparbre -> fd; 
                if (tmparbre==NULL)
                    pereNode -> fd = E;  
            } else{ 
                tmparbre = tmparbre->fg;  
                if (tmparbre==NULL) 
                    pereNode->fg = E; 
            } 
        }  while (tmparbre); 
    else  
        *arbre = E ;
}

//procedure 2 : parcours infixe dans un ABR
void Parcour_infixe(ABR *T){
    if (T!=NULL){
        Parcour_infixe(T->fg);
        printf("%d",T->cle);
        Parcour_infixe(T->fd);
    }
}

//fonction 3 : rechercher la valeur de la clé MAX dans un ABR
int Max_Abr_cle (ABR *T){
    if (T==NULL){
        return 0;
    }
    if (T->fd == NULL){
        return (T->cle);
    }
    return (Max_Abr_cle(T->fd));
}

//fonction 4 : rechercher l'adresse de la clé MAX dans un ABR
ABR *Max_Abr_pointeur (ABR *T){
    if (T == NULL){
        return NULL;
    }
    if (T->fd == NULL){
        return T;
    }
    return (Max_Abr_pointeur(T->fd));
}

//fonction 5 : rechercher un élément x dans un ABR
ABR *recherche (ABR *T, int x){
    if (T==NULL) return NULL; 
    if (x< T->cle){
        return (recherche(T->fg, x));
    }else if (x> T->cle){
        return (recherche(T->fd, x));
    }else{
        return T; 
    }
}

//procedure 6 : supprimer le MAX dans un ABR 
void Sup_Max_Abr (ABR **T){
    if ((*T)== NULL){
        return ; 
    }
    if ((*T)->fd == NULL){
        ABR *temp = *T;
        (*T)=(*T)->fg;
        free(temp);
        return ;
    }
    return (Sup_Max_Abr(&((*T)->fd)));
}

//procedure 6 : supprimer le MAX dans un ABR (itérative)
int Suprim_Max_iterative(ABR **A) {
    ABR *Pere, *E;
    int X;

    if (*A == NULL) {
        return -1; 
    }

    // Cas particulier : le maximum est la racine
    if ((*A)->fd == NULL) {
        X = (*A)->cle;
        E = *A;
        *A = (*A)->fg;
        free(E);
        return X;
    }

    // Cas général
    Pere = *A;
    E = (*A)->fd;

    while (E->fd != NULL) {
        Pere = E;
        E = E->fd;
    }

    // E pointe sur le maximum
    X = E->cle;
    Pere->fd = E->fg; // important si le max a un fils gauche
    free(E);

    return X;
}

//procedure 7 : supprimer une clé dans un ABR
void Suprim_Abr (ABR **T,int x){
    if (*T== NULL) return ; 
    if (x<(*T)->cle){
        Suprim_Abr(&((*T)->fg), x);
    }else if (x>(*T)->cle){
        Suprim_Abr(&((*T)->fd), x);
    }else {
        if ((*T)->fd == NULL){
            ABR *temp = *T;
            (*T)=(*T)->fg;
            free(temp);
        }else if((*T)->fg == NULL) {
            ABR *temp = *T;
            (*T)=(*T)->fd;
            free(temp);
        }else {
            ABR **sucs = &(*T)->fd;
            while((*sucs)->fg!=NULL){
                sucs = &(*sucs)->fg;
            }
            (*T)->cle = (*sucs)->cle;
            Suprim_Abr(sucs, (*sucs)->cle);
        }
    }

}

//fonction 8 : calculer la heuteurs d'un ABR
int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}
int hauteur(ABR *T) {
    if (T == NULL)
        return 0;
    else
        return max(1 + hauteur(T->fg), 1 + hauteur(T->fd));
}

//fonction 8 : calculer la hauteurs d'un ABR (version TD)
int Max (int a, int b) {  
    if (a > b)
        return a;
    else 
        return b; 
} 
int hauteur (ABR*arbre){
    if(!arbre) 
        return 0; 
    else if (arbre->fg==NULL && arbre->fd==NULL) 
        return 1; 
    else 
        return (1+ Max(hauteur(arbre->fg), hauteur(arbre->fd))); 
} 

//fonction 9 : calculer le total de noeuds dans un arbre
int Nb_noeud (ABR *T){
    if (T==NULL) 
        return 0;
    return (1+ Nb_noeud(T->fd) + Nb_noeud(T->fg));
}

//fonction 10 : calculer le nombre de feuilles dans un arbre 
int Nb_feuilles (ABR *T){
    if (T==NULL){
        return 0;
    }
    if (T->fg==NULL && T->fd==NULL){
        return 1;
    }
    return(Nb_feuilles(T->fd) + Nb_feuilles(T->fg));
}

//fonction 11 : liberer un arbre
void Liber_Arbre(ABR **T) {
    if (*T != NULL) {              
        Liber_Arbre(&((*T)->fg));  
        Liber_Arbre(&((*T)->fd));  
        free(*T);                 
        *T = NULL;                 
    }
}


int main (){

    return 0 ;
}