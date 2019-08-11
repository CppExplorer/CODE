#include<cstdio>
using namespace std;
const int Mod=1e9+7,N=2e5+5;
int n,l,r,c[3];
long long f[N][3];
int main(){
    scanf("%d%d%d",&n,&l,&r);
    if (r-l+1<=3){
        for (int i=l;i<=r;++i) c[i%3]++;
    }else{
        int s=l,t=r;
        for (;;s++) if (s%3==0) break;
        for (;;t--) if (t%3==2) break;
        for (int i=0;i<3;++i) c[i]+=(t-s+1)/3;
        for (int i=l;i<s;++i) c[i%3]++;
        for (int i=t+1;i<=r;++i) c[i%3]++;
    }
    f[1][0]=c[0]; f[1][1]=c[1]; f[1][2]=c[2];
    for (int i=2;i<=n;++i){
        f[i][0]=(f[i][0]+(c[0]*f[i-1][0])%Mod)%Mod;
        f[i][0]=(f[i][0]+(c[1]*f[i-1][2])%Mod)%Mod;
        f[i][0]=(f[i][0]+(c[2]*f[i-1][1])%Mod)%Mod;
        f[i][1]=(f[i][1]+(c[0]*f[i-1][1])%Mod)%Mod;
        f[i][1]=(f[i][1]+(c[1]*f[i-1][0])%Mod)%Mod;
        f[i][1]=(f[i][1]+(c[2]*f[i-1][2])%Mod)%Mod;
        f[i][2]=(f[i][2]+(c[0]*f[i-1][2])%Mod)%Mod;
        f[i][2]=(f[i][2]+(c[2]*f[i-1][0])%Mod)%Mod;
        f[i][2]=(f[i][2]+(c[1]*f[i-1][1])%Mod)%Mod;
    }
    printf("%lld",f[n][0]);
    return 0;
}