#include<bits/stdc++.h>
using namespace std;
int n,i,l,p[8000005],ans;
char s[2000005];
bool vis[8000005];

void manacher(){
    char t[8000005];
    for (int i=0;i<n;++i){
        t[2*i+1]=s[i];
        t[2*i]='$';
    }
    int len=strlen(t);
    t[len]='$'; len++;
    int r=0,mid=0;
    for (int i=0;i<len;++i){
        if (i<r) p[i]=min(r-i,p[2*mid-i]);
            else p[i]=1;
        while (i-p[i]>=0 && i+p[i]<len && t[i-p[i]]==t[i+p[i]])p[i]++;
        if (i+p[i]>r){
            r=i+p[i];
            mid=i;
        }
    }
    for (int i=0;i<len;++i)
        if (p[i]-1>=l && i%2==1 && !vis[i]){
            ans++;
            vis[i]=1; vis[i+n]=1;
        }
}

int main(){
    scanf("%d%d%s",&n,&l,s);
    for (i=0;i<n;++i) s[i+n]=s[i];
    n=n*2;
    manacher();
    printf("%d",ans);
    return 0;
}