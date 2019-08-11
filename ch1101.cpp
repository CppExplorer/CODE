#include<bits/stdc++.h>
using namespace std;
int n,cnt,A[25],B[25],a,b;

void dfs(int k){
    if (cnt==20) return;
    if (a==n && b==0){
        for (int i=1;i<=a;++i) printf("%d",A[i]);
        printf("\n");
        cnt++;
        return;
    }
    if (b){
        A[++a]=B[b--];
        dfs(k);
        if (cnt==20) return;
        B[++b]=A[a--];
    }
    if (k<=n){
        B[++b]=k;
        dfs(k+1);
        if (cnt==20) return;
        b--;
    }
}

int main(){
    scanf("%d",&n);
    dfs(1);
    return 0;
}