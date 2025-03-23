#include <iostream>
#include "graph.h"
using namespace std;

int main()
{
    graph g;
    g.insertvertex(100);
    g.insertvertex(200);
    g.insertvertex(300);
    g.insertvertex(400);
    g.insertvertex(500);
    g.insertvertex(600);
    g.insertvertex(700);
    g.insertvertex(800);
    g.insertvertex(900);
    g.insertvertex(1000);

    g.insertedge(100, 200);
    g.insertedge(100, 800);
    g.insertedge(200, 300);
    g.insertedge(200, 400);
    g.insertedge(800, 900);
    g.insertedge(800, 1000);
    g.insertedge(400, 500);
    g.insertedge(400, 600);
    g.insertedge(400, 700);


    // g.insertedge(200, 100);
    // g.insertedge(800, 100);
    // g.insertedge(300, 200);
    // g.insertedge(400, 200);
    // g.insertedge(900, 800);
    // g.insertedge(1000, 800);
    // g.insertedge(500, 400);
    // g.insertedge(600, 400);
    // g.insertedge(700, 400);


    g.Travel_DFS();
    g.Travel_BFS();

    cout << g.degree(1) << endl;
    system("pause");
    return 0;
}