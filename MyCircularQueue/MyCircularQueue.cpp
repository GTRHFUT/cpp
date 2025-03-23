#include "MyCircularQueue.h"  
using namespace std;
MyCircularQueue::MyCircularQueue(int k){
    capacity = k + 1;
    data = new int[capacity];
    front = 0;
    rear = 0;
}
bool MyCircularQueue::enQueue(int value){
    if(isFull())return false;
    rear = (rear + 1)% capacity;
    data[rear] = value;
    return true;
}
bool MyCircularQueue::deQueue(){
    if(isEmpty())return false;
    front = (front + 1) % capacity;
    return true;
}
int MyCircularQueue::Front()const{
    if(isEmpty())return -1;
    return data[(front + 1) % capacity];
}
int MyCircularQueue::Rear()const{
    if(isEmpty())return -1;
    return data[rear];
}
bool MyCircularQueue::isEmpty()const{
    return front == rear;
}
bool MyCircularQueue::isFull()const{
    return (rear + 1) % capacity == front;
}
MyCircularQueue::~MyCircularQueue(){
    delete[] data;
    data = nullptr;
}