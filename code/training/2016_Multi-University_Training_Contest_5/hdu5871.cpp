#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX_N 2222

double dp[MAX_N][MAX_N];

int n, m;

int main() {
    //freopen("haha.txt", "w", stdout);
    n = 2000;m = 12;
        for (int i = 1; i <= n; i++)
            for (int j = 2; j <= m; j++)
                dp[i][j] = 1e100;
        for (int i = 1; i <= m; i++)
            dp[1][i] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i][1] = ((double)i)/(i+1)*dp[i-1][1]+((double)1)/(i+1)*dp[0][1]+1.0;
            for (int j = 2; j <= m; j++)
                for (int k = 1; k <= i; k++) {
                    dp[i][j] = std::min(dp[i][j],
                    ((double)i-k+1)/(i+1)*dp[i-k][j]+((double)k)/(i+1)*dp[k-1][j-1]+1.0);
                }
        }
    while (scanf("%d%d", &n, &m) == 2) {
        if (m >= 12) m = 12;
        printf("%.6f\n", dp[n][m]);
    }
    return 0;
}
/*
题意:
你有一张银行卡,你不知道里面有多少钱,但知道不会超过K元(也就是说[0,K]之间均匀的概率分布),你的目标是取出所有的钱.
你每次可以向ATM机要求提款任意面额.如果失败了会被警告一次.被警告的次数不能超过W.问最优情况下取出所有钱的期望次数

概率DP
 */
