#include <iostream>
#include "MyCircularQueue.h"
using namespace std;
int main()
{
    MyCircularQueue circularQueue(3);                              // 设置长度为 3
    cout << (circularQueue.enQueue(1) ? "true" : "false") << endl; // 返回 true
    cout << (circularQueue.enQueue(2) ? "true" : "false") << endl; // 返回 true
    cout << (circularQueue.enQueue(3) ? "true" : "false") << endl; // 返回 true
    cout << (circularQueue.enQueue(4) ? "true" : "false") << endl; // 返回 false，队列已满
    cout << circularQueue.Rear() << endl;                          // 返回 3
    cout << (circularQueue.isFull() ? "true" : "false") << endl;   // 返回 true
    cout << (circularQueue.deQueue() ? "true" : "false") << endl;  // 返回 true
    cout << (circularQueue.enQueue(4) ? "true" : "false") << endl; // 返回 true
    cout << circularQueue.Rear() << endl;                          // 返回 4
    cout << circularQueue.Front() << endl;                         // 返回 2
    system("pause");
    return 0;
}
