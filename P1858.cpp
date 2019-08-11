#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int m,n,v,val[205],c[205],f[5005][55],ans,cnt[5005],t[55];
int main(){
    scanf("%d%d%d",&m,&v,&n);
    for (int i=1;i<=n;++i) scanf("%d%d",&c[i],&val[i]);
    memset(f,-0x3f,sizeof f);
    f[0][1]=0; cnt[0]=1;
    for (int i=1;i<=n;++i)
        for (int j=v;j>=c[i];--j){
            int l=1,r=1,tot=0;
            for(int k=1;k<=min(m,cnt[j]+cnt[j-c[i]]);++k) {
                if (r>cnt[j] || (l<=cnt[j-c[i]] && f[j][r]<=f[j-c[i]][l]+val[i])) t[k]=f[j-c[i]][l++]+val[i];
                    else if (l>cnt[j-c[i]] || (r<=cnt[j] && f[j][r]>f[j-c[i]][l]+val[i])) t[k]=f[j][r++];
            }
            cnt[j]=min(m,cnt[j]+cnt[j-c[i]]);
            memcpy(f[j],t,sizeof(f[j]));
        }
    for (int i=1;i<=m;++i) ans+=f[v][i];    
    printf("%d",ans);
    return 0;       
}