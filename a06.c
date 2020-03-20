#include"a06.h"
void solve(double *a, int m, int n, int i, int j){
    int l=0;
    
    double temp;
    double *pi=a+i*n;
    double *pj=a+j*n;
    (void)m;
    for(l=0;l<n;l++){
        temp=pi[l];
        pi[l]=pj[l];
        pj[l]=temp;
    }
}
