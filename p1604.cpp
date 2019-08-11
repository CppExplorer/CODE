#include<bits/stdc++.h>
using namespace std;
int n,a[2005],b[2005],c[4005];
char s1[2005],s2[2005];
int main(){
    scanf("%d%s%s",&n,s1,s2);
    a[0]=strlen(s1); b[0]=strlen(s2);
    for (int i=0;i<a[0];++i) a[a[0]-i]=s1[i]-(s1[i]<58?48:55);
    for (int i=0;i<b[0];++i) b[b[0]-i]=s2[i]-(s2[i]<58?48:55);
    int m=max(a[0],b[0]); c[0]=m+2;
    for (int i=1;i<=m;++i) c[i]=a[i]+b[i];
    for (int i=1;i<=c[0];++i){
        c[i+1]+=c[i]/n;
        c[i]%=n;
    }
    while (!c[c[0]] && c[0]>1) c[0]--;
    for (int i=c[0];i;--i) printf("%c",c[i]+(c[i]<10?48:55));
    return 0;
}