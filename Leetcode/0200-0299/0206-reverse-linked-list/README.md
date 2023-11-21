# Reverse Linked List

[Link](https://leetcode.com/problems/reverse-linked-list/description/)

## Description

Given the `head` of a singly linked list, reverse the list, and return the reversed list.

Example 1:

- Input: `head = [1,2,3,4,5]`
- Output: `[5,4,3,2,1]`

Example 2:

- Input: `head = [1,2]`
- Output: `[2,1]`

Example 3:

- Input: `head = []`
- Output: `[]`

Constraints:

- The number of nodes in the list is the range `[0, 5000]`.
- `-5000 <= Node.val <= 5000`

## Solution

### Double Pointer

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
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head;
        ListNode *prev = nullptr;
        while (curr) {
            ListNode *original_next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = original_next;
        }
        return prev;
    }
};
```

- Time complexity: $O(n)$;
- Space complexity: $O(1)$.

### Recursion

#### Way 1: Flip the pointer from front to back

```C++
class Solution {
public:
    ListNode* reverse(ListNode *prev, ListNode *curr) {
        if (curr == nullptr) return prev;
        ListNode *temp = curr->next;
        curr->next = prev;
        // prev = curr;
        // curr = temp;
        return reverse(curr, temp);
    }

    ListNode* reverseList(ListNode* head) {
        return reverse(nullptr, head);
    }
};
```

- Time complexity: $O(n)$;
- Space complexity: $O(n)$.

#### Way 2: Flip the pointer from back to front

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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *tail = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return tail;
    }
};
```

Explanation:

- ***Base Case***: The function checks if the `head` is `nullptr` (empty list) or if `head->next` is `nullptr` (single node list). In either case, the `head` is returned as it is, as there is nothing to reverse.
- ***Recursive Call***: If the list contains more than one node, the function makes a recursive call with the next node (`head->next`). This process continues until the function reaches the end of the list.
- ***Reversing the Links***: Once the end of the list is reached (base case), the function backtracks, reversing the links as it goes. This is done by setting the `next` pointer of the next node to point back to the current node (`head->next->next = head`).
- ***Avoiding Cycles***: The current node's `next` pointer is set to `nullptr` to avoid cycles. This is necessary because, in the last reversal step, the new tail of the list (which was the original head) must point to `nullptr`.
- ***Returning New Head***: The function eventually returns the `tail` node, which is the new head of the reversed list.

Code with comments:

```C++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Base case: if the list is empty or has only one node, return the head as it is
        if (!head || !head->next) return head;
        /*
        // We can also write the code above as:
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        */

        // Recursively call reverseList on the next node
        // This call goes deeper until it reaches the end of the list
        auto tail = reverseList(head->next);

        // After reaching the end, the function starts to backtrack,
        // setting the next node's next pointer to the current node
        // This effectively reverses the direction of the link
        head->next->next = head;

        // Set the current node's next pointer to nullptr to avoid cycles
        // As we backtrack further, the previous node will set this correctly
        head->next = nullptr;

        // Return the new head of the reversed list (which is the original tail)
        return tail;
    }
};
```
