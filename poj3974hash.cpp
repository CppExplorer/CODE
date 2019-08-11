#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N=1000100;
char s[N];
int ans,n,cnt;
unsigned long long f[N],p[N],ff[N];

void Hash(){
    p[0]=1; ff[n+1]=0;
    for (int i=1;i<=n;++i){
        f[i]=f[i-1]*131+(s[i]-'a'+1);
        p[i]=p[i-1]*131;
    }
    for (int i=n;i;--i)
        ff[i]=ff[i+1]*131+(s[i]-'a'+1);
}

bool checkO(int l,int x){
    unsigned long long vl=f[x-1]-f[x-l-1]*p[l];
    unsigned long long vr=ff[x+1]-ff[x+1+l]*p[l];
    //printf("%llu %llu\n",vl,vr);
    if (vl==vr) return true;
        else return false;
}

bool checkE(int l,int x){
    unsigned long long vl=f[x]-f[x-l]*p[l];
    unsigned long long vr=ff[x+1]-ff[x+l+1]*p[l];
    if (vl==vr) return true;
        else return false;
}

int main(){
    while (1){
        scanf("%s",s+1);
        if (s[1]=='E') return 0;
        n=strlen(s+1); ans=0;
        Hash();
        for (int i=1;i<=n;++i){
            int l=0,r=min(i-1,n-i);
            while (l<r){
                int mid=(l+r+1)>>1;
                if (checkO(mid,i)) l=mid;
                    else r=mid-1;
            }
            ans=max(ans,l*2+1);
            l=0; r=min(i,n-i);
            while (l<r){
                int mid=(l+r+1)>>1;
                if (checkE(mid,i)) l=mid;
                    else r=mid-1;
            }
            ans=max(ans,l*2);
        }
        printf("Case %d: %d\n",++cnt,ans);
    }
    return 0;
}