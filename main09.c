#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"matrix.h"
#include"a09.h"
int main(int argc, char *argv[]){
    int n;
    int m;
    int ret;
    double *a;
    double *b;
    double *c;
    double t;
    char *name1=0;
    char *name2=0;
    if((argc==3)||(argc==5)){
        switch (argc) {
        case 5:
            if(((sscanf(argv[1],"%d", &m))==1)&&(sscanf(argv[2],"%d", &n)==1)){
                name1=argv[3];
                name2=argv[4];
            }
            else{
                fprintf(stderr,"Usage: %s [m] [n] [file1] [file2] \n", argv[0]);
                return 2;
            }
            break;
        case 3:
            if(((sscanf(argv[1],"%d", &m))==1)&&(sscanf(argv[2],"%d", &n)==1)){
               name1=0;
               name2=0;
            }
            else{
                fprintf(stderr, "Usage: %s [m] [n]\n", argv[0]);
                return 2;
            }
            break;
        }
    }
    else{
        fprintf(stderr, "Usage: %s [m] [n]\n", argv[0]);
        return 2;
    }
        if(!(a=(double*)malloc(m*n*sizeof(double)))){
        printf("Not enough memory!\n");
        return 2;
    }
        if(!(b=(double*)malloc(n*sizeof(double)))){
            printf("Not enough memory!\n");
            free(a);
            return 2;
        }
        if(!(c=(double*)malloc(m*sizeof(double)))){
            printf("Not enough memory!\n");
            free(a);
            free(b);
            return 2;
        }
    if(name1){
        ret=readMatrix(a,m,n,name1);
        if(ret!=SUCCESS){
            switch (ret) {
            case ERROR_OPEN:
                printf("Can't open %s\n",name1);
                break;


          case ERROR_READ:
                printf("Can't read %s\n",name1);
                break;
            default:
                printf("Unknown error\n");
                break;
            }
            free(a);
            free(b);
            free(c);
            return 3;
        }
    }
    else initMatrix(a,m,n);
    if(name2){
        ret=readMatrix(b,1,n,name2);
        if(ret!=SUCCESS){
            switch (ret) {
            case ERROR_OPEN:
                printf("Can't open %s\n",name2);
                break;


          case ERROR_READ:
                printf("Can't read %s\n",name2);
                break;
            default:
                printf("Unknown error\n");
                break;
            }
            free(a);
            free(b);
            free(c);
            return 3;
        }
    }
    else initMatrix(b,1,n);
    printMatrix(a,m,n);
    printf("\n");
    printMatrix(b,1,n);
    printf("\n");
    t=clock();
    solve(a,m,n,b,c);
    t=clock()-t;
    printMatrix(c,1,m);
    printf("Ellapsed=%.2lf\n",t/CLOCKS_PER_SEC);
    free(a);
    free(b);
    free(c);
    return 0;
}
