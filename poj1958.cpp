#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;
int d[15],f[15];
int main(){
    memset(f,0x3f,sizeof f);
    f[1]=1;
    for (int i=1;i<=12;++i) d[i]=2*d[i-1]+1;
    for (int i=2;i<=12;++i)
        for (int j=1;j<i;++j)
        f[i]=min(f[i],2*f[j]+d[i-j]);
    for (int i=1;i<=12;++i) printf("%d\n",f[i]);
    return 0;
}