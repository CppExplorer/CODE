#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,qx[1000000],qy[1000000],h,t,sx,sy,ex,ey,fi,fj,cnt[1000005],a[305][305];
int fx[4]={1,0,-1,0},fy[4]={0,1,0,-1};
char ch;
bool vis[305][305];

void find(int x,int y){
    fi=0; fj=0;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
        if (a[i][j]==a[x][y] && (i!=x || j!=y)){
            fi=i; fj=j;
            return;
        }
}
int main(){
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;++i)
        for (j=1;j<=m;++j){
            cin>>ch;
            if (ch=='.') a[i][j]=1;
            if (ch=='='){
                a[i][j]=1;
                ex=i; ey=j;
            }
            if (ch=='@'){
                a[i][j]=1;
                sx=i; sy=j;
            }
            if (ch>='A' && ch<='Z') a[i][j]=ch;
        }
    h=0; t=1; qx[t]=sx; qy[t]=sy; vis[sx][sy]=1;
    while (h<t){
        h++;
        if (a[qx[h]][qy[h]]>='A' && a[qx[h]][qy[h]]<='Z'){
            find(qx[h],qy[h]);
            qx[h]=fi; qy[h]=fj;
        }
        for (int k=0;k<4;k++){
            int tx=qx[h]+fx[k],ty=qy[h]+fy[k];
            if (a[tx][ty]!=0 && vis[tx][ty]==0){
                vis[tx][ty]=1;
                t++;
                qx[t]=tx; qy[t]=ty;
                cnt[t]=cnt[h]+1;
                if (tx==ex && ty==ey){
                    printf("%d",cnt[t]);
                    return 0;
                }
            }
        }
    }
    return 0;
}