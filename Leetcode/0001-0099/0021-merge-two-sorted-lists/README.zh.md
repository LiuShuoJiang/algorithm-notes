# 合并两个有序链表

[Leetcode题目连接](https://leetcode.com/problems/merge-two-sorted-lists/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/merge-two-sorted-lists/)。

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        ListNode* tail = new ListNode();
        ListNode* preHead = tail;
        auto p = list1, q = list2;
        while (p && q) {
            if (p->val <= q->val) {
                tail->next = new ListNode(p->val);
                p = p->next;
            } else {
                tail->next = new ListNode(q->val);
                q = q->next;
            }
            tail = tail->next;
        }
        while (p) {
            tail->next = new ListNode(p->val);
            p = p->next;
            tail = tail->next;
        }
        while (q) {
            tail->next = new ListNode(q->val);
            q = q->next;
            tail = tail->next;
        }
        return preHead->next;
    }
};
```
