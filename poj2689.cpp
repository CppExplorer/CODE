#include<cstdio>
#include<cstring>
#include<climits>
using namespace std;
const int N=1000005;
int l,r,prime[N],n,v[N],a[N],m;
bool f[N];

void primes(){
    for (int i=2;i<=46340;++i){
        if (v[i]==0){
            v[i]=i;
            prime[++n]=i;
        }
        for (int j=1;j<=n;++j){
            if (prime[j]>v[i] || prime[j]*i>46340) break;
            v[i*prime[j]]=prime[j];
        }
    }
}

int main(){
    primes();
    while (scanf("%d%d",&l,&r)==2){
        memset(f,1,sizeof f); m=0;
        if (l==1) f[0]=false;
        for (int i=1;i<=n;++i)
            for (int j=l/prime[i];j<=r/prime[i];++j)
                if (j>1 && j*prime[i]>=l) f[j*prime[i]-l]=false;
                // if (j>1) f[j*prime[i]-l]=false;
        for (int i=l;i<=r;++i){
            if (f[i-l]) a[++m]=i;
            if (i==r) break;//for 循环i会多加1，可能会自然溢出，就不等于r
        }
        int maxd=0,mind=INT_MAX,x1,y1,x2,y2;
        for (int i=1;i<m;++i){
            int j=a[i+1]-a[i];
            if (j>maxd){maxd=j; x1=a[i]; y1=a[i+1];}
            if (j<mind){mind=j; x2=a[i]; y2=a[i+1];}
        }
        if (!maxd) printf("There are no adjacent primes.\n");
            else printf("%d,%d are closest, %d,%d are most distant.\n",x2,y2,x1,y1);
    }
    return 0;
}