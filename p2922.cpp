#include<cstdio>
using namespace std;
const int N=5e4+5,SIZE=5e5+5;
int n,m,t[SIZE][2],ed[SIZE],tot=1,cnt[SIZE],len,a[N];

void insert(){
    int p=1;
    for (int i=1;i<=len;++i){
        if (!t[p][a[i]]) t[p][a[i]]=++tot;
        p=t[p][a[i]];
        cnt[p]++;
    }
    ed[p]++;
}

int search(){
    int p=1,ans=0;
    for (int i=1;i<=len;++i){
        p=t[p][a[i]];
        if (i<len) ans+=ed[p];
        if (!p) return ans;
    }
    ans+=cnt[p];
    return ans;
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i){
        scanf("%d",&len);
        for (int j=1;j<=len;++j) scanf("%d",&a[j]);
        insert();
    }
    for (int i=1;i<=m;++i){
        scanf("%d",&len);
        for (int j=1;j<=len;++j) scanf("%d",&a[j]);
        printf("%d\n",search());
    }
    return 0;
}