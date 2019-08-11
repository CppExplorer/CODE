#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int n,m,a[N],sum[N],h=1,t,q[N],ans;
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i) scanf("%d",&a[i]);
    ans=a[1];
    for (int i=1;i<=n;++i) sum[i]=sum[i-1]+a[i];
    for (int i=1;i<=n;++i){
        while (h<=t && i-q[h]>m) h++;
        while (h<=t && sum[q[t]]>=sum[i]) t--;
        q[++t]=i;
        if (i>1) ans=max(ans,sum[i]-sum[q[h]]);
    }
    printf("%d",ans);
    return 0;
}