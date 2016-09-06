#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int maxn = 2e5 + 10, maxa = 1e6 + 10;
int n,t,a[maxn];
int sz,l,r; // block size
struct seg{
    int l,r,id;
    bool operator < (const seg &rhs) const{
        return (l / sz == rhs.l / sz ? r < rhs.r : l / sz < rhs.l / sz);
    }
}q[maxn];
int cnt[maxa];ll sum,ans[maxn];
inline void add(int pos){sum += 1LL * a[pos] * (2 * cnt[a[pos]] + 1); cnt[a[pos]]++;}
inline void del(int pos){sum -= 1LL * a[pos] * (2 * cnt[a[pos]] - 1); cnt[a[pos]]--;}
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> t; sz = sqrt(n);
    for(int i = 1; i <= n; ++i)cin >> a[i];
    for(int i = 1; i <= t; ++i){
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    sort(q+1,q+t+1);
    for(int i = 1; i <= t; ++i){
        while(q[i].l < l)add(--l);
        while(q[i].r > r)add(++r);
        while(q[i].l > l)del(l++);
        while(q[i].r < r)del(r--);
        ans[q[i].id] = sum;
    }
    for(int i = 1; i <= t; ++i)cout << ans[i] << endl;
    return 0;
}
