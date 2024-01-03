# 排序链表

[Leetcode题目链接](https://leetcode.com/problems/sort-list/description/)

## 描述

详见[中文题目链接](https://leetcode.cn/problems/sort-list/description/)。

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
    ListNode* sortList(ListNode* head) {
        int n = 0;
        for (auto p = head; p; p = p->next) n++;

        auto dummy = new ListNode();
        dummy->next = head;

        for (int i = 1; i < n; i *= 2) {
            auto curr = dummy;
            for (int j = 1; j + i <= n; j += i * 2) {
                auto p = curr->next, q = p;
                for (int k = 0; k < i; k++) q = q->next;
                
                int x = 0, y = 0;
                while (x < i && y < i && p && q) {
                    if (p->val <= q->val) {
                        curr = curr->next = p;
                        p = p->next;
                        x++;
                    } else {
                        curr = curr->next = q;
                        q = q->next;
                        y++;
                    }
                }

                while (x < i && p) {
                    curr = curr->next = p;
                    p = p->next;
                    x++;
                }
                while (y < i && q) {
                    curr = curr->next = q;
                    q = q->next;
                    y++;
                }
                curr->next = q;
            }
        }

        return dummy->next;
    }
};
```
