#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2e5+5;
int n,m,cheap,num=1;
struct dish{
    int a,c,id;
}a[N],b[N];

bool cmp(dish x,dish y){
    return x.c==y.c?x.id<y.id:x.c<y.c;
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i) scanf("%d",&a[i].a);
    for (int i=1;i<=n;++i) scanf("%d",&a[i].c),a[i].id=i;
    for (int i=1;i<=n;++i) b[i]=a[i];
    sort(b+1,b+1+n,cmp);
    cheap=b[num].id;
    for (int i=1,t,d;i<=m;++i){
        scanf("%d%d",&t,&d);
        long long ans=0;
        if (a[t].a){
            int eaten=min(a[t].a,d);
            a[t].a-=eaten; d-=eaten;
            ans+=1LL*eaten*a[t].c;
        }
        if (!d){
            printf("%lld\n",ans);
            continue;
        }
        bool flag=0;
        while (d){
            if (!a[cheap].a){
                cheap=b[++num].id;
                if (num>n){flag=1; break;}
            }
            int eaten=min(a[cheap].a,d);
            a[cheap].a-=eaten; d-=eaten;
            ans+=1LL*eaten*a[cheap].c;
        }
        printf("%lld\n",flag?0:ans);
    }
    return 0;
}