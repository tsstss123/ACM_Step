#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef long long int ll;
const int maxn = 100100;
int sz;
struct seg{
	int l,r,id;
	bool operator<(const seg &rhs)const{
		return (l / sz == rhs.l / sz ? r < rhs.r : l /sz < rhs.l / sz);
	}
}q[maxn];
int n,m,k,a[maxn];
int cnt[4000000],l,r;
ll Ans[maxn],ans;
inline void add(int x){ans += cnt[a[x] ^ k]; cnt[a[x]]++;}
inline void del(int x){cnt[a[x]]--; ans -= cnt[a[x] ^ k];}
int main(){
	scanf("%d%d%d",&n,&m,&k); sz = sqrt(n);
	rep(i,1,n){
		scanf("%d",&a[i]);
		a[i] ^= a[i-1];
	}
	rep(i,1,m){
		scanf("%d%d",&q[i].l,&q[i].r); --q[i].l; q[i].id = i;
	}
	sort(q+1,q+m+1);
	add(0);
	rep(i,1,m){
		while(q[i].l < l)add(--l);
		while(q[i].r > r)add(++r);
		while(q[i].l > l)del(l++);
		while(q[i].r < r)del(r--);
		Ans[q[i].id] = ans;
	}
	rep(i,1,m)printf("%I64d\n",Ans[i]);
	return 0;
}
//19759358	2016-08-10 09:02:20	tansongsong	617E - XOR and Favorite Number	GNU C++11	Accepted	405 ms	20000 KB
