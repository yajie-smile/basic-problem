#include <iostream>
using namespace std;

const int stkMaxSize = 10;
const int queMaxSize = 10;
//realize stack with arrays
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
//realize stack with listnodes and class template
static int construct = 0;//test if every node we create get deleted in the end
static int destruct = 0;

template<class T>
class Stack {
    class ListNode {
    public:
        T val;
        ListNode* next;
        ListNode(T t) : val(t), next(NULL) {construct++;}
        ListNode() { construct++; }
        ~ListNode() { destruct++; }
    };
    ListNode* head;
public:
    Stack() : head(NULL) {}
    void push(T ele) {
        ListNode* t = new ListNode(ele);
        t->next = head;
        head = t;
    }
    void pop() {
        ListNode* toBeDeleted = head;
        head = head->next;
        delete toBeDeleted;
    }
    T top() {
        return head->val;
    }
    bool empty() {
        if(head == NULL) return true;
        else return false;
    }
};
//test cases for CLASS TEMPLATE Stack below
#if 0
int main() {
    Stack<int> stk;
    for(int i = 0; i < 10; i++)
        stk.push(i);
    for(int i = 0; i < 12; i++) {
        if(!stk.empty()) {
            cout<<stk.top()<<endl;
            stk.pop();
        }
    }
    cout<<"---------------"<<endl;
    cout<<construct<<endl;
    cout<<destruct<<endl;
}
#endif

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



