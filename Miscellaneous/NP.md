# NP-Complete and NP-Hard Problems

| Polynomial Time Algorithms | Time Complexity | Exponential Time Algorithms | Time Complexity |
|----------------------------|-------------------------|-----------------------------|-------------------------|
| Binary Search              | $O(\log n)$             | Tower of Hanoi              | $O(2^n)$                |
| Merge Sort                 | $O(n \log n)$           | Travelling Salesman Problem (Brute Force) | $O(n!)$  |
| Heap Sort                  | $O(n \log n)$           | Boolean Formula Satisfiability (SAT) | $O(2^n)$  |
| Quick Sort                 | $O(n \log n)$           | Generating Power Set        | $O(2^n)$                |
| Dijkstra's Algorithm       | $O(V^2)$                | Recursive Fibonacci         | $O(2^n)$                |
| Floyd-Warshall Algorithm   | $O(V^3)$                | Exponential Graph Search    | $O(b^d)$                |
| Bellman-Ford Algorithm     | $O(VE)$                 | Hamiltonian Path in a Graph | $O(n!)$                 |
| Insertion Sort             | $O(n^2)$                | Enumerating Permutations    | $O(n!)$                 |
| Bubble Sort                | $O(n^2)$                | Knapsack Problem (Brute Force) | $O(2^n)$            |
| Selection Sort             | $O(n^2)$                | Depth-first Search (in Implicit Graphs) | $O(b^m)$ |
| Breadth-first Search       | $O(V + E)$              |                             |                         |
| Dynamic Programming (e.g., Fibonacci with Memoization) | $O(n)$ |             |                         |
| A* Search Algorithm        | $O(b^d)$                |                             |                         |
| Kruskal's Algorithm        | $O(E \log V)$           |                             |                         |
| Prim's Algorithm           | $O(V^2)$ or $O(E + \log V)$ with Min-Heap |        |                         |

**Note:**

- $n$: size of the input
- $V$: number of vertices in a graph
- $E$: number of edges in a graph
- $b$: branching factor in a graph
- $d$: depth of the graph
- $m$: maximum depth of the search tree
