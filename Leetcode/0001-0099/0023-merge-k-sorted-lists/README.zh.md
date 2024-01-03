# 合并 K 个升序链表

[Leetcode题目链接](https://leetcode.com/problems/merge-k-sorted-lists/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/merge-k-sorted-lists/)。

## 解答

```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);

        for (auto head : lists) {
            if (head) q.push(head);
        }

        auto dummy = new ListNode(), tail = dummy;

        while (!q.empty()) {
            auto node = q.top(); q.pop();
            tail->next = node;
            tail = tail->next;
            if (node->next) q.push(node->next);
        }

        auto mergeHead = dummy->next;
        delete dummy;
        return mergeHead;
    }
};
```
