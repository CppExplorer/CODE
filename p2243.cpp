#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int r,c,i,j,T,dis[1000005],n,head[1000005],k;
deque<int>q;
bool f[1000005];
char ch;
struct edge{
    int to,c,x;
}e[1000005];

void add_edge(int x,int y,int z){
    k++; e[k].x=y; e[k].c=z;
    e[k].to=head[x];
    head[x]=k;
}

int main(){
    scanf("%d",&T); 
    while (T--){
        k=0; memset(dis,0x3f3f3f3f,sizeof dis);
        memset(f,0,sizeof f);
        memset(e,0,sizeof e);
        memset(head,0,sizeof head);
        scanf("%d%d",&r,&c);
        for (i=1;i<=r;++i)
            for (j=1;j<=c;++j){
                cin>>ch;
                if (ch=='/'){
                    add_edge((i-1)*(c+1)+j,i*(c+1)+j+1,1);
                    add_edge((i-1)*(c+1)+j+1,i*(c+1)+j,0);
                    add_edge(i*(c+1)+j+1,(i-1)*(c+1)+j,1);
                    add_edge(i*(c+1)+j,(i-1)*(c+1)+j+1,0);
                }else{
                    add_edge((i-1)*(c+1)+j,i*(c+1)+j+1,0);
                    add_edge((i-1)*(c+1)+j+1,i*(c+1)+j,1);
                    add_edge(i*(c+1)+j+1,(i-1)*(c+1)+j,0);
                    add_edge(i*(c+1)+j,(i-1)*(c+1)+j+1,1);
                }
            }
        n=(r+1)*(c+1);
        dis[1]=0; q.push_back(1);
        while (!q.empty()){
            int x=q.front(); q.pop_front();
            for (i=head[x];i;i=e[i].to){
                int y=e[i].x,z=e[i].c;
                if (dis[x]+z<dis[y]){
                    dis[y]=dis[x]+z;
                    if (!q.empty() && dis[y]<dis[q.front()]) q.push_front(y);
                        else q.push_back(y);
                }
            }
        }
        if (dis[n]!=INF) printf("%d\n",dis[n]);
            else printf("NO SOLUTION\n");
    }
    return 0;
}