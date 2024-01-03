# Sort List

[Link](https://leetcode.com/problems/sort-list/description/)

## Description

Given the `head` of a linked list, return the list after sorting it in ascending order.

Example 1:

- Input: `head = [4,2,1,3]`
- Output: `[1,2,3,4]`

Example 2:

- Input: `head = [-1,5,3,4,0]`
- Output: `[-1,0,3,4,5]`

Example 3:

- Input: `head = []`
- Output: `[]`

Constraints:

- The number of nodes in the list is in the range `[0, 5 * 10^4]`.
- `-10^5 <= Node.val <= 10^5`

## Solution

### Merge Sort (top to bottom)

The process of top-down merge sorting of a linked list is as follows.

- Find the midpoint of the linked list and use the midpoint as a divider to split the linked list into two sub linked lists. To find the midpoint of a linked list, we can use the fast and slow pointers, the fast pointer moves 2 steps at a time, and the slow pointer moves 1 steps at a time. When the fast pointer reaches the end of the linked list, the node of the linked list pointed to by the slow pointer is the midpoint of the linked list.
- Sort the two sub-lined lists separately.
- Merge the two sorted sub-linking lists to get the complete sorted linking list.

The above process can be realized by recursion. The termination condition for recursion is that the number of nodes in the linked list is less than or equal to 1, i.e., when the linked list is empty or contains only 1 nodes, there is no need to split and sort the linked list.

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
private:
    ListNode* merge_sort_top_to_bottom(ListNode* head, ListNode* tail) {
        if (head == nullptr) return head;
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != tail) {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail) fast = fast->next;
        }
        ListNode* mid = slow;
        return merge(merge_sort_top_to_bottom(head, mid), merge_sort_top_to_bottom(mid, tail));
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* temp = dummyHead, *temp1 = head1, *temp2 = head2;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val <= temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if (temp1 != nullptr) temp->next = temp1;
        if (temp2 != nullptr) temp->next = temp2;
        return dummyHead->next;
    }

public:
    ListNode* sortList(ListNode* head) {
        return merge_sort_top_to_bottom(head, nullptr);
    }
};
```

- Time complexity: $O(n\log n)$;
- Space complexity: $O(\log n)$.

### Merge Sort (bottom to top)

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

- Time complexity: $O(n\log n)$;
- Space complexity: $O(1)$.

#### Algorithm Overview: Bottom-Up Merge Sort

1. **Initialization**: First, the length of the list is calculated. This is needed to control the iterations as we'll be merging sublists of increasing sizes.
2. **Dummy Head**: A dummy head node is used for ease of operations. It points to the head of the list and is used to handle edge cases smoothly.
3. **Iterative Merging**: The list is split into pairs of sublists of size `i`, where `i` starts from 1 and doubles each iteration (1, 2, 4, 8, ...). These pairs of sublists are merged in a sorted manner.
4. **Merging Sublists**: For each pair of sublists, the elements are compared and merged into a single sorted sublist. This process continues until all sublists are merged into one sorted list.

#### Code Explanation

***Sorting Initialization***:

```C++
int n = 0;
for (auto p = head; p; p = p->next) n++;
auto dummy = new ListNode();
dummy->next = head;
```

- Counts the total number of nodes in the list.
- Creates a dummy node to simplify edge cases.

***Outer Loop - Sublist Size Doubling***

```C++
for (int i = 1; i < n; i *= 2) {
    auto curr = dummy;
    for (int j = 1; j + i <= n; j += i * 2) {
```

- `i` represents the size of the sublists to be merged, starting from 1 and doubling each time.
- The outer loop iterates over the list, doubling the size of the sublists in each iteration.

***Inner Loop - Processing Each Pair of Sublists***

```C++
auto p = curr->next, q = p;
for (int k = 0; k < i; k++) q = q->next;
```

- `p` and `q` are pointers to the heads of the two sublists to be merged.
- `q` is advanced `i` steps ahead to reach the start of the second sublist.

***Merging Two Sublists***

```C++
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
```

- The elements of `p` and `q` are compared.
- The smaller element is appended to the sorted sublist.
- The process continues until one of the sublists is fully traversed.

***Handling Remaining Elements***

```C++
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
```

- If any elements remain in either `p` or `q` sublist (i.e., one sublist was longer), they are appended to the merged list.
- After the merging of two sublists (`p` and `q`) within the inner loop, we need to ensure that the sorted list is correctly linked to the rest of the list that is yet to be processed. The line `curr->next = q;` ensures that this last node is linked to the head of the next section of the list (`q` at this point).

