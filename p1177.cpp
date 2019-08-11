//基数排序
#include<bits/stdc++.h>
using namespace std;
/*基数为10
const int N=100005;
int n,a[N],ep,maxn,t[N],c[N];

void radix_sort(){
    memset(c,0,sizeof c);
    for (int i=1;i<=n;++i) c[(a[i]/ep)%10]++;
    for (int i=1;i<=n;++i) c[i]+=c[i-1];
    for (int i=n;i;--i) t[c[(a[i]/ep)%10]--]=a[i];
    for (int i=1;i<=n;++i) a[i]=t[i];
}

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        maxn=max(maxn,a[i]);
    }
    for (ep=1;maxn/ep>=1;ep*=10) radix_sort();
    for (int i=1;i<=n;++i) printf("%d ",a[i]);
    return 0;
}
*/
//基数为$2^8$
const int N=3e7+5,radix=1<<8;
int n,c1[radix],c2[radix],c3[radix],c4[radix],b[N];
unsigned int a[N];

void radix_sort(){
    for (int i=1;i<=n;++i){
        c1[a[i]&(radix-1)]++;
        c2[(a[i]>>8)&(radix-1)]++;
        c3[(a[i]>>16)&(radix-1)]++;
        c4[(a[i]>>24)]++;
    }
    for (int i=1;i<radix;++i){
        c1[i]+=c1[i-1];
        c2[i]+=c2[i-1];
        c3[i]+=c3[i-1];
        c4[i]+=c4[i-1];
    }
    for (int i=n;i;--i) b[c1[a[i]&(radix-1)]--]=a[i];
    for (int i=n;i;--i) a[c2[(b[i]>>8)&(radix-1)]--]=b[i];
    for (int i=n;i;--i) b[c3[(a[i]>>16)&(radix-1)]--]=a[i];
    for (int i=n;i;--i) a[c4[b[i]>>24]--]=b[i];
}

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;++i) scanf("%u",&a[i]);
    radix_sort();
    for (int i=1;i<=n;++i) printf("%u ",a[i]);
    return 0;
}