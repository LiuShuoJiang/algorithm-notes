# Remove Nth Node From End of List

[Link](https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/)

## Description

Given the `head` of a linked list, remove the `n`-th node from the end of the list and return its head.

Example 1:

- Input: `head = [1,2,3,4,5], n = 2`
- Output: `[1,2,3,5]`

Example 2:

- Input: `head = [1], n = 1`
- Output: `[]`

Example 3:

- Input: `head = [1,2], n = 1`
- Output: `[1]`

Constraints:

- The number of nodes in the list is `sz`.
- `1 <= sz <= 30`
- `0 <= Node.val <= 100`
- `1 <= n <= sz`

## Solution

To delete the `n`-th node from back to front, we need to get a reference to the `n+1`-th node from back to front.

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode *slow = dummyHead;
        ListNode *fast = dummyHead;

        while (n-- && fast) {
            fast = fast->next;
        }
        fast = fast->next;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

        return dummyHead->next;
    }
};
```

- Time complexity: $O(n)$;
- Space complexity: $O(1)$.
