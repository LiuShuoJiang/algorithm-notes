# 用队列实现栈

[Leetcode链接](https://leetcode.com/problems/implement-stack-using-queues/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/implement-stack-using-queues/description/)。

## 解答

```C++
class MyStack {
public:
    queue<int> q, sq;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        while (q.size() > 1) {
            sq.push(q.front());
            q.pop();
        }
        int res = q.front();
        q.pop();
        while (!sq.empty()) {
            q.push(sq.front());
            sq.pop();
        }
        return res;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
```
