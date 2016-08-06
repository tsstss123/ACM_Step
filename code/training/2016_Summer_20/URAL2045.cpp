#include <cstdio>
#include <algorithm>
#include <cstring>

int n;

int main() {
	scanf("%d", &n);
	if (n == 1) {
		printf("1 : a\n");
		return 0;
	}
	if (n == 2) {
		printf("1 : NO\n");
		printf("2 : ab\n");
		return 0;
	}
	printf("1 : NO\n");
	printf("2 : NO\n");
	for (int i = 3; i <= n; i++) {
		printf("%d : ", i);
		for (int j = 1; j <= i - 2; j++) putchar('a');
		char now = 'b';
		for (int j = i - 1; j <= n; j++) {
			putchar(now);
			if (now == 'b') now = 'c';
			else if (now == 'c') now = 'a';
			else if (now == 'a') now = 'b';
		} 
		printf("\n");
	}
	return 0;
}
/*
题意:
给你一个n,要你构造出n个长度为n的字符串,要求第i个字符串恰好有i个本质不同的回文串,若该字符串不存在则当前位置输出NO

前i-2个由连续的'a'来构造,后面由'abc'循环构造,可以保证后面不产生长度超过1的回文串
*/
