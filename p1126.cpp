#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,a[120][120],sx,sy,ex,ey,h,t,vis[120][120],b[10000],cnt;
int fx[5]={0,0,2,0,-2},fy[5]={0,2,0,-2,0};
int ffx[4]={1,-1,1,-1},ffy[4]={1,1,-1,-1};
struct queue{
    int x,y,ans,way;
}q[4000000];

bool check(int x,int y){
    if (x<=1 || x>=n || y<=1 || y>=m) return false;
    for (int i=0;i<4;++i){
        int xx=x+ffx[i],yy=y+ffy[i];
        if (xx<=1 || xx>=n || yy<=1 || yy>=m) continue;
        if (a[xx][yy]==2) return false;
    }
    return true;
}

int main(){
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;++i)
        for (j=1;j<=m;++j){
            scanf("%d",&sx);
            if (sx==0) a[i*2][j*2]=1;
                else a[i*2][j*2]=2;
        }
    n=n*2+1; m=m*2+1;
    t=1;
    char ch;
    scanf("%d%d%d%d %c",&sx,&sy,&ex,&ey,&ch);
    if (ch=='E') q[t].way=1;
    else if (ch=='S') q[t].way=2;
    else if (ch=='W') q[t].way=3;
    else q[t].way=4;
    sx=sx*2+1; sy=sy*2+1; ex=ex*2+1; ey=ey*2+1;
    memset(vis,0x7f,sizeof vis);
    q[t].x=sx; q[t].y=sy;
    while (h<t){
        h++;
        int x=q[h].x,y=q[h].y;
        if (x==ex && y==ey){
            cnt++;
            b[cnt]=q[h].ans;
        }
        for (i=1;i<=4;++i){
            int tm=q[h].ans;
            if (i!=q[h].way){
                tm++;
                if (abs(q[h].way-i)==2) tm++;
            }
            for (j=1;j<=3;++j){
                int tx=x+j*fx[i],ty=y+j*fy[i];
                if (!check(tx,ty)) break;
                if (tm+1<vis[tx][ty]){
                    vis[tx][ty]=tm+1;
                    t++; q[t].x=tx; q[t].y=ty; q[t].way=i; q[t].ans=tm+1;
                }
            }
        }
    }
    int ans=INT_MAX;
    for (i=1;i<=cnt;++i)
        ans=min(ans,b[i]);
    if (ans<INT_MAX) printf("%d",ans);
        else printf("-1");
    return 0;
}
