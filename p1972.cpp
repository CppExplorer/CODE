#include<bits/stdc++.h>
using namespace std;
int n,f[1000005],a,i,m,c[4000005],ans[1000005],head[1000005],pre[1000005];
struct question{
    int l,r,id;
}q[500005];

bool cmp(question x,question y){
    return x.r<y.r;
}

int lowbit(int x){
    return x&(-x);
}

void add(int x,int y){
    while (x<=n){
        c[x]+=y;
        x+=lowbit(x);
    }
}

int ask(int x){
    int ans=0;
    while (x){
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}

int main(){
    scanf("%d",&n);
    for (i=1;i<=n;++i){
        scanf("%d",&a);
        pre[i]=head[a];
        head[a]=i;
    }
    scanf("%d",&m);
    for (i=1;i<=m;++i){
        scanf("%d%d",&q[i].l,&q[i].r);
        q[i].id=i;
    }
    sort(q+1,q+1+m,cmp);
    int now=0;
    for (i=1;i<=m;++i){
        while (now<q[i].r){
            now++;
            if (pre[now]) add(pre[now],-1);
            add(now,1);
        }
        ans[q[i].id]=ask(q[i].r)-ask(q[i].l-1);
    }
    for (i=1;i<=m;++i) printf("%d\n",ans[i]);
}
