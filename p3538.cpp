#include<cstdio>
#include<cmath>
using namespace std;
const int N=5e5+5;
int sum[N][26],n,q,a[26],b[N],m;
unsigned long long f1[N],p1[N],f2[N],p2[N];
char s[N];

template<typename T>
inline void read(T &x){
    char ch=getchar(); x=0;
    for (;ch<'0' || ch>'9';ch=getchar());
    for (;ch>='0' && ch<='9';ch=getchar()) x=x*10+(ch^48);
}

inline int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

inline void divide(int x){
    m=0;
    int top=0,s[N];
    for (register int i=1,ed=sqrt(x);i<=ed;++i)
        if (x%i==0){
            b[++m]=i;
            if (i*i!=x) s[++top]=x/i;
        }
    while (top) b[++m]=s[top--];
}

int main(){
    read(n);
    scanf("%s",s+1);
    read(q);
    for (register int i=1;i<=n;++i)
        for (register int j=0;j<26;++j)
        if (s[i]-'a'==j) sum[i][j]=sum[i-1][j]+1;
            else sum[i][j]=sum[i-1][j];
    p1[0]=p2[0]=1;
    for (register int i=1;i<=n;++i){
        f1[i]=f1[i-1]*131+s[i];
        p1[i]=p1[i-1]*131;
        f2[i]=f2[i-1]*1331+s[i];
        p2[i]=p2[i-1]*1331;
    }
    for (register int i=1,l,r;i<=q;++i){
        read(l); read(r);
        int ans=-1;
        for (register int j=0;j<26;++j) a[j]=sum[r][j]-sum[l-1][j];
        for (register int j=0;j<26;++j) if (a[j]){ans=a[j]; break;}
        for (register int j=0;j<26;++j) if (a[j]) ans=gcd(ans,a[j]);
        divide(ans);
        for (int j=m;j;--j){
            int len=(r-l+1)/b[j];
            if (f1[r-len]-f1[l-1]*p1[r-len-l+1]==f1[r]-f1[l+len-1]*p1[r-l-len+1] && f2[r-len]-f2[l-1]*p2[r-len-l+1]==f2[r]-f2[l+len-1]*p2[r-l-len+1]){printf("%d\n",len); break;}
        }
    }
    return 0;
}