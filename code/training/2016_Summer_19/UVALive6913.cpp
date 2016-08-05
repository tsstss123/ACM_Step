#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int maxn = 2100;
int n,m,k,ct[maxn],p;
char str[maxn];
int dp[maxn][maxn];
int dfs(int i,int j){
	if(dp[i][j] != -1)return dp[i][j];
	if(ct[i] * k >= j)return dp[i][j]=1;
	for(int t=ct[i];t<=ct[i]*k;++t)
		if(!dfs(i+1,j-t))return dp[i][j]=1;
	return dp[i][j] = 0;
}
int main(){
	int T; scanf("%d",&T);
	rep(cas,1,T){
		scanf("%d%d%d%s",&n,&m,&k,str);
		p = 1; n *= 2;
		ct[1] = 1;
		for(int i=1;i<n;++i)
			if(str[i] != str[i-1]){
				++p;
				ct[p] = 1;
			}else
				++ct[p];
		memset(dp,-1,sizeof(dp));
		int s = dfs(1,m); 
		char c ;
		if(s)c = str[0];
		else c = (str[0]=='A' ? 'B':'A');
		printf("Case #%d: %c\n",cas,c );
	}
	return 0;
}
/*
题意:有N个A组的和N个B组人混在一起站成一排(顺序由题目给出),有M块蛋糕,每个人最多可以买K块最少买一块.问如果两队人足够聪明哪个队能获胜

博弈DP
如果是经典的AB轮流拿取的DP很好做.这里只需要把连续的相同队伍的人压缩成一个,拿取的范围[1,K]->[c,c*K],记忆化搜索即可
 */
