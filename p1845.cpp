#include<bits/stdc++.h>
using namespace std;
int n,i,j,cnt,ans[5000000],m,f[1001][1001],qx[1000000],qy[1000000];
int fx[4]={1,0,-1,0},fy[4]={0,1,0,-1};
char s[1001][1005];

void bfs(int x,int y){
    int h=0,t=1,dep[1001][1001];
    qx[t]=x; qy[t]=y; dep[x][y]=1;
    while (h<t){
        h++; int i=qx[h],j=qy[h];
        f[i][j]=0;
        for (int k=0;k<4;++k){
            int tx=i+fx[k],ty=j+fy[k];
            if (tx>0 && tx<=n && ty>0 && ty<=n && f[tx][ty]){
                f[tx][ty]=0;
                t++; qx[t]=tx; qy[t]=ty;
                dep[tx][ty]=dep[i][j]+1;
            }
        }
    }
    m++; ans[m]=dep[qx[t]][qy[t]];
}

int main(){
    scanf("%d",&n);
    for (i=1;i<=n;++i)
        scanf("%s",s[i]);
    for (i=1;i<=n;++i)
        for (j=0;j<n;++j)
        f[i][j+1]=s[i][j]-'0';
    for (i=1;i<=n;++i)
        for (j=1;j<=n;++j)
        if (f[i][j]){
            cnt++;
            bfs(i,j);
        }
    sort(ans+1,ans+1+m);
    printf("%d\n",cnt);
    for (i=1;i<=m;++i) printf("%d\n",ans[i]);
    return 0;
}