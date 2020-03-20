#include"a01.h"
#include"matrix.h"
int Symmetra(double *a, int m, int n){
    int i,j;
    double *pi;
    double *pj;
    (void)m;
    double sj=0,si=0;
    for(i=0;i<n-1;i++){
        j=i+1;
        pi=a+i*n+j;
        pj=a+j*n+i;
        for(j=0;j<n-i-1;j++){
            si=pi[j];
            sj=pj[j*n];
            if(!(si>=sj && si<=sj)){
                return 0;
            }
        }
    }
    return 1;
}
