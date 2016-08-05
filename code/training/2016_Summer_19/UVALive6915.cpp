#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
const int maxn = 1010000;
int height,n,m,h[maxn],s[maxn],k;
ll S[maxn];
char str[maxn];
pii que[maxn];int head,tail;
int main(){
	int T; scanf("%d",&T);
	rep(cas,1,T){
		scanf("%d%d",&n,&m);
		k = (int)((log(m))/log(2.0));
		height = 0; S[0] = 0;
		scanf("%s",str);
		rep(i,1,n){
			char c = str[i-1];
			h[i] = height;
			if(c == '/'){
				S[i] = S[i-1] + 2 * height + 1;
				++height;
				s[i] = 0;
			}else if(c == '\\'){
				--height; 
				S[i] = S[i-1] + 2 * height + 1;
				-- h[i];
				s[i] = 1;
			}else if(c == '_'){
				S[i] = S[i-1] + 2 * height;
				s[i] = 2;
			}	
		}
		head = tail = 0;
		ll sum = 0, ans = 1e18; // count double score
		rep(i,1,n){
			sum = S[i] - S[i-m];
			while(head < tail && que[head].first <= i-m)head++;
			while(head < tail && que[tail-1].second >= h[i])--tail;
			que[tail] = make_pair(i,h[i]); tail++;
			if(i >= m){
				int hei = que[head].second;
				ll cst = sum - 1LL * m * hei * 2; 
				ans = min(ans,cst);
			}

		}
		printf("Case #%d: %.1f\n",cas,ans / 2.0 );
	}

	return 0;
}
/*
题意:给出一个地面的描述,要你挖一个K长度的坑

手推,前缀和作差统计即可

Trick:要维护连续前K个中的最小值,平常写ST这里会TLE,要用**单调队列**
 */
