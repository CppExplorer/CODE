#include<bits/stdc++.h>
using namespace std;
int n,m,h,t,i,j,cnt,fx[4]={1,0,-1,0},fy[4]={0,1,0,-1};
int f[1005][1005],qx[1000005],qy[1000005],a[1005][1005],step[1000005];
char ch;

void bfs(int sx,int sy){
    cnt++; h=0; t=1; 
    f[sx][sy]=cnt; 
    step[cnt]=1; 
    qx[t]=sx; qy[t]=sy;
    while (h<t){
        h++; int x=qx[h],y=qy[h];
        for (int i=0;i<4;++i){
            int tx=x+fx[i],ty=y+fy[i];
            if (tx<1 || tx>n || ty<1 || ty>n || f[tx][ty] || a[tx][ty]==a[x][y]) continue;
            t++; qx[t]=tx; qy[t]=ty;
            f[tx][ty]=cnt; step[cnt]++;
        }
    }
    printf("%d\n",step[f[sx][sy]]);
}

int main(){
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;++i)
        for (j=1;j<=n;++j){
            cin>>ch;
            if (ch=='1') a[i][j]=1;
                else a[i][j]=0;
        }
    int x,y;
    for (i=1;i<=m;++i){
        scanf("%d%d",&x,&y);
        if (!f[x][y]) bfs(x,y);
            else printf("%d\n",step[f[x][y]]);
    }
    return 0;
}