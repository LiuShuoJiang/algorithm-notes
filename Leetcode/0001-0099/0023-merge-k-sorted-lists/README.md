# Merge k Sorted Lists

[Link](https://leetcode.com/problems/merge-k-sorted-lists/description/)

## Description

You are given an array of `k` linked-lists `lists`, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

Example 1:

- Input: `lists = [[1,4,5],[1,3,4],[2,6]]`
- Output: `[1,1,2,3,4,4,5,6]`
- Explanation:

```
The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
```

Example 2:

- Input: `lists = []`
- Output: `[]`

Example 3:

- Input: `lists = [[]]`
- Output: `[]`

Constraints:

- `k == lists.length`
- `0 <= k <= 10^4`
- `0 <= lists[i].length <= 500`
- `-10^4 <= lists[i][j] <= 10^4`
- `lists[i]` is sorted in ascending order.
- The sum of `lists[i].length` will not exceed `10^4`.

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

- Time Complexity:
    - Inserting an element into a priority queue takes $O(\log k)$ time, where $k$ is the number of linked lists.
    - Each of the $n$ nodes is inserted into the queue once, thus the overall time complexity is $O(n \log k)$.
- Space Complexity:
    - The space complexity is $O(k)$ because the priority queue contains at most $k$ pointers to the head of each linked list.

### Way 2

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        auto dummy = new ListNode(), tail = dummy;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                tail = tail->next;
                list1 = list1->next;
            } else {
                tail->next = list2;
                tail = tail->next;
                list2 = list2->next;
            }
        }
        tail->next = list1 ? list1 : list2;
        return dummy->next;
    }

    ListNode* merge(vector<ListNode*>& lists, int l, int r) {
        if (l == r) return lists[l];
        int mid = (l + r) >> 1;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (!n) return nullptr;
        return merge(lists, 0, n - 1);
    }
};
```
