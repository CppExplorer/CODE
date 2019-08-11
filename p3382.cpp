#include<bits/stdc++.h>
using namespace std;
int n;
double l,r,lmid,rmid,a[14];

double calc(double x){
    double ans=0;
    for (int i=1;i<=n+1;++i) 
        ans+=a[i]*pow(x,n-i+1);
    return ans;
}

int main(){
    scanf("%d%lf%lf",&n,&l,&r);
    for (int i=1;i<=n+1;++i) scanf("%lf",&a[i]);
    while (r-l>1e-9){
        lmid=(2*l+r)/3;
        rmid=(2*r+l)/3;
        double rl=calc(lmid),rr=calc(rmid);
        if (rl<rr) l=lmid;
            else r=rmid;
    }
    printf("%.5lf",l);
    return 0;
}