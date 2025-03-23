#include <iostream>
#include "graph.h"
#include "queue.h"
using namespace std;

graph::graph()
{
    // 初始化元素个数
    currentvertex = 0;
    // 初始化访问数组
    for (int i = 1; i <= MaxNumVertex; i++)
    {
        visited[i] = false;
    }
}
graph::~graph()
{
    for (int i = 0; i < currentvertex; i++)
    {
        Node *current = vertex[i];
        while (current != nullptr)
        {
            Node *temp = current->next;
            delete current;
            current = temp;
        }
        currentvertex--;
    }
}
void graph::insertvertex(const int v)
{
    if (currentvertex < MaxNumVertex)
    {
        Node *newnode = new Node;
        newnode->data = v;
        newnode->next = nullptr;
        vertex[currentvertex++] = newnode;
        return;
    }
    cout << "graph is full!" << endl;
}
void graph::deletevertex(const int v)
{
    bool find = false;
    // 顶点数组变更
    for (int i = 0; i < currentvertex - 1; i++)
    {
        if (vertex[i]->data == v)
        {
            find = true;
            vertex[i] = vertex[i + 1];
        }
    }
    if (!find)
    {
        cout << v << " doesn't exist!" << endl;
        return;
    }
    // 变更各个顶点的邻接表
    currentvertex--;

    for (int i = 0; i < currentvertex; i++)
    {
        Node *current = vertex[i];
        while (current->next != nullptr && current->next->data != v)
        {
            current = current->next;
        }
        if (current->next == nullptr)
        {
            continue;
        }
        Node *temp = current->next;
        current->next = temp->next;
        delete temp;
    }
}
void graph::insertedge(const int v1, const int v2)
{
    int j;
    int findcount = 0;
    for (int i = 0; i < currentvertex; i++)
    {
        if (vertex[i]->data == v1 || vertex[i]->data == v2)
        {
            if (vertex[i]->data == v1)
            {
                j = i;
            }
            findcount++;
        }

        if (findcount == 2)
        {
            Node *newnode = new Node;
            newnode->data = v2;
            newnode->next = nullptr;

            Node *lastptr = vertex[j];
            while (lastptr->next != nullptr)
            {
                lastptr = lastptr->next;
            }
            lastptr->next = newnode;
            return;
        }
    }
    cout << v1 << " or " << v2 << " don't exist!" << endl;
}
void graph::deleteedge(const int v1, const int v2)
{
    for (int i = 0; i < currentvertex; i++)
    {
        if (vertex[i]->data == v1)
        {
            Node *lastptr = vertex[i];
            while (lastptr->next != nullptr && lastptr->next->data != v2)
            {
                lastptr = lastptr->next;
            }

            if (lastptr->next == nullptr)
            {
                cout << v2 << " doesn't exist!" << endl;
                return;
            }

            Node *temp = lastptr->next;
            lastptr->next = temp->next;
            delete temp;
            return;
        }
    }
    cout << v1 << " doesn't exist!" << endl;
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
        {
            bfs(i);
        }
    }
    cout << endl;
}
void graph::dfs(const int v)
{
    int w;
    cout << vertex[v - 1]->data << " ";
    visited[v] = true;
    w = firstadj(v);
    while (w != 0)
    {
        if (visited[w] == false)
        {
            dfs(w);
        }
        w = nextadj(v, w);
    }
}
void graph::bfs(const int v)
{
    int w;
    queue q;
    cout << vertex[v - 1]->data << " ";
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
                cout << vertex[w - 1]->data << " ";
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
        if (vertex[i]->data == v)
        {
            return i + 1;
        }
    }
    return 0;
}
int graph::firstadj(const int v)
{
    // 返回顶点v的下一个邻接点，如果没有，则返回0
    if (v < 1 || v > currentvertex)
    {
        cout << "Illegal Number input!" << endl;
        return 0;
    }
    if (vertex[v - 1]->next == nullptr)
    {
        return 0;
    }
    int val = vertex[v - 1]->next->data;
    for (int i = 0; i < currentvertex; i++)
    {
        if (vertex[i]->data == val)
        {
            return i + 1;
        }
    }
    return 0;
}
int graph::nextadj(const int v, const int w)
{
    // 返回顶点v的邻接点w之后的那个邻接点，如果没有，则返回0
    if (v < 1 || v > currentvertex || w < 1 || w > currentvertex)
    {
        cout << "Illegal Number input!" << endl;
        return 0;
    }
    int val = vertex[w - 1]->data;
    Node *current = vertex[v - 1];
    while (current != nullptr && current->data != val)
    {
        current = current->next;
    }
    if (current == nullptr || current->next == nullptr)
    {
        return 0;
    }
    int nextval = current->next->data;
    for (int i = 0; i < currentvertex; i++)
    {
        if (vertex[i]->data == nextval)
        {
            return i + 1;
        }
    }
    return 0;
}
int graph::degree(const int v)
{
    if (v > currentvertex || v < 1)
    {
        return -1;
    }

    int inDegree = 0;
    int outDegree = 0;
    Node *current = vertex[v - 1]->next;
    // 计算出度
    while (current != nullptr)
    {
        outDegree++;
        current = current->next;
    }
    // 计算入度
    for (int i = 0; i < currentvertex; i++)
    {
        current = vertex[i]->next;
        while (current != nullptr)
        {
            if (current->data == vertex[v - 1]->data)
            {
                inDegree++;
                break;
            }
            current = current->next;
        }
    }
    return inDegree + outDegree;
}
