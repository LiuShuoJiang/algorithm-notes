# 数据流中的第 K 大元素

[Leetcode题目链接](https://leetcode.com/problems/kth-largest-element-in-a-stream/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/kth-largest-element-in-a-stream/)。

## 解答

```C++
class KthLargest {
private:
    int _k;
    priority_queue<int, vector<int>, greater<int>> q;
public:
    KthLargest(int k, vector<int>& nums) {
        for (int num : nums) {
            q.push(num);
            if (q.size() > k) q.pop();
        }
        this->_k = k;
    }
    
    int add(int val) {
       q.push(val);
       if (q.size() > _k) q.pop();
       return q.top(); 
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
```
