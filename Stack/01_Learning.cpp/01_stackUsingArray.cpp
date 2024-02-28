#include<bits/stdc++.h>
using namespace std;

class Stack {
    int tp;
    int cap;
    int *st;
    
public:  
    Stack(int capacity) {
        tp=-1;
        cap=capacity;
        st=new int[cap];
    }

    void push(int num) {
        if(tp==cap-1)
            return ;
        tp++;
        st[tp]=num;
    }

    int pop() {
        if(tp!=-1)
            return st[tp--];
        return -1;
    }
    
    int top() {
        if(tp!=-1)
            return st[tp];
        return -1;
    }
    
    int isEmpty() {
        return tp==-1;
    }
    
    int isFull() {
        return cap-1==tp;
    }
    
};
