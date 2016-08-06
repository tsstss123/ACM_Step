#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long int ll;
const int mod = 997;
vector<pii> v;
int n,m,k;
ll fac[1000] = {1,1}, ans[1000];
ll pw(ll a,ll p){
	if(p == 0)return 1; if(p == 1)return a % mod;
	ll t = pw(a,p/2); t = t * t;
	if(p & 1LL) t = t * a % mod;
	return t % mod;
}
ll c(int n,int m){
	if(n < m)return 0;
	if(n < mod)return fac[n] * pw(fac[n-m] * fac[m] % mod, mod - 2) % mod;
	return c(n%mod,m%mod) * c(n/mod,m/mod) % mod;
}
int main(){
	int T; scanf("%d",&T);
	rep(i,2,999)fac[i] = (fac[i-1] * i) % mod; 
	rep(cas,1,T){
		scanf("%d%d%d",&n,&m,&k);
		v.clear();
		rep(i,1,k){
			int x,y; scanf("%d%d",&x,&y);
			v.pb({x+1,y-1}); v.pb({x+1,y}); v.pb({x+1,y+1});
			v.pb({x,y-1}); v.pb({x,y}); v.pb({x,y+1});
			v.pb({x-1,y-1}); v.pb({x-1,y}); v.pb({x-1,y+1});
		}
		v.pb({n,m});
		sort(v.begin(),v.end());
		rep(i,0,v.size() - 1){
			int x = v[i].first, y = v[i].second;
			ans[i] = c(x + y - 2, x - 1);
			rep(j,0,i-1){
				int nx = v[j].first, ny = v[j].second;
				if(ny > y) continue;
				ans[i] = ((ans[i] - ans[j] * c(x + y - nx - ny,x - nx)) % mod + mod) % mod;
			}
		}
		printf("Case #%d: %lld\n", cas, ans[v.size()-1]);
	}
	return 0;
}
/*
题意:
在一个n*m的棋盘上你要从左上角走到右下角,只能向下或者向右走.棋盘中有最多90个点有障碍物不能通过,问总共有多少方案,对997取模

Lucas定理计算组合数+容斥原理
考虑从左上某一点走到右下某一点若不存在障碍物时的方案数量C(x2-x1+y2-y1,x2-x1)
在所有障碍点之后加上一个点(n,m),双关键字排序
定义ans[i]为从左上角不经过i之前的点到达第i个点的方案数量,即ans[终点]为所求答案.对于终点也为障碍点的情况亦能够兼容处理
由于这个定义的存在,初始化ans[i] = C(xi+yi-2,xi-1),计算时只要减去每个可以到达i的ans[j]*C(,)即可算出ans[i]
 */
