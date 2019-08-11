#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,k,t,l[40],r[40],pos[40005],tot,mn[40][40],x,y,last,cnt,num,p,q,P,Q;
int a[40005],fa[40005],fb[40005],b[40005],c[40][40][40005],f[40][40];

void update(int i){
    c[P][Q][b[i]]++;
    if (c[P][Q][b[i]]>cnt || (c[P][Q][b[i]]==cnt && b[i]<num)){
        cnt=c[P][Q][b[i]];
        num=b[i];
    }
}

int ask(int x,int y){
    if (x>y){
        int z=x; x=y; y=z;
    }
    p=pos[x],q=pos[y];
    if (p+1<=q-1){
        P=p+1; Q=q-1;
    }else P=Q=0;
    cnt=f[P][Q]; num=mn[P][Q];
    if (p==q){
        for (int i=x;i<=y;++i) update(i);
        for (int i=x;i<=y;++i) c[P][Q][b[i]]--;
    }else{
        for (int i=x;i<=r[p];++i) update(i);
        for (int i=l[q];i<=y;++i) update(i);
        for (int i=x;i<=r[p];++i) c[P][Q][b[i]]--;
        for (int i=l[q];i<=y;++i) c[P][Q][b[i]]--;
    }
    return fb[num];
}

int main(){
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;++i) scanf("%d",&a[i]);
    t=(int)pow(n*1.0,1.0/3.0);
    int ln=n/t;
    for (i=1;i<=t;++i){
        l[i]=(i-1)*ln+1;
        r[i]=i*ln;
    }
    if (r[t]<n){
        t++; l[t]=r[t-1]+1; r[t]=n;
    }
    for (i=1;i<=t;++i)
        for (j=l[i];j<=r[i];++j) pos[j]=i;
    memcpy(fa,a,sizeof a);
    sort(fa+1,fa+1+n);
    for (i=1;i<=n;++i)
        if (fa[i]!=fa[i+1]){
            tot++; fb[tot]=fa[i];
        }
    for (i=1;i<=n;++i) b[i]=lower_bound(fb+1,fb+1+tot,a[i])-fb;
    for (i=1;i<=t;++i)
        for (j=1;j<=t;++j){
            for (k=l[i];k<=r[j];++k) c[i][j][b[k]]++;
            for (k=1;k<=tot;++k)
                if (c[i][j][k]>f[i][j] || (c[i][j][k]==f[i][j] && k<mn[i][j])){
                    f[i][j]=c[i][j][k];
                    mn[i][j]=k;
                }
        }
    for (i=1;i<=m;++i){
        scanf("%d%d",&x,&y);
        last=ask((x+last-1)%n+1,(y+last-1)%n+1);
        printf("%d\n",last);
    }
    return 0;
}