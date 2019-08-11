#include<bits/stdc++.h>
using namespace std;
long long n,m,t,b[100005],c[100005],sum[100005];

long long calc(long long a[100005],long long n){
    for (int i=1;i<=n;++i){
        a[i]-=a[0]/n;
        sum[i]=sum[i-1]+a[i];
    }
    sort(sum+1,sum+1+n);
    long long ans=0;
    for (int i=1;i<=n;++i) ans+=abs(sum[i]-sum[(n+1)>>1]);
    return ans;
}

int main(){
    scanf("%lld%lld%lld",&n,&m,&t);
    for (int i=1;i<=t;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        b[x]++; c[y]++;
    }
    for (int i=1;i<=n;++i) b[0]+=b[i];
    for (int i=1;i<=m;++i) c[0]+=c[i];
    if (b[0]%n==0 && c[0]%m==0) printf("both %lld",calc(b,n)+calc(c,m));
    else if (b[0]%n==0) printf("row %lld",calc(b,n));
    else if (c[0]%m==0) printf("column %lld",calc(c,m));
    else printf("impossible");
    return 0;
}