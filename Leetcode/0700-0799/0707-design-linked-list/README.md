# Design Linked list

[Link](https://leetcode.com/problems/design-linked-list/description/)

## Description

Design your implementation of the linked list. You can choose to use a singly or doubly linked list.

A node in a singly linked list should have two attributes: `val` and `next`. `val` is the value of the current node, and `next` is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute `prev` to indicate the previous node in the linked list. Assume all nodes in the linked list are ***0-indexed***.

Implement the `MyLinkedList` class:

- `MyLinkedList()` Initializes the `MyLinkedList` object.
- `int get(int index)` Get the value of the `index`-th node in the linked list. If the index is invalid, return -1.
- `void addAtHead(int val)` Add a node of value `val` before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
- `void addAtTail(int val)` Append a node of value `val` as the last element of the linked list.
- `void addAtIndex(int index, int val)` Add a node of value `val` before the `index`-th node in the linked list. If `index` equals the length of the linked list, the node will be appended to the end of the linked list. If `index` is greater than the length, the node *will not be inserted*.
- `void deleteAtIndex(int index)` Delete the `index`-th node in the linked list, if the index is valid.

Example 1:

- Input:
  - `["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]`
  - `[[], [1], [3], [1, 2], [1], [1], [1]]`
- Output:
  - `[null, null, null, null, 2, null, 3]`

Explanation:

```C++
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
myLinkedList.get(1);              // return 2
myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
myLinkedList.get(1);              // return 3
```

Constraints:

- `0 <= index, val <= 1000`
- Please do not use the built-in LinkedList library.
- At most 2000 calls will be made to `get`, `addAtHead`, `addAtTail`, `addAtIndex` and `deleteAtIndex`.

## Solution

### With Dummy Head

```C++
class MyLinkedList {
public:
    struct LinkedNode {
        int val;
        LinkedNode *next;
        LinkedNode(int val) : val(val), next(nullptr) {}
    };
    MyLinkedList() {
        _dummyHead = new LinkedNode(0);
        _size = 0;
    }
    
    int get(int index) {
        if (index >= _size || index < 0) return -1;
        LinkedNode *curr = _dummyHead->next;
        while (index-- && curr) curr = curr->next;
        if (curr) return curr->val;
        return -1;
    }
    
    void addAtHead(int val) {
        LinkedNode *newNode = new LinkedNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }
    
    void addAtTail(int val) {
        LinkedNode *newNode = new LinkedNode(val);
        LinkedNode *curr = _dummyHead;
        while (curr->next != nullptr) curr = curr->next;
        curr->next = newNode;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > _size) return;
        if (index < 0) index = 0;
        LinkedNode *newNode = new LinkedNode(val);
        LinkedNode *curr = _dummyHead;
        while (index-- && curr->next) curr = curr->next;
        newNode->next = curr->next;
        curr->next = newNode;
        _size++;
    }
    
    void deleteAtIndex(int index) {
        if (index >= _size || index < 0) return;
        LinkedNode *curr = _dummyHead;
        while (index-- && curr->next) curr = curr->next;
        LinkedNode *temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
        temp = nullptr;
        _size--;
    }
private:
    int _size;
    LinkedNode *_dummyHead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
```

- Time complexity: $O(index)$ for operations involving `index`, $O(1)$ for the rest;
- Space complexity: $O(n)$.

Note: When we insert with `index < 0`, test case will just treat as insert at `index = 0`.

Code with comments:

```C++
class MyLinkedList {
public:
    // Node structure representing each element in the list
    struct LinkedNode {
        int val;           // Value of the node
        LinkedNode *next;  // Pointer to the next node in the list
        LinkedNode(int val) : val(val), next(nullptr) {}
    };

    // Constructor
    MyLinkedList() {
        _dummyHead = new LinkedNode(0);  // Create a dummy head to simplify operations
        _size = 0;                       // Initialize the size of the list as 0
    }
    
    // Get the value of the index-th node in the linked list
    int get(int index) {
        if (index >= _size || index < 0) return -1; // Return -1 for invalid index
        LinkedNode *curr = _dummyHead->next;        // Start from the first real node
        while (index--) curr = curr->next;          // Move to the correct node
        return curr->val;                           // Return the value of the node
    }
    
    // Add a node of value val before the first element of the linked list
    void addAtHead(int val) {
        LinkedNode *newNode = new LinkedNode(val);  // Create a new node
        newNode->next = _dummyHead->next;           // Point the new node to the first real node
        _dummyHead->next = newNode;                 // Insert the new node after dummy head
        _size++;                                    // Increase the size of the list
    }
    
    // Append a node of value val to the last element of the linked list
    void addAtTail(int val) {
        LinkedNode *newNode = new LinkedNode(val);  // Create a new node
        LinkedNode *curr = _dummyHead;              // Start from the dummy head
        while (curr->next != nullptr)               // Traverse to the end of the list
            curr = curr->next;
        curr->next = newNode;                       // Append the new node
        _size++;                                    // Increase the size of the list
    }
    
    // Add a node of value val before the index-th node in the linked list
    void addAtIndex(int index, int val) {
        if (index > _size) return;                  // Do nothing if index is greater than the size
        if (index < 0) index = 0;                   // Treat negative index as 0
        LinkedNode *newNode = new LinkedNode(val);  // Create a new node
        LinkedNode *curr = _dummyHead;              // Start from the dummy head
        while (index--) curr = curr->next;          // Move to the correct position
        newNode->next = curr->next;                 // Insert the new node
        curr->next = newNode;
        _size++;                                    // Increase the size of the list
    }
    
    // Delete the index-th node in the linked list, if the index is valid
    void deleteAtIndex(int index) {
        if (index >= _size || index < 0) return;    // Do nothing if the index is invalid
        LinkedNode *curr = _dummyHead;              // Start from the dummy head
        while (index--) curr = curr->next;          // Move to the node before the one to be deleted
        LinkedNode *temp = curr->next;              // Temporarily store the node to be deleted
        curr->next = curr->next->next;              // Remove the node from the list
        delete temp;                                // Delete the node
        temp = nullptr;
        _size--;                                    // Decrease the size of the list
    }

private:
    int _size;                  // Size of the linked list
    LinkedNode *_dummyHead;     // Dummy head node to simplify operations
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
```

### Without Dummy Head

```C++
class MyLinkedList {
public:
    // Node structure for the linked list
    struct Node {
        int val;   // Value of the node
        Node *next; // Pointer to the next node
        Node(int _val) : val(_val), next(nullptr) {} // Constructor to initialize node
    } *head; // Head pointer of the list

    // Constructor initializes the linked list
    MyLinkedList() {
        head = nullptr; // Initially, the list is empty, so head is null
    }

    // Function to get the value of the node at a given index
    int get(int index) {
        if (index < 0) return -1; // Return -1 for invalid index
        auto p = head; // Start from the head of the list
        for (int i = 0; i < index && p; i++) p = p->next; // Traverse the list to reach the desired index
        if (!p) return -1; // If p is null, index is out of bounds
        return p->val; // Return the value of the node at the index
    }

    // Function to add a node at the beginning of the list
    void addAtHead(int val) {
        auto curr = new Node(val); // Create a new node
        curr->next = head; // Link new node to the current head
        head = curr; // Update head to the new node
    }

    // Function to add a node at the end of the list
    void addAtTail(int val) {
        if (!head) { // If the list is empty
            head = new Node(val); // Create a new node and set it as head
        }
        else {
            auto p = head; // Start from the head
            while (p->next) p = p->next; // Traverse to the last node
            p->next = new Node(val); // Add new node at the end
        }
    }

    // Function to add a node at a specific index
    void addAtIndex(int index, int val) {
        if (index <= 0) { // If index is 0 or negative, add at head
            addAtHead(val);
        }
        else {
            int len = 0;
            for (auto p = head; p; p = p->next) len++; // Calculate the length of the list
            if (index == len) { // If index equals the length of the list, add at tail
                addAtTail(val);
            }
            else if (index < len) { // If index is within bounds
                auto p = head;
                for (int i = 0; i < index - 1; i++) p = p->next; // Find the node before the desired index
                auto curr = new Node(val); // Create a new node
                curr->next = p->next; // Insert the new node after p
                p->next = curr;
            }
        }
    }

    // Function to delete a node at a specific index
    void deleteAtIndex(int index) {
        int len = 0;
        for (auto p = head; p; p = p->next) len++; // Calculate the length of the list
        if (index >= 0 && index < len) { // If index is within bounds
            if (!index) { // If index is 0, delete the head
                head = head->next;
            }
            else {
                auto p = head;
                for (int i = 0; i < index - 1; i++) p = p->next; // Find the node before the one to delete
                p->next = p->next->next; // Delete the node at the index
            }
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
```
