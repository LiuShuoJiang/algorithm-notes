# Introduction to Trees

- [Introduction to Trees](#introduction-to-trees)
  - [Basic Concepts of Trees](#basic-concepts-of-trees)
    - [Concept of Tree](#concept-of-tree)
    - [Concept of Binary Tree](#concept-of-binary-tree)
  - [Some Properties of Binary Trees](#some-properties-of-binary-trees)
    - [Number of Possible Binary Trees](#number-of-possible-binary-trees)
    - [Height VS Nodes in Binary Tree](#height-vs-nodes-in-binary-tree)
    - [Internal Nodes VS External Nodes in Binary Tree](#internal-nodes-vs-external-nodes-in-binary-tree)
  - [Special Tree Structures](#special-tree-structures)
    - [Strict (Full) Binary Tree](#strict-full-binary-tree)
      - [Concept of Strict Binary Tree](#concept-of-strict-binary-tree)
      - [Height VS Nodes in Strict Binary Tree](#height-vs-nodes-in-strict-binary-tree)
      - [Internal Nodes VS External Nodes in Strict Binary Tree](#internal-nodes-vs-external-nodes-in-strict-binary-tree)
    - [M-ary Tree](#m-ary-tree)
      - [Concept of M-ary Tree](#concept-of-m-ary-tree)
      - [Height VS Nodes in M-ary Tree](#height-vs-nodes-in-m-ary-tree)
      - [Internal Nodes VS External Nodes in a Strict M-ary Tree](#internal-nodes-vs-external-nodes-in-a-strict-m-ary-tree)
    - [Complete Binary Tree](#complete-binary-tree)
  - [Representation of Binary Tree](#representation-of-binary-tree)
    - [Array Representation](#array-representation)
    - [Linked Representation](#linked-representation)
  - [Binary Tree Traversal](#binary-tree-traversal)
  - [Creating Binary Tree using Queue](#creating-binary-tree-using-queue)
  - [Iterative Methods for Binary Tree Traversal](#iterative-methods-for-binary-tree-traversal)
    - [Pre-order Traversal (Iterative Method)](#pre-order-traversal-iterative-method)
    - [In-order Traversal (Iterative Method)](#in-order-traversal-iterative-method)
    - [Post-order Traversal (Iterative Method)](#post-order-traversal-iterative-method)
    - [Level-order Traversal](#level-order-traversal)
  - [Binary Tree Implementation](#binary-tree-implementation)
  - [Concepts of Binary Search Tree](#concepts-of-binary-search-tree)
  - [Operations of Binary Search Tree](#operations-of-binary-search-tree)
    - [Searching in BST](#searching-in-bst)
      - [Recursive Searching in BST](#recursive-searching-in-bst)
      - [Iterative Searching in BST](#iterative-searching-in-bst)
    - [Inserting in BST](#inserting-in-bst)
      - [Recursive Insertion in BST](#recursive-insertion-in-bst)
      - [Iterative Insertion in BST](#iterative-insertion-in-bst)
    - [Deleting from BST](#deleting-from-bst)
    - [Generating a BST from Pre-order](#generating-a-bst-from-pre-order)

## Basic Concepts of Trees

### Concept of Tree

Definition of **Tree**:

A **tree** represents a hierarchical tree structure with a set of connected nodes. Each *node* in the tree can be connected to many *children* (depending on the type of tree), but must be connected to exactly one *parent*, except for the ***root*** node, which has no parent (i.e., the root node as the top-most node in the tree hierarchy).

**Terminology**:

1. **Root**: The root is the topmost node of a tree. It is the only node in the tree that has no parent. Every tree has exactly one root node.
2. **Parent**: In a tree, a parent is a node that has one or more child nodes. Every node, except the root, has exactly one parent.
3. **Child**: A child is a node that has a parent. A node can have zero, one, or multiple children. In a binary tree, a node can have at most two children.
4. **Sibling**: Siblings are nodes that share the same parent. In other words, nodes are siblings if they are at the same level and have the same parent.
5. **Descendant**: A descendant of a node is any node that can be reached by starting at the given node and repeatedly following child links. This includes the node's children, the children of those children, and so on.
6. **Ancestor**: An ancestor of a node is any node that can be reached by starting at the given node and repeatedly following parent links. This includes the node's parent, the parent's parent, and so on, up to the root.
7. **Degree of a Node**: The degree of a node is the ***number of children*** it has. In a binary tree, this is at most two, but in a general tree, it can be any non-negative integer.
8. **Degree of a Tree**: The degree of a tree is the maximum degree of any node in the tree. It represents the highest number of children any single node in the tree has.
9. **Internal/External Node**: Internal nodes are nodes with at least one child. External nodes, also known as leaf nodes, are nodes without children.
10. **Levels (start from 1)**: Levels in a tree structure start from the root. The root is at level 1, its children are at level 2, and so on. The level of a node is a measure of its distance from the root, plus one.
11. **Height of a Tree (start from 0)**: The height of a tree is the length of the longest path from the root to any leaf. It is measured in edges. For an empty tree, the height is -1; for a tree with just a root, the height is 0; and so on.
12. **Forest**: A forest is a collection of disjoint trees. Removing the root of a tree will result in a forest, with each child of the root becoming the root of a new tree in the forest.

### Concept of Binary Tree

Definition of **Binary Tree**:

A **binary tree** is a tree data structure in which each node has at most two children, referred to as the ***left child*** and the ***right child***.

**Left Skewed Binary Tree** and **Right Skewed Binary Tree**:

1. **Left Skewed Binary Tree**: A left skewed binary tree is a type of binary tree in which every node has either zero or one child, and if the child exists, it is always the left child. This means there are no right children in any of the nodes. Visually, such a tree tends to lean or 'skew' towards the left side. This structure results in a tree that resembles a linked list, with all the nodes aligned to the left. The height of a left skewed binary tree with $n$ nodes is $n-1$, assuming we start counting the height from 0 for a single-node tree. This kind of tree is not balanced and can have inefficient operations in terms of time complexity, as operations like search, insert, or delete would have an average and worst-case complexity of $O(n)$, where $n$ is the number of nodes.

2. **Right Skewed Binary Tree**: A right skewed binary tree is the mirror image of a left skewed binary tree. In this tree, each node has either no child or only a right child. This results in the tree being heavily biased or 'skewed' towards the right side. Like the left skewed tree, it also resembles a linked list, but with all nodes aligned to the right. The height of a right skewed binary tree with $n$ nodes is also $n-1$. Similarly, this tree is unbalanced and operations on it can be inefficient, with search, insert, and delete operations having an average and worst-case complexity of $O(n)$.

## Some Properties of Binary Trees

### Number of Possible Binary Trees

Number of possible binary trees with $n$ nodes ( $n$-th **Catalan number**):

$$
C_n=\frac{1}{n+1}C_{2n}^{n}
$$

The Catalan numbers satisfy the recurrence relations:

$$
C_0=1;\ C_n=\sum_{i=1}^n{C_{i-1}C_{n-i}},\ n>0
$$

Among these binary trees, the number of trees with maximum height is $2^{n-1}$.

Number of binary trees with $n$ nodes, being labelled with $n$ kinds of labels:

$$
\frac{C_{2n}^{n}}{n+1}\cdot n!
$$

### Height VS Nodes in Binary Tree

Given binary tree *height* $h$, the ***minimum*** number of *nodes* required for the binary tree is $h+1$, and the ***maximum*** number of *nodes* possible for the binary tree is $1+2+2^2+\cdots +2^h=2^{h+1}-1$.

Given the number of *nodes* of a binary tree as $n$, the ***minimum*** *height* required for the binary tree is $\log _2\left( n+1 \right) -1$, and the ***maximum*** *height* possible for the binary tree is $n-1$.

Therefore, we know that the height of the binary tree satisfies

$$
\underset{O\left( \log n \right)}{\underbrace{\log _2\left( n+1 \right) -1}}\leqslant h\leqslant \underset{O\left( n \right)}{\underbrace{n-1}}
$$

and the number of nodes in a binary tree satisfies

$$
h+1\leqslant n\leqslant 2^{h+1}-1
$$

### Internal Nodes VS External Nodes in Binary Tree

In a binary tree, there's a specific relationship between the number of nodes with degree 0 (leaf nodes) and the number of nodes with degree 2 (internal nodes with two children). This relationship is:

The number of leaf nodes ( ***degree 0*** ) is always **one more** than the number of nodes with ***degree 2***.

## Special Tree Structures

### Strict (Full) Binary Tree

#### Concept of Strict Binary Tree

Definition of **Strict Binary Tree**:

A **strict** binary tree (sometimes referred to as a **proper**, **plane**, or **full** binary tree) is a binary tree in which every node has either 0 or 2 children. In other words, there are no nodes with 1 child.

A full binary tree is either (recursive definition):

- A single vertex (a single node as the root node).
- A tree whose root node has two subtrees, both of which are full binary trees.

#### Height VS Nodes in Strict Binary Tree

Given strict binary tree *height* $h$, the ***minimum*** number of *nodes* required for the strict binary tree is $2h+1$, and the ***maximum*** number of *nodes* possible for the strict binary tree is $1+2+2^2+\cdots +2^h=2^{h+1}-1$ (same as before).

Given the number of *nodes* of a strict binary tree as $n$, the ***minimum*** *height* required for the strict binary tree is $\log _2\left( n+1 \right) -1$ (same as before), and the ***maximum*** *height* possible for the strict binary tree is $\frac{n-1}{2}$.

#### Internal Nodes VS External Nodes in Strict Binary Tree

A strict binary tree with $n$ ***internal nodes*** has $n+1$ ***external nodes***.

### M-ary Tree

#### Concept of M-ary Tree

Definition of $m$-ary Tree:

An $m$-ary tree (for nonnegative integers $m$) (also known as $n$-ary, $k$-ary or $k$-way tree) is an arborescence (i.e., an ordered tree) in which each node has *no more than* $m$ children. A binary tree is the special case where $m=2$, and a ternary tree is another case with $m=3$ that limits its children to three.

A **full** $m$-ary tree (i.e., a **strict** $m$-ary tree) is an $m$-ary tree where within each level every node has 0 or $m$ children.

A **complete** $m$-ary tree (i.e., a **perfect** $m$-ary tree) is a full $m$-ary tree in which all leaf nodes are at the same depth.

#### Height VS Nodes in M-ary Tree

Given $m$-ary tree *height* $h$, the ***minimum*** number of *nodes* required for the $m$-ary tree is $mh+1$, and the ***maximum*** number of *nodes* possible for the $m$-ary tree is $1+m+m^2+\cdots +m^h=\frac{m^{h+1}-1}{m-1}$.

Given the number of *nodes* of an $m$-ary tree as $n$, the ***minimum*** *height* required for the $m$-ary tree is $\log _m\left[ n\left( m-1 \right) +1 \right] -1$, and the ***maximum*** *height* possible for the $m$-ary tree is $\frac{n-1}{m}$.

#### Internal Nodes VS External Nodes in a Strict M-ary Tree

The number of external nodes $e$ and the number of internal nodes $i$ in a strict $m$-ary tree satisfies: $e=(m-1)\cdot i+1$.

### Complete Binary Tree

Definition of **Perfect Binary Tree**:

A **perfect binary tree** is a binary tree in which all *interior nodes* have *two* children and all *leaves* have the *same* depth or same level (the level of a node defined as the number of edges or links from the root node to a node). *A perfect binary tree is a full binary tree.*

The maximum number of nodes in a perfect binary tree is given by the formula $2^{h+1} – 1$, where $h$ is the height of the tree.

Definition of **Complete Binary Tree**:

A **complete binary tree** is a binary tree in which every level, *except possibly the last*, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and $2^h$ nodes at the last level $h$. *A perfect tree is therefore always complete but a complete tree is not always perfect.* A complete binary tree can be efficiently represented using an array with no blank spaces in between.

## Representation of Binary Tree

### Array Representation

- Element at index $i$;
- Left child at index $2i$;
- Right child at index $2i+1$;
- Parent at index $\lfloor \frac{i}{2} \rfloor$.

### Linked Representation

$n$ nodes: $n+1$ `NULL` pointers.

```C++
struct Node {
    struct Node *lchild;
    int data;
    struct Node *rchild;
};
```

## Binary Tree Traversal

Types of binary tree traversal:

- **Pre-order Traversal**:
    - Visit the root node.
    - Traverse the left subtree in pre-order.
    - Traverse the right subtree in pre-order.
    - **Steps**: `VISIT[Root] → PREORDER[Left Subtree] → PREORDER[Right Subtree]`
- **In-order Traversal**:
    - Traverse the left subtree in in-order.
    - Visit the root node.
    - Traverse the right subtree in in-order.
    - **Steps**: `INORDER[Left Subtree] → VISIT[Root] → INORDER[Right Subtree]`
- **Post-order Traversal**:
    - Traverse the left subtree in post-order.
    - Traverse the right subtree in post-order.
    - Visit the root node.
    - **Steps**: `POSTORDER[Left Subtree] → POSTORDER[Right Subtree] → VISIT[Root]`
- **Level-order Traversal**:
    - Visit nodes *level by level* from top to bottom.
    - At each level, visit nodes from left to right.
    - **Steps**: `[Root]`, then `[Root's Children]`, then `[Children's Children]`, etc., moving left to right at each level.

Let's consider a binary tree for illustration:

```
        A
       / \
      B   C
     / \   \
    D   E   F
```

For this tree, the traversals would be as follows:

- **Pre-order Traversal**: A, B, D, E, C, F
    - Visit A, traverse B (visit D, E), traverse C (visit F).
- **In-order Traversal**: D, B, E, A, C, F
    - Traverse B (visit D, E), visit A, traverse C (visit F).
- **Post-order Traversal**: D, E, B, F, C, A
    - Traverse B (visit D, E), traverse C (visit F), visit A.
- **Level-order Traversal**: A, B, C, D, E, F
    - Visit A, visit B and C, visit D, E, and F.

## Creating Binary Tree using Queue

```C++
// Define the Node structure
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Define the BinaryTree class
class BinaryTree {
public:
    Node* root;

    BinaryTree() : root(nullptr) {}

    // Insert a node in the binary tree
    /*
    insert a new node with a given value into the binary tree 
    following a level-order approach, 
    meaning the node is added
    at the first available position from left to right
    */
    void insert(int value) {
        Node* newNode = new Node(value);
        if (!root) {
            root = newNode;
            return;
        }

        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (!temp->left) {
                temp->left = newNode;
                break;
            } else {
                q.push(temp->left);
            }

            if (!temp->right) {
                temp->right = newNode;
                break;
            } else {
                q.push(temp->right);
            }
        }
    }

    // Pre-order Traversal
    void preOrderTraversal(Node* node) {
        if (node == nullptr) return;
        std::cout << node->data << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }

    // In-order Traversal
    void inOrderTraversal(Node* node) {
        if (node == nullptr) return;
        inOrderTraversal(node->left);
        std::cout << node->data << " ";
        inOrderTraversal(node->right);
    }

    // Post-order Traversal
    void postOrderTraversal(Node* node) {
        if (node == nullptr) return;
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        std::cout << node->data << " ";
    }

    // Level-order Traversal
    void levelOrderTraversal() {
        if (root == nullptr) return;

        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            std::cout << temp->data << " ";

            if (temp->left != nullptr) q.push(temp->left);
            if (temp->right != nullptr) q.push(temp->right);
        }
    }

    // Height of the tree
    int height(Node* node) {
        if (node == nullptr) return 0;
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return std::max(leftHeight, rightHeight) + 1;
    }
};
```

The number of function calls for `preOrderTraversal` on a binary tree with $n$ nodes is $2n+1$. The size of the call stack is $h+2$, where $h$ is the height of the tree. Same for `inOrderTraversal` and `postOrderTraversal`.

If the  pre-order/post-order/in-order of a binary tree is given, we cannot generate a unique tree, and the number of possible trees is $\frac{C_{2n}^{n}}{n+1}$. If the pre-order and post-order of a binary tree is given, we still cannot generate a unique tree.

If the pre-order and in-order (or post-order and in-order) of a binary tree is given, we can generate a unique tree.

Generate a Tree from Traversal:

Time complexity: $O(n^2)$

> Example: [Tree creation](./tree_creation.cpp)

## Iterative Methods for Binary Tree Traversal

### Pre-order Traversal (Iterative Method)

**Pseudocode**:

```
function preOrderTraversal(root):
    if root is null:
        return

    create a stack and push root into it

    while stack is not empty:
        node = pop from stack
        print node's value

        if node's right child is not null:
            push node's right child into stack
        if node's left child is not null:
            push node's left child into stack
```

**Explanation**:

- Start with the root node and push it onto a stack.
- While the stack is not empty, pop the top item from the stack and visit it (e.g., print the node's value).
- Since pre-order traversal is Root-Left-Right, push the right child first (if it exists) and then the left child onto the stack. This ensures that the left child is processed first, as the stack is LIFO (Last In, First Out).

### In-order Traversal (Iterative Method)

**Pseudocode**:

```
function inOrderTraversal(root):
    if root is null:
        return

    create a stack
    set current = root

    while current is not null or stack is not empty:
        while current is not null:
            push current into stack
            set current = current's left child

        current = pop from stack
        print current's value
        set current = current's right child
```

**Explanation**:

- The in-order traversal follows the Left-Node-Right pattern.
- Start with the root node. Go to the leftmost node, pushing all the nodes onto the stack along the way.
- When you reach a null (leftmost), pop from the stack, visit the node (e.g., print its value), and then move to its right child.
- Repeat this process: traversing left as much as possible, visiting the node, and then going right.
- The stack keeps track of nodes to be visited after their left subtrees have been fully traversed.
- This process continues until both the stack is empty and the current node is null, which means that every node has been visited in in-order.

### Post-order Traversal (Iterative Method)

**Pseudocode**:

```
function postOrderTraversal(root):
    if root is null:
        return

    create two stacks, stack1 and stack2
    push root into stack1

    while stack1 is not empty:
        node = pop from stack1 and push it into stack2
        if node's left child is not null:
            push node's left child into stack1
        if node's right child is not null:
            push node's right child into stack1

    while stack2 is not empty:
        node = pop from stack2
        print node's value
```

**Explanation**:

- Use two stacks. The first stack is for processing the nodes, and the second stack is for the final post-order traversal output.
- For each node popped from the first stack, push its left and right children to the first stack, and push the node itself to the second stack.
- After processing all nodes, the second stack will have the nodes in post-order. Pop and visit each node from the second stack.

### Level-order Traversal

**Pseudocode**:

```
function levelOrderTraversal(root):
    if root is null:
        return

    create a queue and enqueue root

    while queue is not empty:
        node = dequeue from queue
        print node's value

        if node's left child is not null:
            enqueue node's left child into queue
        if node's right child is not null:
            enqueue node's right child into queue
```

**Explanation**:

- Use a queue to hold the nodes at each level of the tree.
- Start with the root node by enqueuing it.
- While the queue is not empty, dequeue a node, visit it, and then enqueue its left and right children (if they exist).
- This process is repeated for each level of the tree, ensuring level-order traversal.

> Example: [Iterative traversal](./tree_iterative.cpp)

## Binary Tree Implementation

> Example: [Tree implementation](./tree_implementation.cpp)

## Concepts of Binary Search Tree

Definition of **Binary Search Tree**:

A **binary search tree (BST)**, also called an ordered or sorted binary tree, is a rooted binary tree data structure with the key of each *internal node* being ***greater*** than all the keys in the respective node's ***left subtree*** and ***less*** than the ones in its ***right subtree***. The time complexity of operations on the binary search tree is linear with respect to the height of the tree.

Properties of BST:

- No duplicated elements in BST;
- ***In-order traversal*** of BST gives ***sorted order***;
- Given $n$ nodes (each with unique values), we can generate $\frac{C_{2n}^{n}}{n+1}$ BSTs.

BST is represented using linked structure.

## Operations of Binary Search Tree

On average, the insert, delete and search takes $O(\log n)$ for $n$ nodes. In the worst case, they degrade to that of a singly linked list: $O(n)$.

### Searching in BST

Time complexity of searching in BST is $O\left( h \right) , \left( \log n\leqslant h\leqslant n \right)$, where $h$ is the height of the BST and $n$ is the number of nodes. We can also write is as $O(\log n)$.

#### Recursive Searching in BST

**Pseudocode** (tail recursion):

```C++
// Define a function that takes a key and a node as parameters 
function search(key, node) {
    // If the node is null, return null 
    if (node == NULL) { 
        return NULL; 
    } 
    // If the key is equal to the node’s key, return the node 
    if (key == node.key) { 
        return node; 
    } 
    // If the key is less than the node’s key, search in the left subtree 
    if (key < node.key) { 
        return search(key, node.left); 
    } 
    // If the key is greater than the node’s key, search in the right subtree 
    if (key > node.key) { 
        return search(key, node.right); 
    } 
}
```

#### Iterative Searching in BST

**Pseudocode** (iterative method):

```C++
// Define a function that takes a key and a node as parameters 
function search(key, node) { 
    // Initialize a pointer to the node 
    let p = node;
    // Loop until p is null or the key is found 
    while (p != NULL && key != p.key) { 
        // If the key is less than the node’s key, move to the left subtree
        if (key < p.key) { 
            p = p.left;
        } 
        // If the key is greater than the node’s key, move to the right subtree 
        else {
            p = p.right; 
        }
    }
    // Return p, which is either the node with the matching key or null
    return p;
}
```

### Inserting in BST

Generating a BST with $n$ nodes takes $O(n\log n)$ time.

#### Recursive Insertion in BST

**Pseudocode** (recursion):

```C++
// Define a function that takes a key and a node as parameters 
function insert(key, node) { 
    // If the node is null, create a new node with the key and return it 
    if (node == NULL) { 
        return new Node(key); 
    } 
    // If the key is less than the node’s key, insert it in the left subtree 
    if (key < node.key) { 
        node.left = insert(key, node.left); 
    } 
    // If the key is greater than or equal to the node’s key, insert it in the right subtree 
    else { 
        node.right = insert(key, node.right); 
    } 
    // Return the node 
    return node;
}
```

#### Iterative Insertion in BST

**Pseudocode** (iterative method):

```C++
// Define a function that takes a key and a node as parameters 
function insert(key, node) { 
    // Create a new node with the key 
    let newNode = new Node(key); 
    // If the node is null, return the new node 
    if (node == NULL) { 
        return newNode; 
    }
    // Initialize a pointer to the node and a previous pointer 
    let current = node;
    let previous = NULL;
    // Loop until the current pointer is null 
    while (current != NULL) { 
        // Update the previous pointer to the current pointer 
        previous = current;
        // If the key is less than the current node’s key, move to the left subtree 
        if (key < current.key) { 
            current = current.left; 
        } 
        // If the key is greater than or equal to the current node’s key, move to the right subtree 
        else {
            current = current.right;
        } 
    } 
    // If the key is less than the previous node’s key, make the new node the left child of the previous node 
    if (key < previous.key) { 
        previous.left = newNode; 
    } 
    // If the key is greater than or equal to the previous node’s key, make the new node the right child of the previous node
    else { 
        previous.right = newNode;
    }
    // Return the node 
    return node;
}
```

### Deleting from BST

- **In-order Predecessor** of a node: rightmost child its left subtree;
- **In-order Successor** of a node: leftmost child its right subtree.

**Pseudocode**:

```C++
function deleteNode(root, key) {
    // If the root is null, the tree is empty.
    if (root is NULL) {
        return root;
    }

    // If key to be deleted is smaller than the root's key, then it lies in left subtree.
    if (key < root.key) {
        root.left = deleteNode(root.left, key);
    }
    // If key to be deleted is greater than the root's key, then it lies in right subtree.
    else if (key > root.key) {
        root.right = deleteNode(root.right, key);
    }
    // If key is the same as root's key, then this is the node to be deleted.
    else {
        // Node with only one child or no child.
        if (root.left == NULL) {
            temp = root.right;
            free(root);
            return temp;
        } else if (root.right == NULL) {
            temp = root.left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree).
        temp = minValueNode(root.right);

        // Copy the inorder successor's content to this node.
        root.key = temp.key;

        // Delete the inorder successor.
        root.right = deleteNode(root.right, temp.key);
    }

    return root;
}
```

**Handling Different Cases**:

1. **Node to be deleted is a leaf (no children):** Simply remove the node.
2. **Node to be deleted has one child:** Replace the node with its child.
3. **Node to be deleted has two children:** Find the node's inorder successor (the smallest node in its right subtree), copy its value to the node, and delete the successor. Since the successor will have at most one child, we can use the same procedure to delete it.

**Time Complexity Analysis**:

1. **Best Case (Leaf or one child):** $O(\log n)$. This occurs when the tree is balanced, and we're deleting a leaf or a node with one child. The search for the node takes $O(\log n)$ time in a balanced BST.
2. **Worst Case (Two children):** $O(\log n)$ for search + $O(\log n)$ for finding inorder successor = $O(\log n)$. This complexity also assumes a balanced BST. In an unbalanced BST, these operations could degrade to $O(n)$ in the worst case.

**Space Complexity Analysis**:

The space complexity is $O(h)$, where $h$ is the height of the tree. This is due to the recursive nature of the algorithm, which consumes space on the call stack proportional to the height of the tree. For a balanced tree, this is $O(\log n)$, but it can be $O(n)$ in the worst case for an unbalanced tree.

Maintaining the balance of a BST is crucial for ensuring optimal performance of operations. AVL trees or Red-Black trees are types of BSTs that automatically ensure balance after insertions and deletions.

### Generating a BST from Pre-order

In pre-order traversal, the root node is visited first, followed by the left subtree, and then the right subtree. When constructing a BST from a pre-order traversal, we need to identify the root, and then partition the remaining array into two parts: the left subtree (all elements smaller than the root) and the right subtree (all elements greater than the root).

**Pseudocode**:

```C++
Function constructBSTFromPreorder(preorder) {
    if (preorder == empty) {
        return NULL;
    }

    // Create a new node with the first element in the preorder array as the root.
    root = newNode(preorder[0]);
    stack = emptyStack();
    push(stack, root);

    // Iterate over the rest of the preorder array.
    for (i from 1 to length(preorder) - 1) {
        temp = NULL;

        // Keep popping from the stack as long as the current element in preorder
        // is greater than the top element in the stack. This finds the right
        // position (parent node) for the current element.
        while (not isEmpty(stack) and preorder[i] > peek(stack).value) {
            temp = pop(stack);
        }

        // Make this element as the right child and push it to the stack
        if (temp is not NULL) {
            temp.right = newNode(preorder[i]);
            push(stack, temp.right);
        }
        // If the current element is smaller than the top element, make this
        // element as the left child of the stack's top node. Push it to the stack.
        else {
            peek(stack).left = newNode(preorder[i]);
            push(stack, peek(stack).left);
        }
    }

    return root;
}
```

**Explanation**:

- **Initialization:** We start by creating the root of the tree from the first element in the preorder traversal array.
- **Stack Utilization:** A stack is used to keep track of the path we have taken. We use it to find the correct parent for the next node.
- **Partitioning and Building the Tree:**
    - We iterate through the `preorder` array.
    - When we find an element greater than the current top of the stack, it means we have completed the left subtree for the current top and now we must add this new element to the right subtree. We keep popping from the stack until we find the correct parent for this element.
    - If the current element is smaller than the stack's top element, it belongs to the left subtree of the top element of the stack.

**Time Complexity**:

The time complexity of this algorithm is $O(n)$, where $n$ is the number of nodes in the tree. This efficiency is achieved because each node is processed exactly once.

**Space Complexity**:

The space complexity is $O(h)$, where $h$ is the height of the tree. In the worst case (a skewed tree), it can become $O(n)$. However, for a balanced tree, it remains $O(\log n)$. The space is primarily used by the stack for storing the nodes of the tree.
