## DFS

- DFS looks like in order traversal on Binary Tree
- BFF looks like order traversal on tree

- recurion levels of difficulty
- tally recursion: factorial
- chain recursion: fabonatchi or binary tree
- DFS: has list of neigbours, cycles
- DP:

- Time Complexity
  - DFS: N + M (node and edges)
  - Binary Tree (N + 2 N) node + edges = ~ 3N ~ N

---

##### leetcode_690_employee

- sol1: map IDs to 0 to N-1
- sol2: use unordered_map to represent each employee with number(id)
- there is no visited array because it a rooted tree

###### note

- DAG (Directed Uncycled Graph)
- Every rooted tree is DAG but not Every DAG is rooted tree
- rooted tree dosen't need to visited array
- DAG may need to visited array

##### time complexity for DFS on matrix

- O(E+V) assume matrix 100 \* 100
- #of Nodes = 10k
- #of edges = 10k \* 4 = 40k
- around 50k == 5N == N
- so complexity is O(N)

- reachablility == connected components == flood fill
