// 记忆化搜索
#include <iostream>
#include <cstring>

using namespace std;

const int N = 307;

int a[N], s[N];
int f[N][N];

// 记忆化搜索：dp的记忆化递归实现
int dp(int i, int j) {
    if (i == j) return 0; // 判断边界
    int &v = f[i][j];

    if (v != -1) return v;

    v = 1e8;
    for (int k = i; k <= j - 1; k ++)
        v = min(v, dp(i, k) + dp(k + 1, j) + s[j] - s[i - 1]);

    return v;
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        s[i] += s[i - 1] + a[i];
    }

    memset(f, -1, sizeof f);

    cout << dp(1, n) << endl;

    return 0;
}