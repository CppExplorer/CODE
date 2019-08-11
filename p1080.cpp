#include<bits/stdc++.h>
using namespace std;
int n,now[10000],ans[10000],c[10000];
struct number{
    int l,r;
}a[10005];

bool cmp(number x,number y){
    return x.l*x.r<y.l*y.r;
}

void multiply(int x){
    memset(c,0,sizeof c);
    for (int i=1;i<=now[0];++i){
        now[i]=now[i]*x;
        c[i+1]+=now[i]/10;
        now[i]=now[i]%10;
    }
    for (int i=1;i<=now[0]+4;++i){
        now[i]+=c[i];
        if (now[i]>=10){
            now[i+1]+=now[i]/10;
            now[i]=now[i]%10;
        }
        if (now[i]) now[0]=max(now[0],i);
    }
}

void divide(int x){
    memset(c,0,sizeof c);
    int num=0;
    for (int i=now[0];i;--i){
        num=num*10+now[i];
        c[i]=num/x;
        if (!c[0] && c[i]!=0) c[0]=i;
        num=num%x;
    }
}

bool compare(){
    if (ans[0]<c[0]) return true;
    if (ans[0]>c[0]) return false;
    for (int i=ans[0];i;--i){
        if (ans[i]<c[i]) return true;
        if (c[i]<ans[i]) return false;
    }
}

void cpy(){
    memset(ans,0,sizeof ans);
    for (int i=c[0];i>=0;--i) ans[i]=c[i];
}

int main(){
    scanf("%d",&n);
    for (int i=0;i<=n;++i) scanf("%d%d",&a[i].l,&a[i].r);
    sort(a+1,a+1+n,cmp);
    now[1]=1; now[0]=1;
    for (int i=1;i<=n;++i){
        multiply(a[i-1].l);
        divide(a[i].r);
        if (compare()) cpy();
    }
    for (int i=ans[0];i;--i) printf("%d",ans[i]);
    return 0;
}