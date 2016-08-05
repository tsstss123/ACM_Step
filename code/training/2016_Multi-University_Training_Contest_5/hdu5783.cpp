#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n,a[1010000];
int main(){
	while(scanf("%d",&n)==1){
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		ll sum = 0; int ans = 0;
		for(int i=n;i;--i){
			sum += a[i];
			if(sum >= 0){
				sum = 0;
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
题意:
1e6长度的整数串,最长能分成多少段能够使得每一段的所有前缀和非负

贪心.考虑到只有负数出现才会使得某一段长度大于1,所以等价于倒过来把序列分成每一段之和非负的段数
 */
