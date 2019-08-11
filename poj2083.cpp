#include<iostream>
#include<cstdio>
using namespace std;
int n,edge[8];
bool a[2500][2500];

void dfs(int n,int x,int y){
    if (n==1){
        a[x][y]=1;
        return;
    }
    int e=edge[n-1];
    dfs(n-1,x,y);
    dfs(n-1,x+e,y+e);
    dfs(n-1,x+e*2,y);
    dfs(n-1,x,y+e*2);
    dfs(n-1,x+e*2,y+e*2);
}

void print(int n){
    dfs(n,1,1);
    for (int i=1;i<=edge[n];++i){
        for (int j=1;j<=edge[n];++j) 
        if (a[i][j]) printf("X");
            else printf(" ");
        printf("\n");
    }
    printf("-\n");
}

int main(){
    edge[1]=1;
    for (int i=2;i<=7;++i) edge[i]=edge[i-1]*3;
    scanf("%d",&n);
    while (n!=-1){
        print(n);
        scanf("%d",&n);
    }
    return 0;
}