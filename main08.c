#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"matrix.h"
#include"a08.h"
int main(int argc, char *argv[]){
    int n;
    int m;
    int i,j,b;
    double *a;
    double t;
    char *name=0;
    if((argc==7)||(argc==6)){
        switch (argc) {
        case 7:
            if(((sscanf(argv[1],"%d", &m))==1)&&((sscanf(argv[2],"%d", &n))==1)&&((sscanf(argv[3],"%d", &i))==1)&&(sscanf(argv[4],"%d", &j)==1) && (((sscanf(argv[5],"%d", &b))==1))){
                name=argv[6];
            }
            else{
                fprintf(stderr,"Usage: %s [m] [n] [i] [j] [b] [file]\n", argv[0]);
                return 2;
            }
            break;
        case 6:
            if (((sscanf(argv[1],"%d", &m))==1)&&((sscanf(argv[2],"%d", &n))==1)&&(sscanf(argv[3],"%d", &i))&&(sscanf(argv[4],"%d", &j))&& (((sscanf(argv[5],"%d", &b))==1))){
                name=0;
            }
            else{
                fprintf(stderr, "Usage: %s [m] [n] [i] [j] [b] \n", argv[0]);
                return 2;
            }
            break;
        }
    }
    else{
        fprintf(stderr, "Usage: %s [m] [n] [i] [j] [b] \n", argv[0]);
        return 2;
    }
        if(!(a=(double*)malloc(m*n*sizeof(double)))){
        printf("Not enough memory!\n");
        return 2;
    }
    if(name){
        int ret;
        ret=readMatrix(a,m,n,name);
        if(ret!=SUCCESS){
            switch (ret) {
            case ERROR_OPEN:
                printf("Can't open %s\n",name);
                break;


          case ERROR_READ:
                printf("Can't read %s\n",name);
                break;
            default:
                printf("Unknown error\n");
                break;
            }
            free(a);
            return 3;
        }
    }
    else initMatrix(a,m,n);
    if((i>=n) || (j>=n)){
        printf("Uncorrect i,j\n");
        return 2;
    }
    printMatrix(a,m,n);
    printf("\n");
    t=clock();
    solve(a,m,n,i,j,b);
    t=clock()-t;
    printMatrix(a,m,n);
    printf("Ellapsed=%.2lf\n",t/CLOCKS_PER_SEC);
    free(a);
    return 0;
}
