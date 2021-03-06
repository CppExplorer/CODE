#include<bits/stdc++.h>
using namespace std;
int n,k,h[100005],l,pre[100005],nxt[100005],loc[100005],a[100005],ans,i;

void up(int x){
    int now=x,nt;
    while (now>1){
        nt=now/2;
        if (a[h[now]]>a[h[nt]]) return;
        int t=h[now]; h[now]=h[nt]; h[nt]=t;
        t=loc[h[now]]; loc[h[now]]=loc[h[nt]]; loc[h[nt]]=t;
        now=nt;
    }
}

void down(int x){
    int now=x,nt;
    while (now*2<=l){
        nt=now*2;
        if (nt<l && a[h[nt+1]]<a[h[nt]]) nt++;
        if (a[h[nt]]>a[h[now]]) return;
        int t=h[now]; h[now]=h[nt]; h[nt]=t;
        t=loc[h[now]]; loc[h[now]]=loc[h[nt]]; loc[h[nt]]=t;
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
    scanf("%d%d",&n,&k);
    for (i=1;i<=n;++i) scanf("%d",&a[i]);
    for (i=1;i<n;++i){
        a[i]=a[i+1]-a[i];
        pre[i+1]=i;
        nxt[i]=i+1;
        insert(i);
    }
    for (i=1;i<=k;++i){
        int x=h[1]; ans+=a[x];
        if (pre[x]==0 && nxt[x]==n) break;
        if (pre[x]==0){
            remove(x); remove(nxt[x]);
            pre[nxt[nxt[x]]]=0;
        }else if (nxt[x]==n){
            remove(x); remove(pre[x]);
            nxt[pre[pre[x]]]=n;
        }else{
            remove(x); remove(pre[x]); remove(nxt[x]);
            a[x]=a[pre[x]]+a[nxt[x]]-a[x];
            insert(x);
            pre[x]=pre[pre[x]]; nxt[pre[x]]=x;
            nxt[x]=nxt[nxt[x]]; pre[nxt[x]]=x;
        }
    }
    printf("%d",ans);
    return 0;
}