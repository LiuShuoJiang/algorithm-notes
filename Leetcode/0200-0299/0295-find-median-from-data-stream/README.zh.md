# 数据流的中位数

[Leetcode题目链接](https://leetcode.com/problems/find-median-from-data-stream/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/find-median-from-data-stream/)。

## 解答

```C++
class MedianFinder {
private:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (small.size() >= large.size()) {
            small.push(num);
            large.push(small.top());
            small.pop();
        } else {
            large.push(num);
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        if (large.size() < small.size()) return small.top();
        else if (large.size() > small.size()) return large.top();

        return (large.top() + small.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```
