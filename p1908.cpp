#include<cstdio>
#include<algorithm>
using namespace std;
const int N=5e5+5;
int n,a[N],b[N],c[N],t[N],tot;
long long ans;

template<typename T>
inline void read(T &x){
    char ch=getchar(); bool f=0; x=0;
    for (;ch<'0' || ch>'9';ch=getchar()) f=(ch=='-');
    for (;ch>='0' && ch<='9';ch=getchar()) x=x*10+(ch^48);
    x=f?-x:x;
}

inline int query(int x){
    return upper_bound(c+1,c+1+tot,x)-c-1;//如果找不到a[i]-1,就会返回a[i]离散化后的值，所以要用upper_bound-1
}

inline int lowbit(int x){
    return x&(-x);
}

inline void add(int x,int val){
    for (;x<=n;x+=lowbit(x)) t[x]+=val;
}

inline int ask(int x){
    int ans=0;
    for (;x;x-=lowbit(x)) ans+=t[x];
    return ans;
}

int main(){
    // freopen("a.in","r",stdin);
    read(n);
    for (int i=1;i<=n;++i) read(a[i]),b[i]=a[i];
    sort(b+1,b+1+n);
    for (int i=1;i<=n;++i)
        if (i==1 || b[i]!=b[i-1]) c[++tot]=b[i];
    for (int i=n;i;--i){
        ans+=ask(query(a[i]-1));
        add(query(a[i]),1);
    }
    printf("%lld",ans);
    return 0;
}