#include"a10.h"
void solve(double *a, int m, int n, int k, double *b, double *c){
    int i;
    int j;
    int l;
    double s;
    double *pi;
    double *pj;
    for(i=0;i<m;i++){
        pi=a+i*n;
        for(l=0;l<k;l++){
            pj=b+l;
         for(j=0;j<n;j++){
           s+=pi[j]*pj[k*j];
         }
          c[i*k+l]=s;
          s=0;
        }


    }
}
