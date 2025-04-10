#include <iostream>
#include <stack>
// 非递归版本的 P 函数
void P_iterative(int W)
{
    struct task
    {
        int W;
        int Label;
        task(int W, int Label) : W(W), Label(Label) {}
    };

    std::stack<task> s;
L0:
    if (W > 0)
    {
        s.push({W, 1});
        W = W - 1;
        goto L0;
    L1:

        s.push({W, 2});
        W = W - 1;
        goto L0;
    L2:

        std::cout << W << " ";
    }
    if (!s.empty())
    {
        task top = s.top();
        s.pop();
        W = top.W;
        if (top.Label == 1)
        {
            goto L1;
        }
        else
        {
            goto L2;
        }
    }
}
// ---- 用于对比的原始递归函数 ----
void P_recursive(int W)
{
    if (W > 0)
    {
        P_recursive(W - 1);
        P_recursive(W - 1);
        std::cout << W << " ";
    }
}
