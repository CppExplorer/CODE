#include<bits/stdc++.h>
using namespace std;
int n,m,c,a[100005],l[320],r[320],i,t,sum[320][100005],f[320][320],ans,pos[100005],ct[100005];

int ask(int L,int R){
    if (L>R) swap(L,R);
    int p=pos[L],q=pos[R],res=0;
    if (p==q){
        for (int i=L;i<=R;++i){
            ct[a[i]]++;
            if (!(ct[a[i]]&1)) res++;
                else if (ct[a[i]]>2) res--;
        } 
        for (int i=L;i<=R;++i) ct[a[i]]--;
        return res;
    }else{
        res=f[p+1][q-1];
        for (int i=L;i<=r[p];++i){
            ct[a[i]]++;
            if (!((ct[a[i]]+sum[q-1][a[i]]-sum[p][a[i]])&1)) res++;
                else if ((ct[a[i]]+sum[q-1][a[i]]-sum[p][a[i]])>2) res--;
        }
        for (int i=l[q];i<=R;++i){
            ct[a[i]]++;
            if (!((ct[a[i]]+sum[q-1][a[i]]-sum[p][a[i]])&1)) res++;
                else if ((ct[a[i]]+sum[q-1][a[i]]-sum[p][a[i]])>2) res--;
        }
        for (int i=L;i<=r[p];++i) ct[a[i]]--;
        for (int i=l[q];i<=R;++i) ct[a[i]]--;
        return res;
    }
}

int main(){
    scanf("%d%d%d",&n,&c,&m);
    for (i=1;i<=n;++i) scanf("%d",&a[i]);
    t=(int)sqrt(n);
    for (i=1;i<=t;++i){
        l[i]=(i-1)*t+1;
        r[i]=i*t;
    }
    if (r[t]<n){
        t++; l[t]=r[t-1]+1; r[t]=n;
    }
    for (i=1;i<=t;++i)
        for (int j=l[i];j<=r[i];++j)
        pos[j]=i,sum[i][a[j]]++;
    for (i=1;i<=t;++i)
        for (int j=1;j<=c;++j)
        sum[i][j]+=sum[i-1][j];
    for (i=1;i<=t;++i){
        int tot=0;
        for (int j=l[i];j<=n;++j){
            ct[a[j]]++;
            if (!(ct[a[j]]&1)) tot++;
                else if (ct[a[j]]>2) tot--;
            f[i][pos[j]]=tot;
        }
        for (int j=l[i];j<=n;++j) ct[a[j]]--;
    }
    int L,R;
    for (i=1;i<=m;++i){
        scanf("%d%d",&L,&R);
        ans=ask((L+ans)%n+1,(R+ans)%n+1);
        printf("%d\n",ans);
    }
    return 0;
}