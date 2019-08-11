#include<bits/stdc++.h>
using namespace std;
int n,m,a[50],l;
bool f[50];

void dfs(int k){
    if (k==m+1){
        for (int i=1;i<=l;++i) printf("%d ",a[i]);
        printf("\n");
        return;
    }
    for (int i=a[l]+1;i<=n;++i)
    if (!f[i]){
        f[i]=1;
        l++; a[l]=i;
        dfs(k+1);
        f[i]=0;
        l--;
    }
}

int main(){
    scanf("%d%d",&n,&m);
    dfs(1);
    return 0;
}