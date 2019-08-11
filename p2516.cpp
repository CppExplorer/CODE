#include<bits/stdc++.h>
#define M 100000000
using namespace std;
char s1[5005],s2[5005];
int n,m,f[2][5005],fa[2][5005];
int main(){
    scanf("%s%s",s1+1,s2+1);
    n=strlen(s1+1)-1; m=strlen(s2+1)-1;
	for (int i=0;i<=m;++i) fa[0][i]=1;
    fa[1][0]=1;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j){
            int x=i%2;
			f[x][j]=max(f[x^1][j],f[x][j-1]);
			fa[x][j]=0;
			if (s1[i]==s2[j]) f[x][j]=max(f[x][j],f[x^1][j-1]+1);
			if (f[x][j]==f[x][j-1]) fa[x][j]=(fa[x][j]+fa[x][j-1])%M;
			if (f[x][j]==f[x^1][j])	fa[x][j]=(fa[x][j]+fa[x^1][j])%M;
			if (s1[i]==s2[j] && f[x][j]==f[x^1][j-1]+1) fa[x][j]=(fa[x][j]+fa[x^1][j-1])%M;
			if (f[x][j]==f[x^1][j-1]) fa[x][j]=(fa[x][j]-fa[x^1][j-1]+M)%M;
        }
    printf("%d\n%d",f[n%2][m],fa[n%2][m]);
    return 0;
}