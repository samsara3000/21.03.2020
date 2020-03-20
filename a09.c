#include"a09.h"
void solve(double *a, int m, int n, double *b, double *c){
    double *pi;
    double s=0;
    int i;
    int j;
    for(i=0;i<m;i++){
        pi=a+i*n;
        for(j=0;j<n;j++){
           s+=pi[j]*b[j];
        }
        c[i]=s;
        s=0;
    }
}
