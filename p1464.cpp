#include<bits/stdc++.h>
using namespace std;
long long a,b,c,vis[25][25][25];

long long  work(long long a,long long b,long long c){
    if (a<=0 || b<=0 ||c<=0) return 1;
    else if (vis[a][b][c]!=0) return vis[a][b][c];
    else if (a>20 || b>20 || c>20) vis[a][b][c]=work(20,20,20);
    else if (a<b && b<c) vis[a][b][c]=work(a,b,c-1)+work(a,b-1,c-1)-work(a,b-1,c);
    else vis[a][b][c]=work(a-1,b,c)+work(a-1,b-1,c)+work(a-1,b,c-1)-work(a-1,b-1,c-1);
    return vis[a][b][c];
}

int main(){
    while(scanf("%lld%lld%lld",&a,&b,&c)!=EOF){
        memset(vis,0,sizeof vis);
        if (a==-1 && b==-1 && c==-1) break;
		printf("w(%lld, %lld, %lld) = ",a,b,c);
        if (a>20) a=21;
        if (b>20) b=21;
        if (c>20) c=21;
        printf("%lld\n",work(a,b,c));
    }
    return 0;
}
