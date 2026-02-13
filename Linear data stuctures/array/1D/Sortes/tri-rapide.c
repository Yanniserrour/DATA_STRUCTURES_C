#include <stdio.h>
#include <stdlib.h>

/*
complexité:
pire     : O(n^2)
moyenne  : O(n.log(n))
meilleurs: O(n.log(n))
*/

int choix_pivot(int* T, int P, int D){
    int indice_pivot; 
    int mil ;

    //1.chercher le pivot en utilisant la médiane de 3 
    mil = (P+D) / 2 ;
    if       ( ( (T[P]>T[mil]) && (T[mil]>T[D]) ) || ( (T[P]<T[mil]) && (T[mil]<T[D])) ){
        indice_pivot = mil;

    }else if ( ( (T[mil]>T[P]) && (T[P]>T[D]) )   || ( (T[mil]<T[P]) && (T[P]<T[D]) ) ){
        indice_pivot = P;

    }else if ( ( (T[mil]>T[D]) && (T[D]>T[P]) )   || ( (T[mil]<T[D]) && (T[D]<T[P]) ) ){
        indice_pivot = D;
    }

    return indice_pivot;
}



int partitionner(int* T, int P, int D, int indice_pivot){
    int i , j, temp ;

    //1.Placer le pivot a la fin du tableau 
    temp = T[indice_pivot]; 
    T[indice_pivot] = T[D]; 
    T[D] = temp; 
    indice_pivot = D;

    //2.trier le vecteur sans le pivot 
    j=P;
    for (i=P; i<D; i++){
        if (T[i]<T[indice_pivot]){
            temp = T[i];
            T[i] = T[j];
            T[j] = temp;
            j++;
        }
    }

    //3.remetre le pivot a sa place définitive 
    temp = T[indice_pivot];
    T[indice_pivot] = T[j];
    T[j] = temp;

    //4.retourner l'indice du pivot apres le tri
    return j ;

}


void Tri_rapide(int* T, int premier, int dernier){
    int pivot;
    int pivot_en_place;

    if (premier < dernier) {
        pivot = choix_pivot(T, premier, dernier);
        pivot_en_place = partitionner(T, premier, dernier, pivot);

        Tri_rapide(T, premier, pivot_en_place-1);
        Tri_rapide(T, pivot_en_place +1, dernier);
    }

}



