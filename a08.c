#include"a08.h"
void solve(double *a, int m, int n, int i, int j, int b){
    double *pi=a+i*n;
    double *pj=a+j*n;
    int l;
    int ind=0;
    (void)m;
    if(b==0){
        ind=1;
    }
    if(ind==0){
        for(l=0;l<n;l++){
            pj[l]+=b*pi[l];
        }
    }
}
