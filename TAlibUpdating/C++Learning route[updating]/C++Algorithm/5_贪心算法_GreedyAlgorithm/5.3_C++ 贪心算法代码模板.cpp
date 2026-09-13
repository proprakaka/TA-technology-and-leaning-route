#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 根据实际问题自定义数据结构，例如活动或任务
struct Item {
    int start;  // 起始时间（或其他衡量指标）
    int finish; // 结束时间（或其他衡量指标）
};

// 比较函数用于排序，这里以 finish 作为关键指标进行升序排序
bool compareByFinish(const Item &a, const Item &b) {
    return a.finish < b.finish;
}

int main() {
    // 示例输入：构造任务或活动数组
    vector<Item> items = {
        {1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 9}, {5, 9}, {6, 10}, {8, 11}, {8, 12}, {2, 14}, {12, 16}
    };

    // 第一步：排序，根据具体问题定义比较策略
    sort(items.begin(), items.end(), compareByFinish);

    // 第二步：初始化贪心算法的状态
    vector<Item> selected;  // 用于保存选中的元素（解）
    selected.push_back(items[0]);  // 通常先选取一个初始元素

    // 第三步：循环判断、贪心选择操作
    for (size_t i = 1; i < items.size(); i++) {
        // 例如：若当前活动的开始时间不早于上一次选择活动的结束时间，则可以选择该活动
        if (items[i].start >= selected.back().finish) {
            selected.push_back(items[i]);
        }
    }

    // 输出结果
    cout << "选中的活动数: " << selected.size() << endl;
    for (const auto &act : selected) {
        cout << "活动: (" << act.start << ", " << act.finish << ")" << endl;
    }

    return 0;
}