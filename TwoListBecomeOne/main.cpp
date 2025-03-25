// 单链表（带头结点）
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data, Node *next = nullptr) : data(data), next(next) {}
};

// 链表类
class list
{
public:
    list();
    ~list();
    int length() const { return count; } // 不算头结点
    Node *get_head() { return head; }
    void insert(const int i, const int x);
    void create_R(); // 表尾插入法建立链表
    void print();    // 打印链表
private:
    int count;
    Node *head;
};

list::list()
{
    head = new Node(-1); // 产生头结点
    count = 0;
}

list::~list()
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        count--;
    }
}

void list::insert(const int i, const int x)
{
    if (i < 1 || i > count + 1)
    {
        cout << "The position to be inserted is out of range and cannot be inserted" << endl;
    }
    else
    {
        Node *p = head;
        int j = 0;
        // 搜索第i-1个结点的位置
        while (j != i - 1)
        {
            p = p->next;
            j++;
        }
        Node *node = new Node(x, p->next);
        p->next = node;
        count++;
        cout << "Successfully incorporated elements" << x << "Insert the th into the linked list" << i << " node" << endl;
    }
}

void list::print()
{
    Node *p = head->next;
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void list::create_R()
{
    int x;
    cout << "Please enter the element you want to insert into the linked list. If you do not want to insert it, enter-1" << endl;
    cin >> x;
    Node *rear = head; // 设置尾指针
    while (x != -1)
    {
        count++;
        Node *node = new Node(x);
        rear->next = node;
        rear = node;
        cin >> x; // 读入下一个元素
    }
}

void getCommomElement(list &L1, list &L2, list& L3)
{
    Node *p1 = L1.get_head()->next;
    Node *p2 = L2.get_head()->next;
    while (p1 != nullptr && p2 != nullptr)
    {
        if (p1->data < p2->data)
        {
            p1 = p1->next;
        }
        else
        {
            if (p1->data > p2->data)
            {
                p2 = p2->next;
            }
            else
            {
                L3.insert(L3.length() + 1, p1->data);
                p1 = p1->next;
                p2 = p2->next;
            }
        }
    }
}

int main()
{
    list AL1, AL2, AL3;
    cout << "Please enter the data for the first set of tests" << endl;
    cout << "The first linked list element is (1, 3, 6, 10, 15, 16, 17, 18, 19, 20)" << endl;
    cout << "The second linked list element is (1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 18, 20, 30)" << endl;
    cout << "Create the first linked list" << endl;
    AL1.create_R();
    cout << "Create the second linked list" << endl;
    AL2.create_R();
    getCommomElement(AL1, AL2, AL3);
    cout << "A linked list composed of common elements:";
    AL3.print();

    // list BL1, BL2, BL3;
    // cout << "Please enter the data for the second set of tests" << endl;
    // cout << "The first linked list element is (1, 3, 6, 10,  15, 16, 17, 18, 19, 20)" << endl;
    // cout << "The second linked list element is (2, 4, 5, 7, 8, 9, 12, 22)" << endl;
    // cout << "Create the first linked list" << endl;
    // BL1.create_R();
    // cout << "Create the second linked list" << endl;
    // BL2.create_R();
    // BL3 = getCommomElement(BL1, BL2);
    // cout << "A linked list composed of common elements:";
    // BL3.print();

    // list CL1, CL2, CL3;
    // cout << "Please enter the data for the third set of tests" << endl;
    // cout << "The first linked list element is ()" << endl;
    // cout << "The second linked list element is (1, 2, 3, 4, 5, 6, 7, 8, 9, 10)" << endl;
    // cout << "Create the first linked list" << endl;
    // CL1.create_R();
    // cout << "Create the second linked list" << endl;
    // CL2.create_R();
    // CL3 = getCommomElement(CL1, CL2);
    // cout << "A linked list composed of common elements";
    // CL3.print();
    system("pause");
    return 0;
}
