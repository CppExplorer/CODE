// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,a[15][15],deep[15],ans=INT_MAX,cnt,b[15];
const int inf=2139062143;

inline int read () {
    int X = 0; char ch = 0;
    while(ch < 0 || ch > 9) ch = getchar();
    while(ch >= 0 && ch <= 9) X = X * 10 + ch - '0', ch = getchar();
    return X;
}

inline void dfs(int k){
    if (cnt>ans) return;
    if (k==n+1){
        ans=min(ans,cnt);
        return;
    }
    bool flag=0;
    for (int i=1;i<=k-1;++i)
        if (a[b[i]][b[k]]!=inf){
            flag=1;
            cnt+=deep[b[i]]*a[b[i]][b[k]];
            deep[b[k]]=deep[b[i]]+1;
            dfs(k+1);
            cnt-=deep[b[i]]*a[b[i]][b[k]];
            deep[b[k]]=0;
        }
    if (!flag) return;
}

int main(){
    scanf("%d%d",&n,&m);
    for (i=1;i<15;++i)
        for (j=1;j<15;++j){
            a[i][j]=inf;
            a[j][i]=inf;
        }
    for (i=1;i<=n;++i) b[i]=i;
    for (i=1;i<=m;++i){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        a[x][y]=min(a[x][y],z);
        a[y][x]=min(a[y][x],z);
    }
    for (int times=1;times<=20000;++times){
        random_shuffle(b+1,b+n+1);
        deep[b[1]]=1; 
        cnt=0;
        dfs(2);
        deep[b[1]]=0;
    }
    printf("%d",ans);
    return 0;
}