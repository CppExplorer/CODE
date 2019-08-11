#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,k,m;
long long w[N],ans;
struct heap{
    long long val;
    int h;
    heap(long long _val=0,int _h=0){
        val = _val, h = _h;
    }
    bool operator <(const heap &b) const{
        return val==b.val ? h>b.h : val>b.val;
    }
};

priority_queue<heap> h;

int main(){
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;++i){
        scanf("%lld",&w[i]);
        h.push(heap(w[i],1));
    }
    while ((n-1)%(k-1)!=0){
        n++; h.push(heap(w[n],1));
    }
    while (h.size()>=k){
        long long sum=0; int maxh=0;
        for (int i=1;i<=k;++i){
            sum+=h.top().val;
            maxh=max(maxh,h.top().h);
            h.pop();
        }
        h.push(heap(sum,maxh+1));
        ans+=sum;
    }
    printf("%lld\n%d",ans,h.top().h-1);
    return 0;
}