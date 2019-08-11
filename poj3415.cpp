#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2e5+5;
int k,n,m,x[N],y[N],c[N],sa[N],rk[N],height[N],l,stack[N],top,w[N];
char s[N];

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

int main(){
    scanf("%d",&k);
    while (k){
        scanf("%s",s+1);
        n=strlen(s+1);
        l=n++; s[n]='$';
        scanf("%s",s+1+n);
        n+=strlen(s+1+n); m=122;
        long long ans=0,sum=0;
        GetSA(); GetHeight();
        for (int i=1;i<=n;++i){
            if (height[i]<k) top=0,sum=0;
            else{
                int width=0;
                while (top && stack[top]>height[i]){
                    sum-=w[top]*(stack[top]-height[i]);
                    width+=w[top--];
                }
                if (sa[i-1]<=l) width++,sum+=height[i]-k+1;
                stack[++top]=height[i];
                w[top]=width;
                if (sa[i]>l) ans+=sum;
            }
        }
        for (int i=1;i<=n;++i){
            if (height[i]<k) top=0,sum=0;
            else{
                int width=0;
                while (top && stack[top]>height[i]){
                    sum-=w[top]*(stack[top]-height[i]);
                    width+=w[top--];
                }
                if (sa[i-1]>l) width++,sum+=height[i]-k+1;
                stack[++top]=height[i];
                w[top]=width;
                if (sa[i]<=l) ans+=sum;
            }
        }
        printf("%lld\n",ans);
        scanf("%d",&k);
    }
    return 0;
}