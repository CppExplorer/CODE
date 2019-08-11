#include<bits/stdc++.h>
using namespace std;
const int N=150005;
int T,n,m,x[N],y[N],c[N],sa[N],rk[N],height[N],ct,mx[N],mn[N],sum[N];
char s[N];
bool vis[N];

void GetSA(){
    memset(c,0,sizeof c);
    for (int i=1;i<=n;++i) c[x[i]=s[i]]++;
    for (int i=1;i<=m;++i) c[i]+=c[i-1];
    for (int i=n;i;--i) sa[c[x[i]]--]=i;
    for (int k=1;k<=n;k<<=1){
        int num=0;
        for (int i=n-k+1;i<=n;++i) y[++num]=i;
        for (int i=1;i<=n;++i) if (sa[i]>k) y[++num]=sa[i]-k;
        for (int i=0;i<=m;++i) c[i]=0;
        for (int i=1;i<=n;++i) c[x[i]]++;
        for (int i=1;i<=m;++i) c[i]+=c[i-1];
        for (int i=n;i;--i) sa[c[x[y[i]]]--]=y[i],y[i]=0;
        swap(x,y);
        x[sa[1]]=1; num=1;
        for (int i=2;i<=n;++i)
            x[sa[i]]=(y[sa[i]]==y[sa[i-1]] && y[sa[i]+k]==y[sa[i-1]+k]?num:++num);
        if (num==n) break;
        m=num;
    }
}

void GetHeight(){
    for (int i=1;i<=n;++i) rk[sa[i]]=i,height[i]=0;
    int k=0;
    for (int i=1;i<=n;++i){
        if (rk[i]==1) continue;
        if (k) k--;
        int j=sa[rk[i]-1];
        while (j+k<=n && i+k<=n && s[i+k]==s[j+k]) k++;
        height[rk[i]]=k;
    }
}

bool check(int l){
    int num=0;
    for (int i=1;i<=n;++i){
        if (height[i]<l){
            for (int j=1;j<=ct;++j){
                mx[j]=-INT_MAX; mn[j]=INT_MAX; vis[j]=0; num=0;
            }

        }else{
            if (height[i-1]<l){
                int pos=-1;
                for (int j=1;j<=ct;++j)
                    if (sum[j-1]+1<sa[i-1] && sum[j]>=sa[i-1]){pos=j; break;}
                if (pos!=-1){
                    mx[pos]=max(mx[pos],n-sa[i-1]+1);
                    mn[pos]=min(mn[pos],n-sa[i-1]+1);
                    if (mx[pos]-mn[pos]>=l){
                        if (!vis[pos]) num++;
                        if (num==ct) return true;
                        vis[pos]=1;
                    }
                }
            }
            int pos=-1;
            for (int j=1;j<=ct;++j)
                if (sum[j-1]+1<sa[i] && sum[j]>=sa[i]){pos=j; break;}
            if (pos!=-1){
                mx[pos]=max(mx[pos],n-sa[i]+1);
                mn[pos]=min(mn[pos],n-sa[i]+1);
                if (mx[pos]-mn[pos]>=l){
                    if (!vis[pos]) num++;
                    if (num==ct) return true;
                    vis[pos]=1;
                }
            }
        }
    }
    return false;
}

int main(){
    scanf("%d",&T);
    while (T--){
        int l1=1,r=INT_MAX;
        scanf("%d",&ct);
        for (int i=1;i<=ct;++i){
            s[l1]=i;
            scanf("%s",s+1+l1);
            l1=strlen(s+1); sum[i]=l1++;
            r=min(r,sum[i]-sum[i-1]);
        }
        n=strlen(s+1); m=255;
        //for (int i=1;i<=ct;++i) printf("%d ",sum[i]);
        //printf("\n");
        //printf("%d %s\n",n,s+1);
        GetSA(); GetHeight();
        int l=0;
        while (l<r){
            int mid=(l+r+1)>>1;
            if (check(mid)) l=mid;
                else r=mid-1;
        }
        printf("%d\n",l);
    }
    return 0;
}