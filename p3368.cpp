#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,k,i,c[2000005],a[500005],f;

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
    int res=0;
    while (x){
        res+=c[x];
        x-=lowbit(x);
    }
    return res;
}

int main(){
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;++i) scanf("%d",&a[i]);
    for (i=1;i<=m;++i){
        scanf("%d",&f);
        if (f==1){
            scanf("%d%d%d",&x,&y,&k);
            add(x,k); add(y+1,-k);
        }else{
            scanf("%d",&x);
            printf("%d\n",a[x]+ask(x));
        }
    }
    return 0;
}