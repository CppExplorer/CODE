#include<bits/stdc++.h>
using namespace std;
int n,a[10],m;
bool f[10];

void dfs(int k){
    if (k==n+1){
        for (int i=1;i<=m;++i) printf("%d ",a[i]);
        printf("\n");
        return;
    }
    for (int i=1;i<=n;++i)
    if (!f[i]){
        f[i]=1;
        m++; a[m]=i;
        dfs(k+1);
        f[i]=0; 
        m--;
    }
}

int main(){
    scanf("%d",&n);
    dfs(1);
    return 0;
}