#include <stdio.h>
#include <stdlib.h>

/*complexité : 
meilleur, moyen, pire : O(n.log2(n))
*/

//algorithme 1 :
void fusion (int* T , int P, int Q, int R) {
    // initialisation des variables 
    int ng = Q - P + 1 ;
    int nd = R - Q;
    int i, j, k, t ;
    int G [ng];
    int D [nd];

    // remplir la partie gauche 
    j = P; 
    for (i=0; i<ng; i++){
        G[i] = T[j];
        j++;
    }

    //remplir la partie droite
    j = Q+1; 
    for (i=0; i<nd; i++){
        D[i] = T[j];
        j++;
    }
    
    i = 0; 
    j = 0; 
    k = P; 

    //trier les vecteurs 
    while( (i<ng) && (j<nd) ){
        if (G[i] <= D[j]){
            T[k] = G[i]; 
            i++;
        }else{
            T[k] = D[j]; 
            j++;
        }
        k++;
    }

    //remplir le reste (si il reste)
    while (i<ng){
        T[k] = G[i];
        i++;
        k++;
    }
    while (j<nd){
        T[k] = D[j];
        j++;
        k++;
    }
}

void Tri_fusion(int *T, int g , int d){
    if (g<d){
        int mil = g + (d-g) / 2;
        Tri_fusion(T,g,mil);
        Tri_fusion(T,mil+1,d); 
        fusion(T, g, mil,d);
    }
}



//algorithme 2: 
void fusion_2(int* T, int P, int Q, int R){
    //déclaration
    int i, j, i1, i2 ; 
    int N = R - P + 1;
    int temp[N];

    i  = 0;  //début du vecteur temp 
    i1 = P;  //début du premier SV
    i2 = Q+1;//début du deuxieme SV

    //trier dans le vecteur temp
    while( (i1<=Q) && (i2<=R) ){
        if(T[i1] <= T[i2]){
            temp[i] = T[i1];
            i1++;
        }else {
            temp[i] = T[i2];
            i2++;
        }
        i++;
    }

    //remplir le rest dans temp 
    while(i1<=Q){
        temp[i] = T[i1];
        i++;
        i1++;
    }
    while(i2<=R){
        temp[i] = T[i2];
        i++; 
        i2++;
    }

    //déplacer le vecteur temp dans T
    i = 0;
    for (j=P; j<=R; j++){
        T[j] = temp[i]; 
        i++; 
    }
}

void Tri_fusion_2(int* T, int g, int d){
    if (g<d){
        int mil = (g+d)/2;
        Tri_fusion_2(T, g, mil);
        Tri_fusion_2(T, mil+1, d);
        fusion_2(T, g, mil, d);
    }
}

int main (){
//programme 
    return 0;
}