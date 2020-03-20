#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"matrix.h"
#include"a05.h"
int main(int argc, char *argv[]){
    int n;
    double *a;
    double t;
    char *name=0;
    //матрица m*n
    if(!(argc==2 || argc==3)||(n=atoi(argv[1]))<=0){
        printf("Usage: %s n <file>\n",argv[0]);
        return 1;
    }
    n=atoi(argv[1]);
    if(argc==3) name=argv[2];
    if(!(a=(double*)malloc(n*n*sizeof(double)))){
        printf("Not enough memory!\n");
        return 2;
    }
    if(name){
        int ret;
        ret=readMatrix(a,n,n,name);
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
    else initMatrix(a,n,n);
    printMatrix(a,n,n);
    t=clock();
    swap(a,n);
    t=clock()-t;
    printMatrix(a,n,n);
    printf("Ellapsed=%.2lf\n",t/CLOCKS_PER_SEC);
    free(a);
    return 0;
}
