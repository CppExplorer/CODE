#include<bits/stdc++.h>
using namespace std;
int n,m,i,k,p,l[100005],r[100005],s;
bool f[100005];
int main(){
    scanf("%d",&n);
    for (i=2;i<=n;++i){
        scanf("%d%d",&k,&p);
        if (p==0){
            l[i]=l[k]; r[i]=k;
            r[l[k]]=i; l[k]=i;
        }else{
            r[i]=r[k]; l[i]=k;
            l[r[k]]=i; r[k]=i;
        }
    }
    scanf("%d",&m);
    for (i=1;i<=m;++i){
        scanf("%d",&k);
        if (f[k]) continue;
        r[l[k]]=r[k];
        l[r[k]]=l[k];
        f[k]=1;
    }
    for (i=1;i<=n;++i)
        if (l[i]==0){
            s=i;
            break;
        }
    while (s){
        printf("%d ",s);
        s=r[s];
    }
    return 0;
}