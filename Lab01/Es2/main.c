//
// Created by Pc on 02/08/2017.
//

#include <stdio.h>
#include <stdlib.h>
#define N 20

int main() {
    char filename[11];
    int MATRICE[N][N];
    int n,i,j,layer=0;
    FILE *fp;
    printf("Nome file: ");
    scanf("%s",filename);

    if((fp=fopen(filename,"r"))==NULL) {
        printf("Impassible to open file %s.\n", filename);
        exit(EXIT_FAILURE);
    }
    fscanf(fp,"%d\n",&n);


    for(i=0;i<n;i++){
        for (j= 0; j < n; j++){
            fscanf(fp,"%d",&MATRICE[i][j]);
        }
    }

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            printf("%d ",MATRICE[i][j]);
        }
        printf("\n");
    }

    printf("\n\nvalori: ");

    for(layer=0;layer<n;layer++){
        //to right
        for(i=j=layer;j<n-layer;j++)
            printf("%d ",MATRICE[i][j]);
        j--;

        //to bottom
        for(i=layer+1;i<n-layer;i++)
            printf("%d ",MATRICE[i][j]);
        i--;

        //to left
        for (j--;j>=layer;j--)
            printf("%d ",MATRICE[i][j]);
        j++;

        //to up
        for(i--;i>layer;i--)
            printf("%d ",MATRICE[i][j]);
    }


    return 0;
}