#include<cstdio>
#include<algorithm>
using namespace std;
int T,n,m;
int main(){
    scanf("%d",&T);
    while (T--){
        scanf("%d%d",&n,&m);
        int Mh=0,k=0,cnt=0;
        for (int i=1,h,d;i<=n;++i){
            scanf("%d%d",&h,&d);
            if (h<=d) cnt++;
            Mh=max(Mh,h),k=max(k,h-d);
        }
        if (m<=Mh){
            printf("1\n");
            continue;
        }
        if (cnt==n){
            printf("-1\n");
            continue;
        }
        m-=Mh;
        int ans=m/k;
        if (m%k) ans++;
        printf("%d\n",ans+1);
    }
    return 0;
}