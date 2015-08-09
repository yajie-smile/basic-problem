#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> que1, que2;
public:
    void push(int ele) {
        if(!que2.empty()) que2.push(ele);
        else que1.push(ele);
    }
    void popQueue(queue<int>& queue1, queue<int>& queue2) {
        int tmp = queue1.front();
        queue1.pop();
        while(!queue1.empty()) {
            queue2.push(tmp);
            tmp = queue1.front();
            queue1.pop();
        }
    }
    void pop() {
        if(empty()) return;
        if(!que1.empty())
            popQueue(que1, que2);
        else
            popQueue(que2, que1);
    }
    int topQueue(queue<int>& queue1, queue<int>& queue2) {
        int tmp = queue1.front();
        queue1.pop();
        while(!queue1.empty()) {
            queue2.push(tmp);
            tmp = queue1.front();
            queue1.pop();
        }
        queue2.push(tmp);
        return tmp;
    }
    int top() {
        if(empty()) return NULL;
        if(!que1.empty()) return topQueue(que1, que2);
        else return topQueue(que2, que1);
    }
    bool empty() {
        if(que1.empty() && que2.empty()) return true;
        else return false;
    }
};
int main() {
    Stack stack;
    for(int i = 0; i < 5; i++) {
        cout<<"pushing "<<i<<" into stack"<<endl;
        stack.push(i);
    }
    for(int i = 0; i < 3; i++) {
        cout<<"the top value = "<<stack.top()<<", and pop "<<stack.top()<<" out"<<endl;
        stack.pop();
    }
    cout<<"pushing 10 into stack"<<endl;
    stack.push(10);
    
    for(int i = 0; i < 12; i++) {
        if(!stack.empty()) {
            cout<<"the top value = "<<stack.top()<<", and pop "<<stack.top()<<" out"<<endl;
            stack.pop();
        }
    }

}