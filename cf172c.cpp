#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,t[N],x[N],ti,l=1,r,ans[N],h[N],num,nowx;

void push(int i){
    h[++num]=i;
    int now=num,nxt;
    while (now>1){
        nxt=now>>1;
        if (x[h[nxt]]<x[h[now]]) return;
        int t=h[nxt]; h[nxt]=h[now]; h[now]=t;
        now=nxt;
    }
}

void pop(){
    h[1]=h[num--];
    int now=1,nxt;
    while ((now<<1)<=num){
        nxt=now<<1;
        if (nxt<num && x[h[nxt+1]]<x[h[nxt]]) nxt++;
        if (x[h[nxt]]>x[h[now]]) return;
        int t=h[nxt]; h[nxt]=h[now]; h[now]=t;
        now=nxt;
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i) scanf("%d%d",&t[i],&x[i]);
    for (;r<n;){
        r+=min(n-r,m);
        for (int i=l;i<=r;++i){
            push(i);
            ti=max(ti,t[i]);
        }
        //printf("l=%d r=%d time=%d num=%d\n",l,r,ti,num);
        while (num){
            int xx=x[h[1]],cnt=1,xi=h[1]; pop();
            ti+=xx-nowx; ans[xi]=ti;
            //printf("go to%d now at%d time=%d name=%d\n",xx,nowx,ti,xi);
            while (num && x[h[1]]==xx){
                cnt++; ans[h[1]]=ti; pop();
            }
            ti+=1+cnt/2;
            nowx=xx;
        }
        ti+=nowx; nowx=0; l=r+1;
    }
    //for (int i=1;i<=n;++i) printf("%d %d\n",t[i],x[i]);
    for (int i=1;i<=n;++i) printf("%d ",ans[i]);
    return 0;
}