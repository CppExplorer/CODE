#include<cstdio>
#include<iostream>
using namespace std;
int n,f,i,a[100005];
double l,r,mid,b[100005],sum[100005];
int main(){
    scanf("%d%d",&n,&f);
    for (i=1;i<=n;++i) scanf("%d",&a[i]);
    l=-1e6; r=1e6;
    while (r-l>1e-5){
        mid=(l+r)/2;
        for (i=1;i<=n;++i) b[i]=a[i]-mid;
        for (i=1;i<=n;++i) sum[i]=sum[i-1]+b[i];
        double ans=-1e10,minv=1e10;
        for (i=f;i<=n;++i){
            minv=min(minv,sum[i-f]);
            ans=max(ans,sum[i]-minv);
        }
        if (ans>=0) l=mid;
            else r=mid;
    }
    printf("%d",int(r*1000));
    return 0;
}