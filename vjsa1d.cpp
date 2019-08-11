#include<bits/stdc++.h>
using namespace std;
char s[1005],t[2005],ans[2005];
int p[2005],r,mid;
int main(){
    scanf("%s",s);
    int n=strlen(s);
    for (int i=0;i<n;++i){
        t[i*2]='$';
        t[i*2+1]=s[i];
    }
    int len=strlen(t);
    t[len]='$'; len++;
    for (int i=0;i<len;++i){
        if (i<r) p[i]=min(r-i,p[mid*2-i]);
            else p[i]=1;
        while (i-p[i]>=0 && i+p[i]<len && t[i-p[i]]==t[i+p[i]]) p[i]++;
        if (i+p[i]>r){
            r=i+p[i];
            mid=i;
        }
    }
    int maxl=0;
    for (int i=0;i<len;++i)
        if (p[i]-1>maxl){
            maxl=p[i]-1;
            n=0;
            for (int j=i-p[i]+1;j<=i+p[i]-1;++j) ans[n++]=t[j];
        }
    for (int i=0;i<n;++i) if (ans[i]!='$') printf("%c",ans[i]);
    return 0;
}