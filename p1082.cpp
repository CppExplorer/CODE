#include<cstdio>
using namespace std;
int a,b,x,y;

int exgcd(int a,int b,int &x,int &y){
    if (!b){x=1,y=0; return a;}
    int ans=exgcd(b,a%b,x,y);
    int z=x; x=y; y=z-y*(a/b);
    return ans;
}

int main(){
    scanf("%d%d",&a,&b);
    int d=exgcd(a,b,x,y);
    printf("%d",(x+b/d)%(b/d));
    return 0;
}