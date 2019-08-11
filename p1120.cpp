#include<bits/stdc++.h>
using namespace std;
int m,i,n,a[70],l,r;
bool vis[70];

bool cmp(int x,int y){
    return x>y;
}

inline void dfs(int x,int m,int len,int now){
    if (m*len==r){
        printf("%d",len);
        exit(0);
    }
    if (x==len){
        dfs(0,m+1,len,1);
        return;
    }
    if (len-x<a[n]) return;
    for (int j=now;j<=n;++j)
        if (!vis[j] && x+a[j]<=len){
            vis[j]=1;
            dfs(x+a[j],m,len,j+1);
            vis[j]=0;
            if (x+a[j]==len || x==0) break;
            while (a[j]==a[j+1]) j++;
        }
}

int main(){
    scanf("%d",&m);
    for (i=1;i<=m;++i){
        int x;
        scanf("%d",&x);
        if (x>50) continue;
        n++; 
        a[n]=x;
        l=max(x,l); r+=x;
    }
    sort(a+1,a+1+n,cmp);
    for (i=l;i<=r/2;++i)
        if (r%i==0) dfs(0,0,i,1);
    printf("%d",r);
    return 0;
}