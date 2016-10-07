//由知乎https://www.zhihu.com/question/29580448
//统计1-n内有多少素数
#include <bits/stdc++.h>
inline long long V2IDX(long long v, long long N, long long Ndr, long long nv) {
    return v >= Ndr ? (N/v - 1) : (nv - v);
}

long long getsum(long long N) {
    long long *S;
    long long *V;

    long long r = (long long)sqrt(N);
    long long Ndr = N/r;

    assert(r*r <= N and (r+1)*(r+1) > N);

    long long nv = r + Ndr - 1;

    V = new long long[nv];
    S = new long long[nv];

    for (long long i=0; i<r; i++) {
        V[i] = N/(i+1);
    }
    for (long long i=r; i<nv; i++) {
        V[i] = V[i-1] - 1;
    }

    for (long long i=0; i<nv; i++) {
        S[i] = V[i] - 1;
    }

    for (long long p=2; p<=r; p++) {
        if (S[nv-p] > S[nv-p+1]) {
            long long sp = S[nv-p+1];
            long long p2 = p*p;
            for (long long i=0; i<nv; i++) {
                if (V[i] >= p2) {
                    S[i] -= (S[V2IDX(V[i]/p, N, Ndr, nv)] - sp);
                } else {
                    break;
                }
            }
        }
    }

    return S[0];
}

int main() {
    long long N = 1000000000LL;
    std::cout << getsum(N) << std::endl;
}
