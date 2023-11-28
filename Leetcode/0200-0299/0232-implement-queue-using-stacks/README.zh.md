# 用队列实现栈

[Leetcode链接](https://leetcode.com/problems/implement-queue-using-stacks/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/implement-queue-using-stacks/description/)。

## 解答

```C++
class MyQueue {
public:
    stack<int> stkIn, stkOut;
    MyQueue() {
        
    }
    
    void push(int x) {
        stkIn.push(x);
    }
    
    int pop() {
        // Import data from stIn only if stOut is empty (import all stIn data)
        if (stkOut.empty()) {
            while (!stkIn.empty()) {
                stkOut.push(stkIn.top());
                stkIn.pop();
            }
        }
        int result = stkOut.top();
        stkOut.pop();
        return result;
    }
    
    int peek() {
        int result = this->pop();
        // Because the pop function pops the element "result",
        // it need to be added back again
        stkOut.push(result);
        return result;
    }
    
    bool empty() {
        return stkIn.empty() && stkOut.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
```
