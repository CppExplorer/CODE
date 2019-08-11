#include<cstdio>
#include<algorithm>
using namespace std;
const int N=2e4;
int n,m,f[N],oe[N],b[N],c[N],cnt,num;
char ans[10];
struct answer{
    int l,r,oe;
}a[N];

int query(int x){
    return lower_bound(c+1,c+1+cnt,x)-c;
}

int father(int x){
    if (f[x]==x) return x;
    int fa=f[x];
    f[x]=father(f[x]);
    oe[x]^=oe[fa];
    return f[x];
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;++i){
        scanf("%d%d%s",&a[i].l,&a[i].r,ans+1);
        if (ans[1]=='e') a[i].oe=0;
            else a[i].oe=1;
        b[++num]=a[i].l-1; b[++num]=a[i].r;
    }
    sort(b+1,b+1+num);
    for (int i=1;i<=num;++i)
        if (i==1 || b[i]!=b[i-1]) c[++cnt]=b[i];
    for (int i=1;i<=(m<<1);++i) f[i]=i;
    for (int i=1;i<=m;++i){
        int x=query(a[i].l-1),y=query(a[i].r);
        int u=father(x),v=father(y);
        if (u==v){
            if ((oe[x]^oe[y])!=a[i].oe){
                printf("%d",i-1);
                return 0;
            }
        }else{
            f[u]=v;
            oe[u]=oe[x]^oe[y]^a[i].oe;
        }
    }
    printf("%d",m);
    return 0;
}