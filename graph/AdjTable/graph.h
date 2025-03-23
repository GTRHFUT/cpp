#pragma once
#include"node.h"
#define MaxNumVertex 100

class graph
{
public:
    graph();    //初始化
    ~graph();   //析构
    void insertvertex(const int v);  //插入顶点(数值)
    void deletevertex(const int v);  //删除顶点及其关联边（数值）
    void insertedge(const int v1, const int v2); //插入从顶点v1到顶点v2的边或弧（数值）
    void deleteedge(const int v1, const int v2); //删除从顶点v1到顶点v2的边或弧（数值）
    void Travel_DFS();   //整个图的深度优先搜索
    void Travel_BFS();   //整个图的广度优先搜索
    void dfs(int v);   //从顶点v开始的深度优先搜索（序号）
    void bfs(int v);   //从顶点v开始的广度优先搜索（序号）
    int locatevertex(const int v);  //定位顶点v在顶点数组中的位置（参数为顶点数值，返回值为序号）
    int firstadj(const int v);  //返回顶点v的第一个邻接顶点（参数和返回值都是序号）
    int nextadj(const int v, const int w);  //返回顶点v的邻接顶点w的下一个邻接顶点（都是序号）
    int degree(const int v);    //返回顶点v的度数（序号）
    bool visited[MaxNumVertex + 1];  //访问标志数组
private:
    int currentvertex;  //当前顶点数目
    Node* vertex[MaxNumVertex];        //顶点表
};