//225. Implement Stack using Queues
#include<bits/stdc++.h>
using namespace std;

class MyStack {
    queue<int>q1,q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    //T.C=O(1)
    
    int pop() {
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }

        int popped=q1.front();
        q1.pop();

        //push back into q1
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }

        return popped;
    }
    //T.C=O(N)+O(N)
    
    int top() {
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }

        int peek=q1.front();
        q2.push(q1.front());
        q1.pop();

        //push back into q1
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }

        return peek;
    }
    //T.C=O(N)+O(N)
    
    bool empty() {
        return q1.empty();
    }
    //T.C=O(1)
};

//FOLLOW UP QUESTION: Implement stack using only one queue.
class MyStack {
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        int size=q.size();
        q.push(x);
        while(size){
            int x=q.front();
            q.pop();
            q.push(x);
            size--;
        }
    }
    //T.C=O(N)
    
    int pop() {
        int x=q.front();
        q.pop();
        return x;
    }
    //T.C=O(1)
    
    int top() {
        return q.front();
    }
    //T.C=O(1)
    
    bool empty() {
        return !q.size();
    }
    //T.C=O(1)
};


/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */