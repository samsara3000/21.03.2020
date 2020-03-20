#include"a07.h"
void solve(double *a, int m, int n, int i, int j){
    double *pi=a+i;
    double *pj=a+j;
    double temp;
    int l;
    for(l=0;l<m;l++){
        temp=pi[l*n];
        pi[l*n]=pj[l*n];
        pj[l*n]=temp;
       }
}
