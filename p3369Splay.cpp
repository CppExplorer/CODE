#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int cmd,n,x,i,root,val[N],ch[N][2],f[N],cnt[N],size[N],m;

void clear(int x){
    val[x]=ch[x][0]=ch[x][1]=f[x]=cnt[x]=size[x]=0;
}

void update(int x){
    size[x]=size[ch[x][0]]+size[ch[x][1]]+cnt[x];
}

int get(int x){
    return ch[f[x]][1]==x;
}

void rotate(int x){
    int fa=f[x],gfa=f[fa],lr=get(x);
    ch[fa][lr]=ch[x][lr^1]; f[ch[fa][lr]]=fa;
    ch[x][lr^1]=fa; f[fa]=x;
    ch[gfa][ch[gfa][1]==fa]=x; f[x]=gfa;
    update(fa); update(x);
}

void splay(int x){
    while (f[x]){
        if (f[f[x]]){
            if (get(x)^get(f[x])) rotate(x);
                else rotate(f[x]);
        }
        rotate(x);
    }
    root=x;
}

void insert(int x){
    int now=root,fa=0;
    while (now && val[now]!=x){
        fa=now;
        now=ch[now][x>val[now]];
    }
    if (!now){
        m++; val[m]=x; cnt[m]=size[m]=1; f[m]=fa;
        if (fa) ch[fa][x>val[fa]]=m;
        now=m;
    }else{
        cnt[now]++; update(now);
    }
    splay(now);
}

int GetRank(int x){
    int now=root,ans=1;
    while (1){
        if (val[now]==x){
            ans+=size[ch[now][0]];
            splay(now);
            return ans;
        }
        if (x<val[now]) now=ch[now][0];
            else{
                ans+=size[ch[now][0]]+cnt[now];
                now=ch[now][1];
            }
    }
}

int GetPre(){
    int ans=ch[root][0];
    while (ch[ans][1]) ans=ch[ans][1];
    return ans;
}

int GetNext(){
    int ans=ch[root][1];
    while (ch[ans][0]) ans=ch[ans][0];
    return ans;
}

int GetVal(int rank){
    int now=root,ans=0;
    while (1){
        if (ans+size[ch[now][0]]>=rank) now=ch[now][0];
            else{
                if (ans+size[ch[now][0]]+cnt[now]>=rank) return val[now];
                ans+=size[ch[now][0]]+cnt[now];
                now=ch[now][1];
            }
    }
}

void remove(int val){
    int xx=GetRank(val);
    if (cnt[root]>1){
        cnt[root]--; size[root]--;
        return;
    }
    if (!ch[root][0] && !ch[root][1]){
        clear(root);
        root=0;
        return;
    }
    if (!ch[root][0]){
        xx=root; root=ch[root][1]; f[root]=0; clear(xx); return;
    }
    if (!ch[root][1]){
        xx=root; root=ch[root][0]; f[root]=0; clear(xx); return;
    }
    int old=root,root=GetPre();
    splay(root);
    ch[root][1]=ch[old][1]; f[ch[root][1]]=root;
    clear(old);
    update(root);
}

int main(){
    scanf("%d",&n);
    for (i=1;i<=n;++i){
        scanf("%d%d",&cmd,&x);
        switch (cmd){
            case 1:
                insert(x);
                break;
            case 2:
                remove(x);
                break;
            case 3:
                printf("%d\n",GetRank(x));
                break;
            case 4:
                printf("%d\n",GetVal(x));
                break;
            case 5:
                insert(x);
                printf("%d\n",val[GetPre()]);
                remove(x);
                break;
            case 6:
                insert(x);
                printf("%d\n",val[GetNext()]);
                remove(x);
                break;
        }
    }
    return 0;
}