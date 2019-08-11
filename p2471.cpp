#include<cstdio>
#include<algorithm>
using namespace std;
const int N=5e4+5;
int n,q,year[N],rain[N],f[N][20],lg[N+5];

int query(int l,int r){
    int k=lg[r-l+1];
    return max(f[l][k],f[r-(1<<k)+1][k]);
}

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;++i) scanf("%d %d",&year[i],&rain[i]);
    for (int i=1;i<=n;++i) f[i][0]=rain[i];
    for (int i=2;i<=N;++i) lg[i]=lg[i>>1]+1;
    for (int j=1;j<=lg[n];++j)
        for (int i=1;i+(1<<j)-1<=n;++i)
        f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
    scanf("%d",&q);
    for (int i=1,x,y;i<=q;++i){
        scanf("%d%d",&y,&x);
        int a=lower_bound(year+1,year+1+n,y)-year,b=lower_bound(year+1,year+1+n,x)-year;
        if (year[a]!=y && year[b]!=x){
            printf("maybe\n");
            continue;
        }
        if (year[a]!=y && year[b]==x){
            if (b-a<1){
                printf("maybe\n");
                continue;
            }
            int res=query(a,b-1);
            if (res>=rain[b]){
                printf("false\n");
                continue;
            }
            printf("maybe\n");
            continue;
        }
        if (year[a]==y && year[b]!=x){
            if (b-a<=1){
                printf("maybe\n");
                continue;
            }
            int res=query(a+1,b-1);
            if (res>=rain[a]){
                printf("false\n");
                continue;
            }
            printf("maybe\n");
            continue;
        }
        if (b-a==1){
            if (rain[a]<rain[b]){
                printf("false\n");
                continue;
            }
            if (b-a<x-y){
                printf("maybe\n");
                continue;
            }
            printf("true\n");
            continue;
        }
        int res=query(a+1,b-1);
        if (rain[b]>rain[a] || res>=rain[a] || res>=rain[b]){
            printf("false\n");
            continue;
        }
        if (b-a<x-y){
            printf("maybe\n");
            continue;
        }
        printf("true\n");
    }
    return 0;
}