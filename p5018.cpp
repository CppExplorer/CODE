#include<bits/stdc++.h>
using namespace std;
int n,l[1000005],r[1000005],v[1000005],i,m,ans;
bool flag;

void count(int x){
    m++;
    if (l[x]!=-1) count(l[x]);
    if (r[x]!=-1) count(r[x]);    
}

void tree(int x,int y){
    if (x==-1 && y==-1) return;
    if (x==-1 || y==-1 || v[x]!=v[y]){
        flag=0;
        return;
    }
    tree(l[x],r[y]);
    tree(r[x],l[y]);
}

int main(){
    scanf("%d",&n);
    for (i=1;i<=n;++i) scanf("%d",&v[i]);
    for (i=1;i<=n;++i) scanf("%d%d",&l[i],&r[i]);
    for (i=1;i<=n;++i){
        m=0; flag=1;
        tree(l[i],r[i]);
        if (flag) count(i);
        if (m>ans) ans=m;
    }
    printf("%d",ans);
    return 0;
}