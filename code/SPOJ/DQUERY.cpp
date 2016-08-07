#include <bits/stdc++.h>
#include <unordered_map>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define mid ((l+r)/2)
using namespace std;
const int BUFFER_MAX_SIZE = 100000;
struct Quick_In{
	char buf[BUFFER_MAX_SIZE], *ps = buf, *pe = buf + 1;
	inline void InNext(){
		if(++ps == pe)
			pe = (ps = buf) + fread(buf, sizeof(char), sizeof(buf) / sizeof(char), stdin);
	}
	template<class T>
	inline bool operator()(T &number){
		number = 0;
		T f = 1;
		if(ps == pe)return false; // EOF
		do {
			InNext();
			if('-' == *ps) f = -1;
		}while(!isdigit(*ps) && ps != pe);
		if(ps == pe) return false;
		do {
			number = (number << 1) + (number << 3) + *ps - 48;
			InNext();
		}while(isdigit(*ps) && ps != pe);
		number *= f;
		return true;
	}
} In;
struct Quick_Out{
	char buf[BUFFER_MAX_SIZE], *ps = buf, *pe = buf + BUFFER_MAX_SIZE;
	inline void write(){
		fwrite(buf, sizeof(char), ps - buf, stdout);
		ps = buf;
	}
	inline void oc(char c){
		*(ps++) = c;
		if(ps == pe) write();
	}
	inline void os(char *s){
		for(int i = 0; s[i]; ++i) oc(s[i]);
	}
	template<class T>
	inline void oi(T x){
		if(!x) {
			oc('0');
			return ;
		}
		if(x < 0) oc('-'), x = -x;
		char tmp[30];
		int len = 0;
		while(x){
			tmp[len++] = x % 10 + '0';
			x /= 10;
		}
		while(len){
			--len;
			oc(tmp[len]);
		}
	}
	~Quick_Out(){write();}
} Out;
const int maxn = 30010;
int n,a[maxn],b[maxn];
int root[maxn],ls[maxn*40],rs[maxn*40],cnt[maxn*40],tot;
unordered_map<int,int> bel;
void build(int l,int r,int &rt){
	rt = ++tot;
	cnt[rt] = 0;
	if(l == r){
		return ;
	}
	build(l,mid,ls[rt]);build(mid+1,r,rs[rt]);
}
inline void mt(int rt){
	cnt[rt] = cnt[ls[rt]] + cnt[rs[rt]];
}
void modify(int x,int det,int l,int r,int &rt,int ort){
	rt = ++tot;
	ls[rt] = ls[ort]; rs[rt] = rs[ort]; cnt[rt] = cnt[ort];
	if(l == r){
		cnt[rt] += det;
		return ;
	}
	if(x<=mid)modify(x,det,l,mid,ls[rt],ls[rt]);
	else modify(x,det,mid+1,r,rs[rt],rs[rt]);
	mt(rt);
}
int query(int L,int R,int l,int r,int rt){
	if(L <= l && r <= R){
		return cnt[rt];
	}
	int ret = 0;
	if(L<=mid)ret += query(L,R,l,mid,ls[rt]);
	if(R >mid)ret += query(L,R,mid+1,r,rs[rt]);
	return ret;
}
void getx(int &x){
	x = 0;char c = getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c)){
		x = x * 10 + (c - '0');
		c = getchar();
	}
}
int main(){
	In(n);
	rep(i,1,n){
		In(a[i]);
	}
	rep(i,1,n){
		root[i] = root[i-1];
		if(bel[a[i]]){
			modify(bel[a[i]],-1,1,n,root[i],root[i]);
		}
		bel[a[i]] = i;
		modify(i,1,1,n,root[i],root[i]);
	}
	int m; In(m);
	rep(i,1,m){
		int l,r;
		In(l); In(r);
		int ans = query(l,r,1,n,root[r]);
		Out.oi(ans);Out.oc('\n');
	}
	return 0;
}
/*
17453992	2016-08-07 12:52:45	Tan song	D-query	accepted 0.29	18M	C++14
题意:
3w长度的整数序列,20w的询问某个区间(l,r)内有多少个不同的整数

用unordered_map + 读入挂 + 主席树
用主席树维护一个bel[x]表示x这个数最后一次出现在哪个位置
注意不需要先建立一棵完整的树
 */
