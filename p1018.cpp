#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N=50;
int n,m;
char s[N];
struct Mul{
    int num[100];
}f[N][10],c;

Mul cut(int l,int r){
    memset(c.num,0,sizeof c.num);
    for (int i=r;i>=l;--i) c.num[++c.num[0]]=s[i]-'0';
    return c;
}

Mul multiply(Mul x,Mul y){
    memset(c.num,0,sizeof c.num);
    c.num[0]=x.num[0]+y.num[0]+1;
    for (int i=1;i<=x.num[0];++i)
        for (int j=1;j<=y.num[0];++j)
        c.num[i+j-1]+=x.num[i]*y.num[j];
    for (int i=1;i<=c.num[0];++i){
        c.num[i+1]+=c.num[i]/10;
        c.num[i]%=10;
    }
    while (!c.num[c.num[0]] && c.num[0]>1) c.num[0]--;
    return c;
}

Mul Max(Mul x,Mul y){
    if (x.num[0]>y.num[0]) return x;
    if (y.num[0]>x.num[0]) return y;
    for (int i=x.num[0];i;--i){
        if (x.num[i]>y.num[i]) return x;
        if (y.num[i]>x.num[i]) return y;
    }
}

int main(){
    scanf("%d%d%s",&n,&m,s+1);
    for (int i=1;i<=n;++i) f[i][0]=cut(1,i);
    for (int i=2;i<=n;++i)
        for (int j=1;j<=min(m,i-1);++j)
            for (int k=j;k<i;++k)
            f[i][j]=Max(f[i][j],multiply(f[k][j-1],cut(k+1,i)));
    for (int i=f[n][m].num[0];i;--i) printf("%d",f[n][m].num[i]);
    return 0;
}