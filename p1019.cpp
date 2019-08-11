#include<bits/stdc++.h>
using namespace std;
int n,i,ans,cnt,vis[25];
char s[21][200],ch;

int cmp(int x,int y){
    int l1=strlen(s[x]),l2=strlen(s[y]),res=INT_MAX;
    for (int i=0;i<l1;++i)
    if (s[x][i]==s[y][0]){
        int j=i,k=0;
        while (j<l1 && k<l2 && s[x][j]==s[y][k]){j++;k++;}
        if (j==l1) res=min(res,l1-i);
    }
    if (res!=INT_MAX) return res;
    return 0;
}

void dfs(int x){
    for (int i=1;i<=n;++i)
    if (vis[i]<2){
        int m=cmp(x,i);
        if (m){
            int l=strlen(s[i]);
            vis[i]++; cnt+=l-m;
            dfs(i);
            vis[i]--; cnt=cnt-l+m;
        }
    }
    ans=max(ans,cnt);
}

int main(){
    scanf("%d",&n);
    for (i=1;i<=n;++i) scanf("%s",s[i]);
    scanf("\n%c",&ch);
    for (i=1;i<=n;++i)
        if (s[i][0]==ch){
            memset(vis,0,sizeof 0);
            cnt=strlen(s[i]); vis[i]=1;
            dfs(i);
        }
    printf("%d",ans);
    return 0;
}