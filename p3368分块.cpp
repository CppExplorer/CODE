#include<bits/stdc++.h>
using namespace std;
int n,m,t,i,a[500005],pos[500005],l[5005],r[5005],j,x,y,k,c,add[5005];

void change(int x,int y,int d){
    int p=pos[x],q=pos[y];
    if (p==q){
        for (int i=x;i<=y;++i) a[i]+=d;
    }else{
        for (int i=p+1;i<=q-1;++i) add[i]+=d;
        for (int i=x;i<=r[p];++i) a[i]+=d;
        for (int i=l[q];i<=y;++i) a[i]+=d;
    }
}

int ask(int x){
    return add[pos[x]]+a[x];
}

int main(){
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;++i) scanf("%d",&a[i]);
    t=sqrt(n);
    for (i=1;i<=t;++i){
        l[i]=(i-1)*t+1;
        r[i]=i*t;
    }
    if (r[t]<n){
        t++; l[t]=r[t-1]+1; r[t]=n;
    }
    for (i=1;i<=t;++i)
        for (j=l[i];j<=r[i];++j) pos[j]=i;
    for (i=1;i<=m;++i){
        scanf("%d%d",&c,&x);
        if (c==1){
            scanf("%d%d",&y,&k);
            change(x,y,k);
        }else printf("%d\n",ask(x));
    }
    return 0;
}