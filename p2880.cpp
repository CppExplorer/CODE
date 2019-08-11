#include<bits/stdc++.h>
using namespace std;
int n,q,l,r,mx[50005][20],mn[50005][20],a[50005];

void RMQ(){
    for (int i=1;i<=n;++i){
        mx[i][0]=a[i]; mn[i][0]=a[i];
    }
    int t=log(n)/log(2)+1;
    for (int j=1;j<t;++j)
        for (int i=1;i<=n-(1<<j)+1;++i){
            mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
            mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
        }
}

int ask(int l,int r){
    int k=log(r-l+1)/log(2);
    int maxn=max(mx[l][k],mx[r-(1<<k)+1][k]);
    int minn=min(mn[l][k],mn[r-(1<<k)+1][k]);
    return maxn-minn;
}

int main(){
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;++i) scanf("%d",&a[i]);
    RMQ();
    for (int i=1;i<=q;++i){
        scanf("%d%d",&l,&r);
        printf("%d\n",ask(l,r));
    }
    return 0;
}