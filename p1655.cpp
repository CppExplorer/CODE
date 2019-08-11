#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int f[105][105][1000],n,m,c[1000],t[1000];

void add(int x,int y){
    f[x+1][y+1][0]=max(f[x][y][0],c[0])+3;
    for (int i=1;i<=f[x+1][y+1][0];++i){
        f[x+1][y+1][i]+=f[x][y][i]+c[i];
        f[x+1][y+1][i+1]+=f[x+1][y+1][i]/10;
        f[x+1][y+1][i]%=10;
    }
    while (f[x+1][y+1][0]>1 && !f[x+1][y+1][f[x+1][y+1][0]]) f[x+1][y+1][0]--;
}

void mul(int x,int y,int val){
    memset(c,0,sizeof c);
    memset(t,0,sizeof t);
    for (int i=f[x][y][0];i>=0;--i) c[i]=f[x][y][i];
    c[0]=f[x][y][0]+5;
    for (int i=1;i<=c[0];++i){
        c[i]=c[i]*val+t[i];
        t[i+1]+=c[i]/10;
        c[i]%=10;
    }
    while (c[0]>1 && !c[c[0]]) c[0]--;
}

int main(){
    for (int i=1;i<=100;++i)
        f[i][1][0]=1,f[i][1][1]=1;
    for (int i=2;i<=100;++i)
        for (int j=2;j<=i;++j){
            mul(i-1,j,j);
            add(i-1,j-1);
        }
    while (scanf("%d%d",&n,&m)==2){
        if (n<m) printf("0");
        else for (int i=f[n][m][0];i;--i) printf("%d",f[n][m][i]);
        printf("\n");
    }
    return 0;
}