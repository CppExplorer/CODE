#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,x[20005],y[20005],rk[20005],sa[20005],c[20005],s[20005],height[20005],a[20005];

void GetSA(){
    memset(c,0,sizeof c);
    memset(y,0,sizeof y);
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

bool check(int k){
    int maxh=0,minh=2e9; height[n+1]=0;
    for (int i=1;i<=n+1;++i){
        if (height[i]<k){
            if (maxh-minh>=k) return true;
            maxh=0; minh=2e9;
        }
        maxh=max(maxh,sa[i]); minh=min(minh,sa[i]);
    }
    return false;
}

int main(){
    scanf("%d",&n);
    while (n){
        for (int i=1;i<=n;++i) scanf("%d",&a[i]);
        for (int i=1;i<n;++i) s[i]=a[i+1]-a[i]+100;
        n--; m=200;
        GetSA(); GetHeight();
        int l=1,r=n;
        while (l<r){
            int mid=(l+r+1)>>1;
            if (check(mid)) l=mid;
                else r=mid-1; 
        }
        printf("%d\n",(l<4?0:l+1));
        scanf("%d",&n);
    }
    return 0;
}