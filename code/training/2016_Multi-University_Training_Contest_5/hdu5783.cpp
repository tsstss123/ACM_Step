#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
#define mid ((l+r)/2)
const int maxn = 100010;
int n,m;
string s;
int ch[maxn][26],tot,bel[maxn];
int ls[maxn*40],rs[maxn*40],cnt[maxn*40],rt[maxn],stot;
//seg tree
inline void upd(int rt){
	cnt[rt] = cnt[ls[rt]] + cnt[rs[rt]];
}
void build(int &rt,int l,int r){
	rt = ++stot;
	if(l == r)return ;
	build(ls[rt],l,mid);
	build(rs[rt],mid+1,r);
}
void modify(int &rt,int l,int r,int lst,int x,int det){
	rt = ++stot; ls[rt] = ls[lst]; rs[rt] = rs[lst];
	if(l == r){
		cnt[rt] = cnt[lst] + det;
		return ;
	}
	if(x<=mid)modify(ls[rt],l,mid,ls[lst],x,det);
	else modify(rs[rt],mid+1,r,rs[lst],x,det);
	upd(rt);
}
int query(int rt,int l,int r,int L,int R){
	if(L <= l && r <= R){
		return cnt[rt];
	}
	int ret = 0;
	if(L<=mid)ret += query(ls[rt],l,mid,L,R);
	if(R >mid)ret += query(rs[rt],mid+1,r,L,R);
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	while(cin >> n){
		tot = 0; stot = 0;
		memset(cnt,0,sizeof(cnt));
		memset(ch[0],0,sizeof(ch[0]));
		build(rt[0],1,n);
		rep(i,1,n){
			cin >> s;
			rt[i] = rt[i-1];
			int id = 0;
			for(int j = 0; j < s.size(); ++j){
				int c = s[j] - 'a';
				if(ch[id][c]){
					modify(rt[i],1,n,rt[i],bel[ch[id][c]],-1);
					bel[ch[id][c]] = i;
				}else{
					ch[id][c] = ++tot;
					memset(ch[tot],0,sizeof(ch[tot]));
					bel[tot] = i;
				}
				id = ch[id][c];
			}
			modify(rt[i],1,n,rt[i],i,s.size());
		}
		cin >> m;
		int l,r,z = 0;
		rep(i,1,m){
			cin >> l >> r;
			l = (l + z) % n + 1; r = (r + z) % n + 1;
			if(r < l)swap(l,r);
			z = query(rt[r],1,n,l,r);
			cout << z << endl;
		}
	}
	return 0;
}
//17924907	2016-08-04 20:05:47	Accepted	5790	2636MS	41768K	1720B	G++	Orz WJMZBMR

/*
题意:给出n个字符串,编号从1-n,每次强制在线询问区间[l,r]的所有字符串有多少不同的前缀串

Trie+主席树.把字符串顺序插入一个Trie,即每个节点都代表一个前缀.开一个数组存一下这个前缀属于哪个字符串,如果改变的话(新插入的字符串走过了这个点)就将原字符串所在的串在主席树内减1.
查询就是在root[r]里面查询sum(l,r)不需要作差.
 */
