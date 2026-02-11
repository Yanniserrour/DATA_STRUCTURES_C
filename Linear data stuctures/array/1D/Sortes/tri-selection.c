#include <stdio.h>

/*
complexité : 
meilleurs cas: O(n^2)
pire cas  :    O(n^2)
*/
void tri_selection(int V[], int max){
    int i,j,min,x ; 
    for (i=0; i<max-1; i++){
        min=i; 
        for (j=i+1; j<max; j++){
            if (V[j]<V[min]){
                min=j;
            }
        }
        if (min!=i){
            x=V[i];
            V[i]=V[min];
            V[min]=x;
        }
    }
}

void remplire(int V[], int max){
    int i ; 
    for (i=0; i<max; i++){
        printf("veuillez entrer l'element numero %d : ", i+1);
        scanf("%d",&V[i],"\n");
    }
}
void afficher (int V[], int max){
    int i ; 
    for (i=0; i<max; i++){
        printf("%d ",V[i]);
    }
}
int main (){
    int T[100], n ; 

    printf("veuillez entrer la taille du vecteurs : "); 
    scanf("%d",&n);

    remplire(T,n);
    printf("le vecteur avent le tri: ");
    afficher(T,n);
    printf("\n");
    printf("le vecteur apres le tri: ");
    tri_selection(T,n);
    afficher(T,n);


    return 0;
}