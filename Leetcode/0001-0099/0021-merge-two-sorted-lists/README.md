# Merge Two Sorted Lists

[Link](https://leetcode.com/problems/merge-two-sorted-lists/description/)

## Description

You are given the heads of two sorted linked lists `list1` and `list2`.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Example 1:

- Input: `list1 = [1,2,4], list2 = [1,3,4]`
- Output: `[1,1,2,3,4,4]`

Example 2:

- Input: `list1 = [], list2 = []`
- Output: `[]`

Example 3:

- Input: `list1 = [], list2 = [0]`
- Output: `[0]`

Constraints:

- The number of nodes in both lists is in the range `[0, 50]`.
- `-100 <= Node.val <= 100`
- Both `list1` and `list2` are sorted in non-decreasing order.

## Solution

### Way 1

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

### Way 2 (In Place)

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
        auto dummy = new ListNode(), tail = dummy;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail = tail->next = list1;
                list1 = list1->next;
            } else {
                tail = tail->next = list2;
                list2 = list2->next;
            }
        }
        if (list1) tail->next = list1;
        if (list2) tail->next = list2;
        
        return dummy->next;
    }
};
```

- Time complexity: $O(m+n)$;
- Space complexity: $O(1)$.
