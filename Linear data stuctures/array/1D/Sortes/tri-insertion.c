#include <stdio.h>

/*complexité : 
meilleurs cas : O(n)
pire cas : O(n^2)
*/
void tri_insertion (int v[], int n){
    int x , j , i ;
    for (i=1; i<n; i++){
        x=v[i];
        j=i;
        while ((j>0) && (v[j-1]>x)){
            v[j]=v[j-1];
            j--;
        }   
        v[j]=x;
    }

}

void tri_insertion_volee (int v[], int n){
    int x , i , j; 
    for (i=0; i<n; i++){
        printf("veuiller entrer la valeur numero %d : ",i+1);
        scanf("%d",&x);
        j=i;
        while ((j>0) && (v[j-1]>x)){
            v[j]=v[j-1];
            j--;
        }
        v[j]=x;
    }
}

void afficher (int t[], int max){
    int k; 
    for (k=0; k<max; k++){
        printf("%d ",t[k]);
    }
}

int main (){
    int i , x , j , temp ;
    int t[100], max;


    printf("veuillez entrer la taille du vecteur: ");
    scanf("%d",&max);


    tri_insertion (t,max);
    printf("le vecteur trier est : ");
    afficher (t,max);



    return 0;
}