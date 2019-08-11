#include<cstdio>
using namespace std;
long long x,y,m,n,l;

long long exgcd(long long a,long long b,long long &x,long long &y){
    if (!b){x=1,y=0; return a;}
    long long ans=exgcd(b,a%b,x,y);
    long long z=x; x=y; y=z-y*(a/b);
    return ans;
}

int main(){
    scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l);
    long long a=n-m,b=l,x1,y1,c=x-y;
    if (a<0) a=-a,c=-c;
    long long ans=exgcd(a,b,x1,y1);
    if (c%ans!=0){
        printf("Impossible");
        return 0;
    }
    printf("%lld",((x1*c/ans)%(l/ans)+(l/ans))%(l/ans));
    return 0;
}