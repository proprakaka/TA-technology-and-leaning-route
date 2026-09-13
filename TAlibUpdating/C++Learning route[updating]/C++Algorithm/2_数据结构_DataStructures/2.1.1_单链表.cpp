#include <iostream>

using namespace std;

const int N = 100010;

// head是头指针
// e[i]表示节点i的值
// ne[i]表示节点i的next指针
// idx表示当前已经用到的点
int head, e[N], ne[N], idx;

// 初始化链表为空
void init()
{
    head = -1;
    idx = 0;
}

// 新节点插入到头节点的位置
void add_to_head(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx++;
}

// 新节点插入到下标为k的节点后面
void add_to_k(int k, int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}

// 单链表删除操作
void remove(int k)
{
    ne[k] = ne[ne[k]];
}

int main()
{
    int m;
    cin >> m;

    init();

    while (m--)
    {
        int k, x;
        char op;

        cin >>op;
        if (op == 'H')
        {
            cin >> x;
            add_to_head(x);
        }
        else if (op == 'D')
        {
            cin >> k;
            if (!k)
                head = ne[head];
            remove(k - 1);
        }
        else
        {
            cin >> k >> x;
            add_to_k(k - 1, x);
        }
    }

    for (int i = head; i != -1; i = ne[i])
    {
        cout << e[i] << ' ';
    }
    cout << endl;

    return 0;
}