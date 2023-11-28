# Introduction to Trees

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

### Internal Nodes VS Internal Nodes in Binary Tree

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

#### Internal Nodes VS Internal Nodes in Strict Binary Tree

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

#### Internal Nodes VS Internal Nodes in a Strict M-ary Tree

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
