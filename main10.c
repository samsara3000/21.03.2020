#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"matrix.h"
#include"a10.h"
int main(int argc, char *argv[]){
    int n;
    int m;
    int k;
    int ret;
    double *a;
    double *b;
    double *c;
    double t;
    char *name1=0;
    char *name2=0;
    if((argc==4)||(argc==6)){
        switch (argc) {
        case 6:
            if(((sscanf(argv[1],"%d", &m))==1)&&(sscanf(argv[2],"%d", &n)==1)&&(sscanf(argv[3],"%d",&k))){
                name1=argv[4];
                name2=argv[5];
            }
            else{
                fprintf(stderr,"Usage: %s [m] [n] [k] [file1] [file2] \n", argv[0]);
                return 2;
            }
            break;
        case 4:
            if(((sscanf(argv[1],"%d", &m))==1)&&(sscanf(argv[2],"%d", &n)==1)&&(sscanf(argv[3],"%d",&k))){
               name1=0;
               name2=0;
            }
            else{
                fprintf(stderr, "Usage: %s [m] [n] [k]\n", argv[0]);
                return 2;
            }
            break;
        }
    }
    else{
        fprintf(stderr, "Usage: %s [m] [n] [k]\n", argv[0]);
        return 2;
    }
        if(!(a=(double*)malloc(m*n*sizeof(double)))){
        printf("Not enough memory!\n");
        return 2;
    }
        if(!(b=(double*)malloc(n*k*sizeof(double)))){
            printf("Not enough memory!\n");
            free(a);
            return 2;
        }
        if(!(c=(double*)malloc(m*k*sizeof(double)))){
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
    else initMatrix(b,n,k);
    printMatrix(a,m,n);
    printf("\n");
    printMatrix(b,n,k);
    printf("\n");
    t=clock();
    solve(a,m,n,k,b,c);
    t=clock()-t;
    printMatrix(c,m,k);
    printf("Ellapsed=%.2lf\n",t/CLOCKS_PER_SEC);
    free(a);
    free(b);
    free(c);
    return 0;
}
