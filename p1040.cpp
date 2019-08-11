#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,i,root[35][35],f[35][35];

ll dp(int l,int r){
    if (l>r) return 1;
    if (f[l][r]>-1) return f[l][r];
    for (int k=l;k<=r;++k){
        ll tmp=dp(l,k-1)*dp(k+1,r)+f[k][k];
        if (tmp>f[l][r]){
            f[l][r]=tmp;
            root[l][r]=k;
        }
    }
    return f[l][r];
}

void dfs(int l,int r){
    if (l>r) return;
    printf("%d ",root[l][r]);
    dfs(l,root[l][r]-1);
    dfs(root[l][r]+1,r);
}

int main(){
    scanf("%d",&n);
    memset(f,-1,sizeof f);
    for (i=1;i<=n;++i){
        scanf("%d",&f[i][i]);
        root[i][i]=i;
    }
    printf("%lld\n",dp(1,n));
    dfs(1,n);
    return 0;
}