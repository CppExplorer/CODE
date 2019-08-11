#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,kth,m,x[1000010],y[1000010],c[1000010],sa[1000010],rk[1000010],s[1000010],height[1000010];

void GetSA(){
    for (int i=1;i<=n;++i) c[x[i]=s[i]]++;
    for (int i=1;i<=m;++i) c[i]+=c[i-1];
    for (int i=n;i;--i) sa[c[x[i]]--]=i;
    for (int k=1;k<=n;k<<=1){
        int num=0;
        for (int i=n-k+1;i<=n;++i) y[++num]=i;
        for (int i=1;i<=n;++i) if (sa[i]>k) y[++num]=sa[i]-k;
        for (int i=0;i<=m;++i) c[i]=0;
        for (int i=1;i<=n;++i) c[x[i]]++;
        for (int i=1;i<=m;++i) c[i]+=c[i-1];
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
    int cnt=0; height[n+1]=0;
    for (int i=1;i<=n+1;++i){
        if (height[i]<k){
            if (cnt>=kth) return true;
            cnt=0;
        }
        cnt++;
    }
    return false;
}

int main(){
    scanf("%d%d",&n,&kth);
    for (int i=1;i<=n;++i) scanf("%d",&s[i]);
    m=1000000;
    GetSA(); GetHeight();
    int l=1,r=n;
    while (l<r){
        int mid=(l+r+1)>>1;
        if (check(mid)) l=mid;
            else r=mid-1;
    }
    printf("%d",l);
    return 0;
}