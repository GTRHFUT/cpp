#include <iostream>
#include "graph.h"
#include "queue.h"
using namespace std;

graph::graph()
{
    // 初始化元素个数
    currentvertex = 0;
    // 初始化访问标识数组
    for (int i = 1; i <= MaxNumVertex; i++)
    {
        visited[i] = false;
    }
    // 初始化各边（弧）不相连
    for (int i = 0; i < MaxNumVertex; i++)
    {
        for (int j = 0; j < MaxNumVertex; j++)
        {
            edge[i][j] = 0;
        }
    }
}
graph::~graph()
{
}
void graph::insertvertex(const int v)
{
    if (currentvertex < MaxNumVertex)
        vertex[currentvertex++] = v;
    else
        cout << "graph is full!" << endl;
}
void graph::deletevertex(const int v)
{
    int i;
    for (i = 0; i < currentvertex; i++)
    {
        if (vertex[i] == v)
            break;
        if (i == currentvertex - 1)
        {
            cout << v << " doesn't exist!" << endl;
            return;
        }
    }
    // 调整顶点数组vertex(删除v)
    for (int j = i; j < currentvertex - 1; j++)
    {
        vertex[j] = vertex[j + 1];
    }
    // 调整边关系数组(删除v相关的行和列)
    // 删除行
    for (int j = i; j < currentvertex - 1; j++)
    {
        for (int k = 0; k < currentvertex; k++)
        {
            edge[j][k] = edge[j + 1][k];
        }
    }
    // 删除列
    for (int j = 0; j < currentvertex - 1; j++)
    {
        for (int k = i; k < currentvertex - 1; k++)
        {
            edge[j][k] = edge[j][k + 1];
        }
    }
    // 顶点数-1
    currentvertex--;
}
void graph::insertedge(const int v1, const int v2)
{
    int j, k;
    int findcount = 0;
    for (int i = 0; i < currentvertex; i++)
    {
        if (vertex[i] == v1 || vertex[i] == v2)
        {
            if (vertex[i] == v1)
            {
                j = i;
            }
            else
            {
                k = i;
            }
            findcount++;
        }
        if (findcount == 2)
        {
            edge[j][k] = 1;
            return;
        }
    }
    cout << v1 << " or " << v2 << " don't exist!" << endl;
}
void graph::deleteedge(const int v1, const int v2)
{
    int j, k;
    int findcount = 0;
    for (int i = 0; i < currentvertex; i++)
    {
        if (vertex[i] == v1 || vertex[i] == v2)
        {
            if (vertex[i] == v1)
            {
                j = i;
                findcount++;
            }
            else
            {
                k = i;
                findcount++;
            }
        }
        if (findcount == 2)
        {
            edge[j][k] = 0;
            return;
        }
    }
    cout << v1 << " or " << v2 << " don't exist!" << endl;
}
void graph::Travel_DFS()
{
    for (int i = 1; i <= currentvertex; i++)
    {
        visited[i] = false;
    }
    for (int i = 1; i <= currentvertex; i++)
    {
        if (visited[i] == false)
        {
            dfs(i);
        }
    }
    cout << endl;
}
void graph::Travel_BFS()
{
    for (int i = 1; i <= currentvertex; i++)
    {
        visited[i] = false;
    }
    for (int i = 1; i <= currentvertex; i++)
    {
        if (visited[i] == false)
            bfs(i);
    }
    cout << endl;
}
void graph::dfs(int v) // 序号
{
    cout << vertex[v - 1] << " ";
    visited[v] = true;
    int w = firstadj(v);
    while (w != 0)
    {
        if (visited[w] == false)
            dfs(w);
        w = nextadj(v, w);
    }
}
void graph::bfs(int v)
{
    int w;
    queue q;
    cout << vertex[v - 1] << " ";
    visited[v] = true;
    q.append(v);
    while (!q.empty())
    {
        int x;
        q.get_front(x);
        q.serve();
        w = firstadj(x);
        while (w != 0)
        {
            if (visited[w] == false)
            {
                cout << vertex[w - 1] << " ";
                visited[w] = true;
                q.append(w);
            }
            w = nextadj(x, w);
        }
    }
}
int graph::locatevertex(const int v)
{
    for (int i = 0; i < currentvertex; i++)
    {
        if (vertex[i] == v)
            return i + 1;
    }
    cout << v << " doesn't exist!" << endl;
    return 0;
}
int graph::firstadj(const int v)
{
    for (int i = 0; i < currentvertex; i++)
    {
        if (edge[v - 1][i] == 1)
            return i + 1;
    }
    return 0;
}
int graph::nextadj(const int v, const int w)
{
    for (int i = w; i < currentvertex; i++)
    {
        if (edge[v - 1][i] == 1)
            return i + 1;
    }
    return 0;
}
int graph::degree(const int v)
{
    if (v > currentvertex)
    {
        cout << v << " doesn't exist!" << endl;
        return -1;
    }

    int degree = 0;

    for (int i = 0; i < currentvertex; i++)
    {
        // 出度+入度
        if (edge[v - 1][i] == 1 || edge[i][v - 1] == 1)
            degree++;
    }
    return degree;
}
