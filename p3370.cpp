#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int n,ans;
char s[1500];
unsigned long long a[N];

void H(int k,char s[]){
    int m=strlen(s+1);
    for (int i=1;i<=m;++i)
        a[k]=a[k]*131+(s[i]-'0');
    //printf("%llu\n",a[k]);
}

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%s",s+1);
        H(i,s);
    }
    sort(a+1,a+1+n);
    for (int i=1;i<=n;++i) if (a[i]!=a[i+1]) ans++;
    printf("%d",ans);
    return 0;
}