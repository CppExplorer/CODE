#include<cstdio>
using namespace std;
int n,r;
struct tree{
    int fa,cnt,c;
    double w;
}a[1005];

int find(){
    int res;
    double maxn=0;
    for (int i=1;i<=n;++i)
        if (i!=r && a[i].w>maxn){
            maxn=a[i].w;
            res=i;
        }
    return res;
}

int main(){
    scanf("%d%d",&n,&r);
    while (n && r){
        int ans=0;
        for (int i=1;i<=n;++i){
            scanf("%d",&a[i].c);
            a[i].w=a[i].c;
            a[i].cnt=1;
            ans+=a[i].c;
        }
        for (int i=1,x,y;i<n;++i){
            scanf("%d%d",&x,&y);
            a[y].fa=x;
        }
        for (int i=1;i<n;++i){
            int now=find();
            a[now].w=0;
            int fa=a[now].fa;
            ans+=a[now].c*a[fa].cnt;
            a[fa].cnt+=a[now].cnt;
            a[fa].c+=a[now].c;
            a[fa].w=(double)a[fa].c/a[fa].cnt;
            for (int j=1;j<=n;++j)
                if (a[j].fa==now) a[j].fa=fa;
        }
        printf("%d\n",ans);
        scanf("%d%d",&n,&r);
    }
    return 0;
}