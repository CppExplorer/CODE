#include<bits/stdc++.h>
using namespace std;
int m,n,k,i,c[400005],ans[100005];
struct node{
    int x,y,z,cnt,ans;
}a[100005],b[100005];

int lowbit(int x){
    return x&(-x);
}

void add(int x,int y){
    while (x<=k){
        c[x]+=y;
        x+=lowbit(x);
    }
}

int ask(int x){
    int res=0;
    while (x){
        res+=c[x];
        x-=lowbit(x);
    }
    return res;
}

bool cmpx(node a,node b){
    if (a.x==b.x){
        if (a.y==b.y) return a.z<b.z;
        return a.y<b.y;
    }
    return a.x<b.x;
}

bool cmpy(node a,node b){
    if (a.y==b.y) return a.z<b.z;
    return a.y<b.y;
}

void cdq(int l,int r){
    if (l==r) return;
    int mid=(l+r)/2;
    cdq(l,mid);
    cdq(mid+1,r);
    sort(a+l,a+mid+1,cmpy);
    sort(a+mid+1,a+r+1,cmpy);
    int j=l;
    for (int i=mid+1;i<=r;++i){
        while (a[j].y<=a[i].y && j<=mid){
            add(a[j].z,a[j].cnt);
            j++;
        } 
        a[i].ans+=ask(a[i].z);
    }
    for (int i=l;i<j;++i)
        add(a[i].z,-a[i].cnt);
}

int main(){
    scanf("%d%d",&m,&k);
    for (i=1;i<=m;++i) scanf("%d%d%d",&b[i].x,&b[i].y,&b[i].z);
    sort(b+1,b+1+m,cmpx);
    int c=0;
    for (i=1;i<=m;++i){
        c++;
        if (b[i].x!=b[i+1].x || b[i].y!=b[i+1].y || b[i].z!=b[i+1].z){
            n++; a[n]=b[i]; a[n].cnt=c; c=0;
        }
    }
    cdq(1,n);
    for (i=1;i<=n;++i)
        ans[a[i].ans+a[i].cnt-1]+=a[i].cnt;
    for (i=0;i<m;++i) printf("%d\n",ans[i]);
    return 0;
}