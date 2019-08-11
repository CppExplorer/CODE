#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=4e5+5;
int n,a[N],t[32*N][2],tot=1,l[N],r[N],b[35],ed[32*N],ans;

void insert(int num){
    int x=a[num],y=32,p=1;
    memset(b,0,sizeof b);
    for (;x;x>>=1) b[y--]=x%2;
    for (int i=1;i<=32;++i){
        if (!t[p][b[i]]) t[p][b[i]]=++tot;
        p=t[p][b[i]];
    }
    ed[p]=num;
}

void search(int num,int cmd){
    int x=a[num],y=32,p=1;
    memset(b,0,sizeof b);
    for (;x;x>>=1) b[y--]=x%2;
    for (int i=1;i<=32;++i){
        if (!t[p][b[i]^1]) p=t[p][b[i]];
            else p=t[p][b[i]^1];
    }
    cmd==0?l[num]=max(l[num-1],a[ed[p]]^a[num]):r[num]=max(r[num+1],a[ed[p]]^a[num]);
}

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;++i) scanf("%d",&a[i]),a[i]^=a[i-1];
    insert(0);
    for (int i=1;i<=n;++i){
        insert(i);
        search(i,0);
    }
    memset(t,0,sizeof t); tot=1;
    memset(ed,0,sizeof ed);
    insert(0);
    for (int i=n;i;--i){
        insert(i);
        search(i,1);
    }
    for (int i=1;i<n;++i) ans=max(ans,l[i]+r[i+1]);
    printf("%d",ans);
    return 0;
}