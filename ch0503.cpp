#include<bits/stdc++.h>
using namespace std;
int n,c[1000006],a[250005],b[250005];

int lowbit(int x){
    return x&(-x);
}

void add(int x,int y){
    if (x==0) return;
    for (;x<=n*n;x+=lowbit(x)) c[x]+=y;
}

int ask(int x){
    int ans=0;
    for (;x>=1;x-=lowbit(x)) ans+=c[x];
    return ans;
}

int main(){
    while (scanf("%d",&n)!=EOF){
        memset(c,0,sizeof c);
        for (int i=1;i<=n*n;++i) scanf("%d",&a[i]);
        int ans1=0;
        for (int i=n*n;i;--i){
            ans1+=ask(a[i]-1);
            add(a[i],1);
        }
        memset(c,0,sizeof c);
        for (int i=1;i<=n*n;++i) scanf("%d",&b[i]);
        int ans2=0;
        for (int i=n*n;i;--i){
            ans2+=ask(b[i]-1);
            add(b[i],1);
        }
        if (ans1&1){
            if (ans2&1) printf("TAK\n");
                else printf("NIE\n");
        }else{
            if (ans2&1) printf("NIE\n");
                else printf("TAK\n");
        }
    }
    return 0;
}