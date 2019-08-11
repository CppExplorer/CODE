#include<cstdio>
#include<algorithm>
#include<cassert>
using namespace std;
const int N=1005;
int kx,ky,x[N],y[N],vis[N][N],midx=500,midy=500;

template <typename Tp>
inline void read(Tp &x) {
    bool f = true; char ch = getchar(); x=0;
    for ( ; ch < '0' || ch > '9'; ch = getchar()) f ^= ch == '-';
    for ( ; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + (ch ^ 48);
    x = f ? x : -x;
}

void move(int &x,int &y){
    if (x<=midx && y<=midy){
        if (x<midx && y<midy && !vis[x+1][y+1]){x++,y++; return;}
        if (x<midx && y<midy && vis[x+1][y+1]){
            if (!vis[x+1][y]){x++; return;}
            if (!vis[x][y+1]){y++; return;}
        }
        if (x==midx && y<midy){y++; return;}
        if (y==midy && x<midx){x++; return;}
    }
    if (x<=midx && y>midy){
        if (x<midx && !vis[x+1][y-1]){x++,y--; return;}
        if (x<midx && vis[x+1][y-1]){
            if (!vis[x+1][y]){x++; return;}
            if (!vis[x][y-1]){y--; return;}
        }
        if (x==midx){y--; return;}
    }
    if (x>midx && y<=midy){ 
        if (y<midy && !vis[x-1][y+1]){x--,y++; return;}
        if (y<midy && vis[x-1][y+1]){
            if (!vis[x-1][y]){x--; return;}
            if (!vis[x][y+1]){y++; return;}
        }
        if (y==midy){x--; return;}
    }
    if (x>midx && y>midy){
        if (!vis[x-1][y-1]){x--,y--; return;}
        if (vis[x-1][y-1]){
            if (!vis[x-1][y]){x--; return;}
            if (!vis[x][y-1]){y--; return;}
        }
    }
}

int main(){
    read(kx),read(ky);
    for (int i=1;i<=666;++i) read(x[i]),read(y[i]),vis[x[i]][y[i]]++;
    while (kx!=500 || ky!=500){
        move(kx,ky);
        printf("%d %d\n",kx,ky); fflush(stdout);
        int k,tx,ty;
        read(k),read(tx),read(ty);
        if (k==-1 || !k) return 0;
        vis[x[k]][y[k]]--; vis[tx][ty]++;
        x[k]=tx,y[k]=ty;
    }
    int lu=0,ru=0,ld=0,rd=0;
    for (int i=1;i<=666;++i){
        if (x[i]<500 && y[i]<500){lu++; continue;}
        if (x[i]<500 && y[i]>500){ru++; continue;}
        if (x[i]>500 && y[i]<500){ld++; continue;}
        if (x[i]>500 && y[i]>500){rd++; continue;}
    }
    int way=min(lu,min(ru,min(ld,rd)));
    if (way==lu) midx=999,midy=999;
    else if (way==ru) midx=999,midy=1;
    else if (way==ld) midx=1,midy=999;
    else if (way==rd) midx=1,midy=1;
    while (kx!=midx || ky!=midy){
        move(kx,ky);
        printf("%d %d\n",kx,ky); fflush(stdout);
        int k,tx,ty;
        read(k),read(tx),read(ty);
        if (k==-1 || !k) return 0;
        vis[x[k]][y[k]]--; vis[tx][ty]++;
        x[k]=tx,y[k]=ty;
    }
    return 0;
}