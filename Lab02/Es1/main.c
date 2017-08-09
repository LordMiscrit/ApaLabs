//
// Created by Pc on 02/08/2017.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50
void stampa_vettore(int *v,int N);
void stampa_matrice(int n_righe,int n_colonne,int mat[][n_colonne]);

void ruotaVettore(int V[], int dir, int N, int P);
void ruotaMatrice(int dim1,int dim2,int M[][dim2], char r_o_c, int target, int P, int dir);

int main(){
    int matrice[][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int n_righe=3,n_colonne=4;
    int fine=0;

    char input[MAX+1],comando[MAX];
    int target,direzione,posizioni;

    while(!fine){
        stampa_matrice(n_righe,n_colonne,matrice);
        printf("cosa vuoi muovere?\nformato:[riga,colonna,fine] target[n° di riga o colonna] direzione[0=sinistra/su, 1=destra/giù] n° di posizioni:\n> ");
        gets(input);
        sscanf(input,"%s %d %d %d",comando,target,direzione,posizioni);
        if(!strcmp(comando,"fine")){
            fine=1;
        }
        else{
            if(!strcmp(comando,"riga")){
                if(direzione!=0 && direzione!=1)
                    printf("direzione errata, inserire 0 o 1\n");
                else{
                    if(target>=0 && target<n_righe){
                        ruotaMatrice(n_righe,n_colonne,matrice,'r',target,posizioni,direzione);
                    }
                    else
                        printf("riga inesistente\n");
                }
            }
            else if(!strcmp(comando,"colonna")){
                if(direzione!=0 && direzione!=1)
                    printf("direzione errata, inserire 0 o 1\n");
                else{
                    if(target>=0 && target<n_colonne){
                        ruotaMatrice(n_righe,n_colonne,matrice,'c',target,posizioni,direzione);
                    } else
                        printf("colonna inesistente\n");
                }
            }
            else
                printf("comando sconosciuto\n");

        }


    }


    return 0;
}



void stampa_vettore(int *v,int N){
    for (int i = 0; i < N; ++i)
        printf("[%d]",v[i]);
    printf("\n");
}

void stampa_matrice(int n_righe,int n_colonne,int mat[][n_colonne]){
    for (int i = 0; i < n_righe; ++i) {
        stampa_vettore(mat[i],n_colonne);
    }
}

void ruotaVettore(int V[], int dir, int N, int P){
    int *vett2=malloc(N* sizeof(int));
    int i,j;
    switch (dir){
        case 1:
            for(i=0, j=N-P;i<N;i++,j=(j+1)%N){
                vett2[i]=V[j];
            }
            break;
        case 0:
            for(i=0, j=P;i<N;i++,j=(j+1)%N){
                vett2[i]=V[j];
            }
            break;
        default: break;
    }
    for (int i = 0; i < N; ++i)
        V[i]=vett2[i];
    free(vett2);
}

void ruotaMatrice(int dim1,int dim2,int M[][dim2], char r_o_c, int target, int P, int dir){
    int *vett;
    switch(r_o_c){
        case 'c':
            vett=malloc(dim1* sizeof(int));
            for (int i = 0; i < dim1; ++i)
                vett[i]=M[i][target];
                ruotaVettore(vett,dir,dim1,P);
            for (int i = 0; i < dim1; ++i)
                M[i][target]=vett[i];
            free(vett);
            break;
        case 'r':
                ruotaVettore(M[target],dir,dim2,P);
            break;
        default:
            break;
    }
}