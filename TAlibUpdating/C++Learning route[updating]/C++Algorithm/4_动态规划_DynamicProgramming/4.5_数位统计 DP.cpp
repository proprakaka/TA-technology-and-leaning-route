#include <iostream>
#include <vector>

using namespace std;

int base[10];
int f[10][10];
int g[10][10];

void init()
{
    base[0] = 1;
    for(int i = 1 ; i <= 9 ; i++) base[i] = base[i-1]*10;

    //从00……0 - 99……9 的各位数字有多少个，其中i为数字个数（包含前导零）
    for(int i = 0 ; i <= 9 ; i++) f[1][i] = 1;
    for(int i = 2 ; i <= 9 ; i++)
        for(int j = 0 ; j <= 9 ; j++)
            f[i][j] = f[i-1][j]*10 + base[i-1];

    //从1 - 99……9 的各位数字有多少个，其中i为数字个数（不包含前导零）
    for(int i = 1 ; i <= 9 ; i++) g[1][i] = 1;//循环从1开始
    for(int i = 2 ; i <= 9 ; i++) {
        g[i][0] = g[i-1][0] + f[i-1][0]*9;
        for(int j = 1 ; j <= 9 ; j++)
            g[i][j] = g[i-1][j] + f[i-1][j]*9 + base[i-1];
    }
}

vector<int> dp(int n)
{
    vector<int> ans(10,0); //记录答案
    if(n<=0) return ans; //边界条件

    vector<int> nums;
    while(n) nums.push_back(n%10), n/=10;

    vector<int> last(10,0); //记录前缀中各个数字个数

    //统计1 - 99……9(n-1个9)里面各个数字有多少个
    for(int i = 0 ; i <= 9 ; i++) ans[i] = g[nums.size()-1][i];
    //统计大于10……0(n-1个0) 的树里各个数字有多少个
    for(int i = nums.size()-1 ; i >=0 ; i--) {
        //循环变量i可以表示剩下的数字有多少个
        int x = nums[i];
        for(int j = i==nums.size()-1 ; j < x ; j++) { //第一次循环不能有0
            //前缀部分
            for(int k = 0 ; k <= 9 ; k++)
                ans[k] += last[k] * base[i];
            //当前位置部分
            ans[j] += base[i];
            //后缀部分
            for(int k = 0 ; k <= 9 ; k++)
                ans[k] += f[i][k];
        }
        //更新前缀计数器
        last[x] ++;

        //统计叶子节点（这个数本身）
        if(!i) for(int k = 0 ; k <= 9 ; k++) ans[k] += last[k];
    }
    return ans;
}

vector<int> ask(int a, int b)
{
    auto x = dp(b);
    auto y = dp(a-1);
    vector<int> ans;
    for(int i = 0 ; i <= 9 ; i++) ans.push_back(x[i]-y[i]);
    return ans;
}

void print(vector<int> ans)
{
    for(auto x:ans) printf("%d ",x);
    puts("");
}

bool check(int x)
{
    auto t = ask(x,x);
    vector<int> cnt(10,0);
    while(x) cnt[x%10]++,x/=10;
    for(int i = 0 ; i <= 9 ; i++)
        if(cnt[i] != t[i])
            return false;
    return true;
}

int main()
{
    init();

    //这里是一个DEBUG函数
    // for(int i = 1 ; i <= 1000000 ; i*=10) {
    //     if(!check(i))
    //         printf("ERROR:%d\n",i);
    // }

    int a,b;
    while(cin >> a >> b, a||b) {
        if(a>b) swap(a,b);
        auto t = ask(a,b);
        print(t);
    }

    return 0;
}