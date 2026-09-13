// f[i][j] = f[i - 1][j] + f[i][j - i]
#include <iostream>

using namespace std;

const int N = 1e3 + 7, mod = 1e9 + 7;

int f[N][N];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i <= n; i ++) {
        f[i][0] = 1; // 容量为0时，前 i 个物品全不选也是一种方案
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j <= n; j ++) {
            f[i][j] = f[i - 1][j] % mod; // 特殊 f[0][0] = 1
            if (j >= i) f[i][j] = (f[i - 1][j] + f[i][j - i]) % mod;
        }
    }

    cout << f[n][n] << endl;
}