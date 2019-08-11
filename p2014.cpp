#include <bits/stdc++.h>
using namespace std;
int n,m,i,son[305],s[305],x,l[305],r[305],f[305][305],root;

int choose(int x,int y)
{
  int t;
  if (x==-1)return 0;
  if (f[x][y]>=0) return f[x][y];
  if (l[x]==-1 && r[x]==-1) return s[x];
  t=choose(r[x],y);
  for (int i=1;i<=y;i++)
    t=max(t,choose(l[x],i-1)+choose(r[x],y-i)+s[x]);
  f[x][y]=t;
  return f[x][y];
}

int main(){
    scanf("%d%d",&n,&m);
    memset(r,-1,sizeof r);
    memset(l,-1,sizeof l);
    memset(f,-1,sizeof f);
    for (i=1;i<=n;++i){
        scanf("%d%d",&x,&s[i]);
        if (son[x]==0) l[x]=i;
          else r[son[x]]=i;
        son[x]=i;
        if (x==0) root=l[x];
    }
    for (i=0;i<=n;i++)
      for (int j=0;j<=m;j++){
        if (j==0) f[i][j]=0;else f[i][j]=-1;
     }
    printf("%d",choose(root,m));
    return 0;
}
