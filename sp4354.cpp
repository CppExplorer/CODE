#include<cstdio>
using namespace std;
const int p=99991,N=1000000;
int n,a[7],head[N],nxt[N],tot,snow[N][6];

int H(int a[]){
    int sum=0,mul=1;
    for (int i=0;i<6;++i){
        sum=(sum+a[i])%p;
        mul=((long long)mul*a[i])%p;
    }
    return (sum+mul)%p;
}

bool equal(int a[],int b[]){
    for (int i=0;i<6;++i)
        for (int j=0;j<6;++j){
            bool flag=1;
            for (int k=0;k<6;++k)
                if (a[(i+k)%6]!=b[(j+k)%6]) flag=0;
			if (flag) return true;
			flag=1;
            for (int k=0;k<6;++k)
                if (a[(i+k)%6]!=b[(j-k+6)%6]) flag=0;
			if (flag) return true;
        }
	return false;
}

bool insert(int a[]){
    int val=H(a);
    for (int i=head[val];i;i=nxt[i])
        if (equal(snow[i],a)) return true;
    tot++;
    for (int i=0;i<6;++i)
        snow[tot][i]=a[i];
    nxt[tot]=head[val];
    head[val]=tot;
	return false;
}

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        for (int j=0;j<6;++j) scanf("%d",&a[j]);
        if (insert(a)){
            printf("Twin snowflakes found.");
            return 0;
        }
    }
    printf("No two snowflakes are alike.");
    return 0;
}