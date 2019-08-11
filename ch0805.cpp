#include<bits/stdc++.h>
using namespace std;
int t,n,s[200005],e[200005],d[200005];
long long l,mid,r;
int main(){
    scanf("%d",&t);
    while (t--){
        scanf("%d",&n);
        for (int i=1;i<=n;++i) scanf("%d%d%d",&s[i],&e[i],&d[i]);
        l=0; r=INT_MAX;
        while (l<r){
            mid=(l+r)>>1;
            int tot=0;
            for (int i=1;i<=n;++i)
            if (mid>=s[i]){
                if (mid<e[i]) tot+=(mid-s[i])/d[i]+1;
                else tot+=(e[i]-s[i])/d[i]+1;
            }
            if (tot&1) r=mid;
                else l=mid+1;
        }
        int ans=0;
        for (int i=1;i<=n;++i)
            if (l>=s[i] && l<=e[i] && (l-s[i])%d[i]==0) ans++;
        if (ans&1) printf("%lld %d\n",l,ans);
            else printf("There's no weakness.\n");
    }
    return 0;
}