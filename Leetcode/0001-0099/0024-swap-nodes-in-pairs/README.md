# Swap Nodes in Pairs

[Link](https://leetcode.com/problems/swap-nodes-in-pairs/description/)

## Description

Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

Example 1:

- Input: `head = [1,2,3,4]`
- Output: `[2,1,4,3]`

Example 2:

- Input: `head = []`
- Output: `[]`

Example 3:

- Input: `head = [1]`
- Output: `[1]`

Constraints:

- The number of nodes in the list is in the range `[0, 100]`.
- `0 <= Node.val <= 100`

## Solution

### Classical Solution

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
    ListNode* swapPairs(ListNode* head) {
        // Create a dummy node to simplify edge cases like empty list or list with single node
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;

        // Use curr to traverse the list
        ListNode *curr = dummyHead;

        // Loop through the list in pairs
        while (curr->next && curr->next->next) {
            // Identify the two nodes to be swapped
            ListNode *temp1 = curr->next; // First node in the pair
            ListNode *temp2 = curr->next->next->next; // Node right after the second node in the pair

            // Perform the swap
            curr->next = curr->next->next; // Point current to the second node
            curr->next->next = temp1; // Point second node to the first node
            curr->next->next->next = temp2; // Connect the first node to the rest of the list

            // Move curr two nodes forward for the next pair
            curr = curr->next->next;
        }

        // Return the new head of the list
        return dummyHead->next;
    }
};
```

- Time complexity: $O(n)$;
- Space complexity: $O(1)$.

### Recursive Solution

```C++
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode *first = head;
        ListNode *second = head->next;
        ListNode *after = head->next->next;

        second->next = first;
        first->next = swapPairs(after);
        return second;
    }
};
```

Another way of writing:

```C++
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Base case: if list is empty or has only one node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Nodes to be swapped
        ListNode *node1 = head;
        ListNode *node2 = head->next;

        // Swap the nodes and recursively call for the rest of the list
        node1->next = swapPairs(node2->next);
        node2->next = node1;

        // After swapping, node2 is now the head of this part of the list
        return node2;
    }
};
```

The function `swapPairs` is called with the current head of the list. If the list is empty or has only one node, it returns the head as is. Otherwise, it swaps the first two nodes and then recursively calls itself for the rest of the list, starting from the third node.

The returned node from the recursive call is linked with the first node of the current pair, and the second node of the pair becomes the new head of this part of the list. This process repeats until all pairs are swapped, or the end of the list is reached.
