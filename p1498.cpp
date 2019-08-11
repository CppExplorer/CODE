#include<bits/stdc++.h>
using namespace std;
int n,edge[11],a[1025][2049];

void dfs(int x,int y,int n){
    if (n==1){
        a[x][y]=a[x-1][y+1]=1;
        a[x][y+3]=a[x-1][y+2]=2;
        a[x][y+1]=a[x][y+2]=3;
        return;
    }
    int e=edge[n-1];
    dfs(x,y,n-1);
    dfs(x,y+2*e,n-1);
    dfs(x-e,y+e,n-1);
}

void print(int n){
    dfs(edge[n],1,n);
    for (int i=1;i<=edge[n];++i){
        for (int j=1;j<=2*edge[n];++j){
            if (!a[i][j]) printf(" ");
            if (a[i][j]==1) printf("/");
            if (a[i][j]==2) printf("\\");
            if (a[i][j]==3) printf("_");
        }
        printf("\n");
    }
}

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;++i) edge[i]=1<<i;
    print(n);
    return 0;
}