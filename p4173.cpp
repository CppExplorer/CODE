#include<bits/stdc++.h>
using namespace std;
int m,n,i,j,nxt[300005],f[300005],ans,l[300005];
char a[300005],b[300005];
int main(){
    scanf("%d%d",&m,&n);
    scanf("%s%s",a+1,b+1);
    nxt[1]=0;
    for (i=2,j=0;i<=m;++i){
        while (j>0 && a[i]!=a[j+1]) j=nxt[j];
        if (a[i]==a[j+1]) j++;
        nxt[i]=j;
    }
    for (i=1,j=0;i<=n;++i){
        while (j>0 && a[j+1]!='*' && b[i]!='*' && b[i]!=a[j+1]) j=nxt[j];
        if (b[i]==a[j+1] || (a[j+1]=='*' || b[i]=='*')) j++;
        f[i]=j;
        if (f[i]==m){
            ans++;
            l[ans]=i; 
        }
    }
    printf("%d\n",ans);
    for (i=1;i<=ans;++i) printf("%d ",l[i]);
    return 0;
}