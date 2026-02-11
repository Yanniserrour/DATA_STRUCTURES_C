#include <stdio.h>

/*complexité : 
meilleurs cas : O(n^2) 
pire cas : O(n^2)
*/
void tri_bulle (int v[], int max){
    int k , l , temp;
    for (k=(max-1); k>=1; k--){
        for (l=0; l<=(k-1); l++){
            if (v[l+1]<v[l]){
                temp = v[l+1];
                v[l+1] = v[l]; 
                v[l] = temp;
            }
        }
    }
}

/*complexité : 
meilleurs cas : O(n) 
pire cas : O(n^2)
*/
void tri_bulle_optimiser (int v[], int max){
    int l , temp, control;
    control = 0;
    while(control==0){
        control = 1 ;
        for (l=0; l<max - 1; l++){
            if (v[l+1]<v[l]){
                temp = v[l+1];
                v[l+1] = v[l]; 
                v[l] = temp;
                control = 0 ; 
            }
        }
        max=max-1;
    }
}

void afficher (int v[], int max){
    int k; 
    for (k=0; k<max; k++){
        printf("%d ",v[k]);
    }
}

int main (){
    int i, T[100],n ;


    printf("entrer la taille du vecteurs : ");
    scanf("%d",&n);

    for (i=0; i<n; i++){
        printf("entrer l'element numero %d : ",(i+1));
        scanf("%d",&T[i],"\n");
    }

    //afficher le vecteur avent le tri 
    printf("le vecteurs avent le tri : ");
    afficher(T,n);
    printf("\n");


    //trier le vecteurs 
    tri_bulle(T,n);

    //afficher le vecteur apres le tri
    printf("le vecteurs apres le tri : ");
    afficher(T,n);

    return 0;
}