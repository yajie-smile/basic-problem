#include <iostream>
using namespace std;

const int stkMaxSize = 10;
const int queMaxSize = 10;

class Stack {
    int stk[stkMaxSize];
    int size;
public:
    Stack() : size(0) {}
    void push(int ele) {
        if(size ==stkMaxSize) {
            cout<<"the stack is full!!!"<<endl;
            return;
        }
        stk[size] = ele;
        size++;
    }
    void pop() {
        if(empty()) {
            cout<<"the stack is empty!!!"<<endl;
            return;
        }
        size--;
    }
    int top() {
        if(empty()) {
            cout<<"the stack is empty!!!"<<endl;
            return NULL;
        }
        return stk[size - 1];
    }
    bool empty() {
        if(size > 0)  return false;
        else  return true;
    }
    void print() {
        if(!empty()) {
            for(int i = 0; i < size; i++)
                cout<<stk[i]<<" ";
            cout<<endl;
        }
    }
};

class Queue {
    int que[queMaxSize];
    int posWr, posRd;
public:
    Queue() : posWr(-1), posRd(-1) {}
    void push(int ele) {
        if(posWr - posRd == queMaxSize || posRd - posWr == 1) {
            cout<<"the queue is full!!!"<<endl;
            return;
        }
        
        posWr++;
        if(posWr == queMaxSize)
            posWr = 0;
        
        que[posWr] = ele;
    
    }
    void pop() {
        if(empty()) {
            cout<<"the queue is empty!!!"<<endl;
            return;
        }
        
        posRd++;
        if(posRd == queMaxSize)
            posRd = 0;
    }
    int front() {
        if(empty()) {
            cout<<"the queue is empty!!!"<<endl;
            return NULL;
        }
        if(posRd + 1 == queMaxSize) posRd = -1;
        return que[posRd + 1];
    }
    bool empty() {
        if(posWr == posRd) return true;
        else return false;
    }
    void print() {
        if(!empty()) {
            int i = posRd;
            while(i != posWr) {
                cout<<que[i + 1]<<" ";
                i++;
                if(i == queMaxSize) i = -1;
            }
            cout<<endl;
        }
    }
};

int main() {
    Stack stack;
    for(int i = 0; i < 12; i++) {
        stack.push(i);
        stack.print();
    }
    cout<<endl;
    for(int i = 0; i < 5; i++) {
        stack.print();
        cout<<"the top value = "<<stack.top()<<endl;
        stack.pop();
    }
    cout<<endl;
    
    stack.push(10);
    for(int i = 0; i < 12; i++) {
        stack.print();
        stack.pop();
    }
    Queue queue;
    for(int i = 0; i < 12; i++) {
        queue.push(i);
        queue.print();
    }
    cout<<endl;
    for(int i = 0; i < 5; i++) {
        queue.print();
        cout<<"the top value = "<<queue.front()<<endl;
        queue.pop();
    }
    cout<<endl;
    
    queue.push(10);
    for(int i = 0; i < 12; i++) {
        queue.print();
        queue.pop();
    }
    return 0;
}



