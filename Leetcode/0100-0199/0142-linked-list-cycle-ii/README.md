# Linked List Cycle II

[Link](https://leetcode.com/problems/linked-list-cycle-ii/description/)

## Description

Given the `head` of a linked list, return the node where the cycle begins. If there is no cycle, return `null`.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the `next` pointer. Internally, `pos` is used to denote the index of the node that tail's `next` pointer is connected to (0-indexed). It is `-1` if there is no cycle. Note that `pos` is not passed as a parameter.

Do not modify the linked list.

Example 1:

- Input: `head = [3,2,0,-4], pos = 1`
- Output: tail connects to node index 1
- Explanation: There is a cycle in the linked list, where tail connects to the second node.

Example 2:

- Input: `head = [1,2], pos = 0`
- Output: tail connects to node index 0
- Explanation: There is a cycle in the linked list, where tail connects to the first node.

Example 3:

- Input: `head = [1], pos = -1`
- Output: no cycle
- Explanation: There is no cycle in the linked list.

Constraints:

- The number of the nodes in the list is in the range `[0, 10^4]`.
- `-10^5 <= Node.val <= 10^5`
- `pos` is `-1` or a valid index in the linked-list.

## Solution

```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                ListNode *index1 = fast;
                ListNode *index2 = head;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
            }
        }

        return nullptr;
    }
};
```
