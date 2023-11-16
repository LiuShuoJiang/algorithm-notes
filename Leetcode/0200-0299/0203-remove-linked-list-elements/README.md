# Remove Linked List Elements

[Link](https://leetcode.com/problems/remove-linked-list-elements/description/)

## Description

Given the `head` of a linked list and an integer `val`, remove all the nodes of the linked list that has `Node.val == val`, and return *the new head*.

Example:

- Input: `head = [1,2,6,3,4,5,6], val = 6`
- Output: `[1,2,3,4,5]`

Example 2:

- Input: `head = [], val = 1`
- Output: `[]`

Example 3:

- Input: `head = [7,7,7,7], val = 7`
- Output: `[]`

Constraints:

- The number of nodes in the list is in the range `[0, 10^4]`.
- `1 <= Node.val <= 50`
- `0 <= val <= 50`

## Solution

### Solution 1

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
    ListNode* removeElements(ListNode* head, int val) {
        // NOTE!!! use "while" here! (not "if")
        while (head != NULL && head->val == val) {
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }

        ListNode *current = head;
        while (current != NULL && current->next != NULL) {
            if (current->next->val == val) {
                ListNode *temp = current->next;
                current->next = current->next->next;
                delete temp;
            } else {
                current = current->next;
            }
        }

        return head;
    }
};
```

- Time complexity: $O(n)$;
- Space complexity: $O(1)$

### Solution 2 (Recommended): Dummy Head Node

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode* current = dummyHead;
        while (current->next != NULL) {
            if (current->next->val == val) {
                ListNode *temp = current->next;
                current->next = current->next->next;
                delete temp;
            } else {
                current = current->next;
            }
        }

        // NOTE!!! Do not return head directly (because head may have been deleted)
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};
```