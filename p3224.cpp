#include<cstdio>
using namespace std;
const int N=1e5+5;
int n,m,a[N],tot,root[N],fa[N],q;
char cmd;
struct SegmentTree{
	int l,r,val,size;
}t[N<<5];

int father(int x){
	return fa[x]==x?x:fa[x]=father(fa[x]);
}

void insert(int p,int l,int r,int x,int val){
	if (l==r){
		t[p].val+=val;
		t[p].size=1;
		return;
	}
	int mid=(l+r)>>1;
	if (x<=mid){
		if (!t[p].l) t[p].l=++tot;
		insert(t[p].l,l,mid,x,val);
	}else{
		if (!t[p].r) t[p].r=++tot;
		insert(t[p].r,mid+1,r,x,val);
	}
	t[p].size=t[t[p].l].size+t[t[p].r].size;
}

int Merge(int p,int q,int l,int r){
	if (!p) return q;
	if (!q) return p;
	if (l==r){
		t[p].val+=t[q].val;
		t[p].size+=t[q].size;
		return p;
	}
	int mid=(l+r)>>1;
	t[p].l=Merge(t[p].l,t[q].l,l,mid);
	t[p].r=Merge(t[p].r,t[q].r,mid+1,r);
	t[p].size=t[t[p].l].size+t[t[p].r].size;
	return p;
}

int query(int p,int l,int r,int x){
	if (t[p].size<x || !p) return -1;
	if (l==r) return t[p].val;
	int mid=(l+r)>>1;
	if (t[t[p].l].size>=x) return query(t[p].l,l,mid,x);
		else return query(t[p].r,mid+1,r,x-t[t[p].l].size);
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i) scanf("%d",&a[i]);
	for (int i=1;i<=n;++i) root[i]=++tot,fa[i]=i;
	for (int i=1;i<=n;++i) insert(root[i],1,n,a[i],i);
	for (int i=1,x,y;i<=m;++i){
		scanf("%d%d",&x,&y);
		int u=father(x),v=father(y);
		fa[v]=u;
		root[u]=Merge(root[u],root[v],1,n);		
	}
	scanf("%d",&q);
	for (int i=1,x,y;i<=q;++i){
		scanf("\n%c%d%d",&cmd,&x,&y);
		if (cmd=='B'){
			int u=father(x),v=father(y);
			if (u!=v){
				fa[v]=u;
				root[u]=Merge(root[u],root[v],1,n);
			}
		}else{
			int u=father(x);
			printf("%d\n",query(root[u],1,n,y));
		}
	}
	return 0;
}