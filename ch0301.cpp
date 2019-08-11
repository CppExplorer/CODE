#include<bits/stdc++.h>
using namespace std;
int n,m,a[20];

void dfs(int x){
    if (x==n+1){
        for (int i=1;i<=m;++i) printf("%d ",a[i]);
        printf("\n");
        return;
    }
    dfs(x+1);
    m++; a[m]=x;
    dfs(x+1);
    m--;
}

int main(){
    scanf("%d",&n);
    dfs(1);
    return 0;
}