#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N],n,t[N*31][2],tot=1,tail[N*31],b[32],ans;

void insert(int num){
    int x=a[num],y=31,p=1;
    memset(b,0,sizeof b);
    while (x){
        b[y--]=x%2;
        x>>=1;
    }
    for (int i=1;i<=31;++i){
        if (!t[p][b[i]]) t[p][b[i]]=++tot;
        p=t[p][b[i]];
    }
    tail[p]=num;
}

void search(int num){
    int x=a[num],y=31,p=1;
    memset(b,0,sizeof b);
    while (x){
        b[y--]=x%2;
        x>>=1;
    }
    for (int i=1;i<=31;++i){
        if (!t[p][b[i]^1]) p=t[p][b[i]];
            else p=t[p][b[i]^1];
        if (tail[p]) ans=max(ans,a[tail[p]]^a[num]);
        if (!p) return;
    }
}

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        search(i);
        insert(i);
    }
    printf("%d",ans);
    return 0;
}