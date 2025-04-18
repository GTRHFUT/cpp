#include "HuffmanTree.h"
HuffmanTree::HuffmanTree(int data)
{
    root = new bnode(data);
}
void HuffmanTree::destroyTree(bnode* node)
{
    if (node)
    {
        destroyTree(node->lchild);
        destroyTree(node->rchild);
        delete node;
    }
}
bnode *HuffmanTree::get_root() const
{
    return root;
}
void HuffmanTree::createHuffmanTree(HuffmanTree *trees, int n)
{
    int i = 0;
    while (i < n - 1)
    {
        std::sort(trees + i, trees + n, [](const HuffmanTree& a, const HuffmanTree& b)
                  { return a.root->data < b.root->data; });
        
        // 创建新节点
        bnode* new_node = new bnode(trees[i].root->data + trees[i + 1].root->data);
        new_node->lchild = trees[i].root;
        new_node->rchild = trees[i + 1].root;
        
        // 将当前位置的root置为nullptr，防止被析构时重复删除
        // trees[i].root = nullptr;
        trees[i + 1].root = new_node;
        
        i++;
    }
}
void HuffmanTree::CodeHuffmanTree(bnode *node, std::string code)
{
    if (node)
    {
        node->code = code;
        CodeHuffmanTree(node->lchild, code + "0");
        CodeHuffmanTree(node->rchild, code + "1");
    }
}
void HuffmanTree::printLeaf(bnode* node)const
{
    if(node){
        if(!node->lchild && !node->rchild){
            std::cout << node->data << " : " << node->code << std::endl;
        }
        printLeaf(node->lchild);
        printLeaf(node->rchild);
    }
}
void HuffmanTree::printCode() const
{
    printLeaf(root);
}