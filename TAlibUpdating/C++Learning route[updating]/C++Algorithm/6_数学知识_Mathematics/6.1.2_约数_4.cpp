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
        // 辗转相除，直到小括号内右边数为 0
        while (b)
        {
            int c = a % b;
            // 小括号左边放除数，右边放约数
            a = b;
            b = c;
        }
        // 小括号内左边数为最大公约数
        cout << a << endl;
    }
}