#include "HuffmanTree.h"
int main()
{
    HuffmanTree trees[] = {50, 40, 38, 32, 30, 25, 20, 15, 10, 3};
    int n = sizeof(trees) / sizeof(trees[0]);
    trees->createHuffmanTree(trees, n);
    trees[n - 1].CodeHuffmanTree(trees[n - 1].get_root(), "");
    trees[n - 1].printCode();
    trees[n - 1].destroyTree(trees[n - 1].get_root());
    system("pause");
    return 0;
}