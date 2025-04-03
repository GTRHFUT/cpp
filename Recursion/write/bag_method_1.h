// 背包问题：设有n个物品，其重量分别为w1，w2，w3，…，wn，
// 所有物品的重量之和≥背包所能放置的重量S。设计算法从中找出若干物品放入背包中，使得其重量之和正好为S 。
// 例如，S = 50, n = 10,  w = ( 29  26  18  16  13  10  8  5  3  1)
//(其中每一行为一个解。每一对数中，第一个为该元素在w中的序号，第二个为元素的值）：
//(1,29)  (3,18)  (9,3)
//(1,29)  (4,16)  (8,5)
//(1,29)  (5,13)  (7,8)
//(1,29)  (5,13)  (8,5)   (9,3)
//(1,29)  (6,10)  (7,8)   (9,3)
//(2,26)  (3,18)  (8,5)   (10,1)
//(2,26)  (4,16)  (7,8)
//(2,26)  (4,16)  (8,5)   (9,3)
//(2,26)  (5,13)  (6,10)  (10,1)
// ……….
#pragma once
#include <iostream>
struct bags
{
    int sequence;
    int weight;
};
const void print_bag(bags bags[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "(" << bags[i].sequence << "," << bags[i].weight << ")  ";
    }
    std::cout << std::endl;
}
void bag(int w[], int n, int S, int index, bags bags[], int size, int SS)
{
    if (SS == S)
    {
        print_bag(bags, size);
        return;
    }
    if (index < n && SS < S)
    {
        //先不装入，在装入

        /*bag(w, n, S, index + 1, bags, size, SS);
        bags[size].sequence = index + 1;
        bags[size].weight = w[index];
        bag(w, n, S, index + 1, bags, size + 1, SS + bags[size].weight);
        */

        //先装入，在不装入
        bags[size].sequence = index + 1;
        bags[size].weight = w[index];
        bag(w, n, S, index + 1, bags, size + 1, SS + bags[size].weight);
        bag(w, n, S, index + 1, bags, size, SS);
    }
}