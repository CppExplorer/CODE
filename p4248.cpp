#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int x[500005],y[500005],c[500005],sa[500005],n,m,height[500005],rk[500005];
int st[500005],top,l[500005],r[500005];
char s[500005];
long long ans;

void GetSA(){
    for (int i=1;i<=n;++i) c[x[i]=s[i]]++;
    for (int i=2;i<=m;++i) c[i]+=c[i-1];
    for (int i=n;i;--i) sa[c[x[i]]--]=i;
    for (int k=1;k<=n;k<<=1){
        int num=0;
        for (int i=n-k+1;i<=n;++i) y[++num]=i;
        for (int i=1;i<=n;++i) if (sa[i]>k) y[++num]=sa[i]-k;
        for (int i=1;i<=m;++i) c[i]=0;
        for (int i=1;i<=n;++i) c[x[i]]++;
        for (int i=2;i<=m;++i) c[i]+=c[i-1];
        for (int i=n;i;--i) sa[c[x[y[i]]]--]=y[i],y[i]=0;
        swap(x,y);
        x[sa[1]]=1; num=1;
        for (int i=2;i<=n;++i) 
            x[sa[i]]=(y[sa[i]]==y[sa[i-1]] && y[sa[i]+k]==y[sa[i-1]+k]?num:++num);
        if (num==n) break;
        m=num;
    }
}

void GetHeight(){
    for (int i=1;i<=n;++i) rk[sa[i]]=i;
    int k=0;
    for (int i=1;i<=n;++i){
        if (rk[i]==1) continue;
        if (k) k--;
        int j=sa[rk[i]-1];
        while (j+k<=n && i+k<=n && s[i+k]==s[j+k]) k++;
        height[rk[i]]=k;
    }
}

int main(){
    scanf("%s",s+1);
    n=strlen(s+1); m=122;
    GetSA();
    GetHeight();
    height[0]=height[n+1]=-2e9;
    for (int i=1;i<=n+1;++i){
        while (top && height[i]<height[st[top]]) r[st[top--]]=i;
        st[++top]=i;
    }
    for (int i=n;i>=0;--i){
        while (top && height[i]<=height[st[top]]) l[st[top--]]=i;
        st[++top]=i;
    }
    ans=(long long)(n-1)*n*(n+1)/2;
    for (int i=1;i<=n;++i) ans-=(long long)2*height[i]*(i-l[i])*(r[i]-i);
    printf("%lld",ans);
    return 0;
}