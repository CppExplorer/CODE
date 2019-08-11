#include<bits/stdc++.h>
using namespace std;
int m,d,i,x,tot,t,dat[800005];
char c;

void change(int p,int l,int r,int x,int k){
    if (l==r){
        dat[p]=k;
        return;
    }
    int mid=(l+r)/2;
    if (x<=mid) change(p*2,l,mid,x,k);
        else change(p*2+1,mid+1,r,x,k);
    dat[p]=max(dat[p*2],dat[p*2+1])%d;
}

int ask(int p,int l,int r,int fl,int fr){
    if (l<=fl && r>=fr) return dat[p];
    int val=-INT_MAX,mid=(fl+fr)/2;
    if (l<=mid) val=max(val,ask(p*2,l,r,fl,mid));
    if (r>mid) val=max(val,ask(p*2+1,l,r,mid+1,fr));
    return val;
}
int main(){
    scanf("%d%d",&m,&d);
    for (i=1;i<=m;++i){
        scanf("\n%c%d",&c,&x);
        if (c=='A'){
            tot++;
            change(1,1,m,tot,(x+t)%d);
        }else{
            t=ask(1,tot-x+1,tot,1,m)%d;
            printf("%d\n",t);
        }
    }
    return 0;
}
