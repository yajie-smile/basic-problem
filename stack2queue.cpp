#include <iostream>
#include <stack>
using namespace std;

class Queue {
    stack<int> stk1, stk2;
public:
    void push(int ele) {
        stk1.push(ele);
    }
    void pop() {
        if(stk1.empty() && stk2.empty()) {
            cout<<"the queue is empty!!!"<<endl;
            return;
        }
        if(stk2.empty()) {
            while(!stk1.empty()) {
                int tmp = stk1.top();
                stk1.pop();
                stk2.push(tmp);
            }
        }
        stk2.pop();
    }
    int front() {
        if(empty()) return NULL;
        if(stk2.empty()) {
            while(!stk1.empty()) {
                int tmp = stk1.top();
                stk1.pop();
                stk2.push(tmp);
            }
        }
        return stk2.top();
    }
    bool empty() {
        if(stk1.empty() && stk2.empty()) return true;
        else return false;
    }
};

int main() {
    Queue queue;
    for(int i = 0; i < 5; i++) {
        cout<<"pushing "<<i<<" into queue"<<endl;
        queue.push(i);
    }
    for(int i = 0; i < 3; i++) {
        cout<<"the top value = "<<queue.front()<<", and pop "<<queue.front()<<" out"<<endl;
        queue.pop();
    }
    cout<<"pushing 10 into queue"<<endl;
    queue.push(10);
    
    for(int i = 0; i < 12; i++) {
        if(!queue.empty()) {
            cout<<"the top value = "<<queue.front()<<", and pop "<<queue.front()<<" out"<<endl;
            queue.pop();
        }
    }
    return 0;
}