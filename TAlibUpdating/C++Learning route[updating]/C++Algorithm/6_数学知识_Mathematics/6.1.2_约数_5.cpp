#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int a, b;
        cin >> a >> b;
        // a % b == 0，则 b 就是最大公约数，可以提前结束循环
        while (a % b)
        {
            int c = a % b;
            a = b;
            b = c;
        }
        cout << b << endl;
    }
}