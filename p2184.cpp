#include<cstdio>
using namespace std;
const int N=1e5+5;
int n,m;
/*
1.只要一个区间的开头在一个节点i的左边，那么这个区间包含在区间1~i中。
2.只要一个区间的尾部在一个节点j的左边，那么这个区间肯定不属于j之后的所有区间
*/
struct BinaryIndexedTree{
    int c[N];
    inline int lowbit(int x){
        return x&(-x);
    }
    inline void add(int x,int val){
        for (;x<=n;x+=lowbit(x)) c[x]+=val;
    }
    inline int ask(int x){
        int ans=0;
        for (;x;x-=lowbit(x)) ans+=c[x];
        return ans;
    }
}l,r;

int main(){
    scanf("%d%d",&n,&m);
    for (int i=1,cmd,x,y;i<=m;++i){
        scanf("%d%d%d",&cmd,&x,&y);
        if (cmd==1) l.add(x,1),r.add(y,1);
            else printf("%d\n",l.ask(y)-r.ask(x-1));
    }
    return 0;
}