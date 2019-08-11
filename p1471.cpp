#include<bits/stdc++.h>
using namespace std;
int n,m,i,opt,x,y;
double a[100005],ans,avg,sum,k;
struct SegmentTree{
    int l,r;
    double sum,add,ss;
}t[400005];

void build(int x,int l,int r){
    t[x].l=l; t[x].r=r;
    if (l==r){
        t[x].sum=a[l];
        t[x].ss=a[l]*a[l];
        return;
    }
    int mid=(l+r)/2;
    build(x*2,l,mid);
    build(x*2+1,mid+1,r);
    t[x].sum=t[x*2].sum+t[x*2+1].sum;
    t[x].ss=t[x*2].ss+t[x*2+1].ss;
}

void spread(int x){
    if (t[x].add){
        t[x*2].ss+=2*t[x].add*t[x*2].sum+(t[x*2].r-t[x*2].l+1)*t[x].add*t[x].add;
        t[x*2+1].ss+=2*t[x].add*t[x*2+1].sum+(t[x*2+1].r-t[x*2+1].l+1)*t[x].add*t[x].add;
        t[x*2].sum+=t[x].add*(t[x*2].r-t[x*2].l+1);
        t[x*2+1].sum+=t[x].add*(t[x*2+1].r-t[x*2+1].l+1);
        t[x*2].add+=t[x].add;
        t[x*2+1].add+=t[x].add;
        t[x].add=0;
    }
}

void change(int x,int l,int r,double d){
    if (l<=t[x].l && r>=t[x].r){
        t[x].ss+=2*d*t[x].sum+(t[x].r-t[x].l+1)*d*d;
        t[x].sum+=d*(t[x].r-t[x].l+1);
        t[x].add+=d;
        return;
    }
    spread(x);
    int mid=(t[x].l+t[x].r)/2;
    if (l<=mid) change(x*2,l,r,d);
    if (r>mid) change(x*2+1,l,r,d);
    t[x].sum=t[x*2].sum+t[x*2+1].sum;
    t[x].ss=t[x*2].ss+t[x*2+1].ss;
}

double askavg(int x,int l,int r){
    if (l<=t[x].l && r>=t[x].r) return t[x].sum;
    spread(x);
    double val=0;
    int mid=(t[x].l+t[x].r)/2;
    if (l<=mid) val+=askavg(x*2,l,r);
    if (r>mid) val+=askavg(x*2+1,l,r);
    return val;
}

double askvar(int x,int l,int r){
    if (l<=t[x].l && r>=t[x].r) return t[x].ss;
    spread(x);
    double val=0;
    int mid=(t[x].l+t[x].r)/2;
    if (l<=mid) val+=askvar(x*2,l,r);
    if (r>mid) val+=askvar(x*2+1,l,r);
    return val;
}

int main(){
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;++i) scanf("%lf",&a[i]);
    build(1,1,n);
    for (i=1;i<=m;++i){
        scanf("%d%d%d",&opt,&x,&y);
        if (opt==1){
            scanf("%lf",&k);
            change(1,x,y,k);
        }else if (opt==2){
            ans=askavg(1,x,y)/(y-x+1);
            printf("%.4lf\n",ans);
        }else{
            sum=askavg(1,x,y);
            avg=sum/(y-x+1);
            ans=(askvar(1,x,y)-2*avg*sum+(y-x+1)*avg*avg)/(y-x+1);
            printf("%.4lf\n",ans);
        }
    }
    return 0;
}