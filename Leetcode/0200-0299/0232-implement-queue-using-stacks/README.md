# Implement Queue using Stacks

[link](https://leetcode.com/problems/implement-queue-using-stacks/description/)

## Description

Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (`push`, `peek`, `pop`, and `empty`).

Implement the `MyQueue` class:

- `void push(int x)` Pushes element `x` to the back of the queue.
- `int pop()` Removes the element from the front of the queue and returns it.
- `int peek()` Returns the element at the front of the queue.
- `boolean empty()` Returns `true` if the queue is empty, `false` otherwise.

Notes:

- You must use only standard operations of a stack, which means only `push to top`, `peek/pop from top`, `size`, and `is empty` operations are valid.
- Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.

Example 1:

- Input:
    - `["MyQueue", "push", "push", "peek", "pop", "empty"]`
    - `[[], [1], [2], [], [], []]`
- Output:
    - `[null, null, null, 1, 1, false]`

Explanation:

```C++
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
```

Constraints:

- `1 <= x <= 9`
- At most `100` calls will be made to `push`, `pop`, `peek`, and `empty`.
- All the calls to `pop` and `peek` are valid.

## Solution

### Implementation Using Two Stacks

When pushing data, it is sufficient to simply place the data into the input stack. However, popping data is a bit more complex. If the output stack is empty, then all the data from the input stack should be transferred into it (note that it should be a complete transfer), and then data can be popped from the output stack. If the output stack is not empty, data can be directly popped from it.

Finally, how do we determine if the queue is empty? If both the input and output stacks are empty, then the simulated queue is considered empty.

#### Way 1

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

- Time complexity: `push` and `empty` are $O(1)$, `pop` and `peek` are $O(n)$;
- Space complexity: $O(n)$.

#### Way 2

We use a stack to store the elements of the queue, and an auxiliary stack to aid in the implementation of the `pop()` and `peek()` operations.

The four operations are implemented as follows:

- `push(x)`: inserts `x` directly into the top of the stack;
- `pop()`: if we need to pop the bottom element of the stack, we first insert all elements above the bottom of the stack into the auxiliary stack, then pop the bottom element, and finally re-press the elements of the auxiliary stack into the current stack;
- `peek()`: returns the top element of the stack. Similarly, we first insert all elements above the bottom of the stack into the auxiliary stack, then eject the bottom element, and finally re-press the elements in the auxiliary stack into the current stack to restore the current stack to its original state;
- `empty()`: returns whether the current stack is empty.

```C++
class MyQueue {
public:
    stack<int> stkMain, stkSupply;
    MyQueue() {
        
    }
    
    void push(int x) {
        stkMain.push(x);
    }
    
    int pop() {
        while (stkMain.size() > 1) {
            stkSupply.push(stkMain.top());
            stkMain.pop();
        }
        int t = stkMain.top();
        stkMain.pop();
        while (stkSupply.size()) {
            stkMain.push(stkSupply.top());
            stkSupply.pop();
        }
        return t;
    }
    
    int peek() {
        while (stkMain.size() > 1) {
            stkSupply.push(stkMain.top());
            stkMain.pop();
        }
        int t = stkMain.top();
        while (stkSupply.size()) {
            stkMain.push(stkSupply.top());
            stkSupply.pop();
        }
        return t;
    }
    
    bool empty() {
        return stkMain.empty();
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

### Implementation Using Array

```C++
class MyQueue {
public:
    MyQueue() {
        hh = 0;
        tt = -1;
    }
    
    void push(int x) {
        q[++tt] = x;
    }
    
    int pop() {
        hh++;
        return q[hh - 1];
    }
    
    int peek() {
        return q[hh];
    }
    
    bool empty() {
        if (hh <= tt) return false;
        else return true;
    }
    int q[110];
    int hh;
    int tt;
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
