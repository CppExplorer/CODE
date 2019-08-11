#include<bits/stdc++.h>
using namespace std;
int n,m,i,a[200005],nxt[200005],pre[200005],h[200005],loc[200005],l,ans;

void up(int x){
    int now=x,nt;
    while (now>1){
        nt=now/2;
        if (a[h[nt]]>a[h[now]]) return;
        int t=h[nt]; h[nt]=h[now]; h[now]=t;
        t=loc[h[nt]]; loc[h[nt]]=loc[h[now]]; loc[h[now]]=t;
        now=nt;
    }
}

void down(int x){
    int now=x,nt;
    while (now*2<=l){
        nt=now*2;
        if (nt<l && a[h[nt+1]]>a[h[nt]]) nt++;
        if (a[h[now]]>a[h[nt]]) return;
        int t=h[nt]; h[nt]=h[now]; h[now]=t;
        t=loc[h[nt]]; loc[h[nt]]=loc[h[now]]; loc[h[now]]=t;
        now=nt;
    }
}

void insert(int x){
    l++; h[l]=x; loc[x]=l;
    up(l);
}

void remove(int x){
    h[loc[x]]=h[l]; loc[h[l]]=loc[x]; l--;
    up(loc[x]); down(loc[x]);
}

int main(){
    scanf("%d%d",&n,&m);
    if (n%2==0){
        if (m>n/2){
            printf("Error!");
            return 0;
        }
    }else{
        if (m>=(n+1)/2){
            printf("Error!");
            return 0;
        }
    }
    pre[1]=n;
    for (i=1;i<=n;++i){
        scanf("%d",&a[i]);
        pre[i+1]=i;
        nxt[i]=i+1;
        if (i==n) nxt[i]=1;
        insert(i);
    }
    for (i=1;i<=m;++i){
        int x=h[1]; ans+=a[x];
        remove(x); remove(pre[x]); remove(nxt[x]);
        a[x]=a[pre[x]]+a[nxt[x]]-a[x];
        insert(x);
        pre[x]=pre[pre[x]]; nxt[pre[x]]=x;
        nxt[x]=nxt[nxt[x]]; pre[nxt[x]]=x;
    }
    printf("%d",ans);
    return 0;
}