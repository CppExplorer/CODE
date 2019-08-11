#include<bits/stdc++.h>
using namespace std;
int a[2005],b[2005],c[4005];
char s1[2005],s2[2005];
int main(){
    scanf("%s%s",s1,s2);
    int l1=strlen(s1),l2=strlen(s2);
    for (int i=1;i<=l1;++i) a[i]=s1[l1-i]-'0';
    for (int i=1;i<=l2;++i) b[i]=s2[l2-i]-'0';
    for (int i=1;i<=l1;++i)
        for (int j=1;j<=l2;++j) c[i+j-1]+=a[i]*b[j];
    int len=l1+l2;
    for (int i=1;i<=len;++i){
        c[i+1]+=c[i]/10;
        c[i]%=10;
    }
    while (!c[len] && len>1) len--;
    for (int i=len;i;--i) printf("%d",c[i]);
    return 0;
}