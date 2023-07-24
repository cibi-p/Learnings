# Data Structure  and Algorithm (Python)

## Notation (Big O Notation)

- O(n) 
- O(log(n))
 
## Collections
### Lists
- Arrays
    - List of element of same datatype
    - Will have consecutive memory location


### Linkedlist

### Stack

### Binary Search
Efficieny: O(log2(n)) or O(log(n)).   
<sup>In computer science log2 is refered as log but in general log10 is refered as log and log2 as ln</sup>

### Merge sort
### Quick Sort

### set, MAP, HASH
### Hash Map

### Trees
**Properties:**
- Every element in the tree should be reachable from the root node of the tree
- Tree should not has cycles or loops formed by a nodes.

**Tree Terminology**
![](https://media.geeksforgeeks.org/wp-content/uploads/20221124153129/Treedatastructure.png)
<sub>Node in the Lower level(root) is also called as ancestor and Node at the higher level(leaf nodes) are also called as descendant.\
**Paths** is path of the particular node from root node. ex: path of node A is G->B->A in the below tree
</sub>

![](https://www.cs.cornell.edu/courses/cs2112/2021fa/lectures/trees/tree_anatomy.png)

**Tree Traversal**
- Depth First Search
    - Pre-order Traversal
    - In-order Traversal
    - Post-order Traversal
- Breadth First Search (Level Order Traversal)

**Depth First Traversals**
![Type of DFS](https://leetcode.com/articles/Figures/145_transverse.png)
![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/Preorder-from-Inorder-and-Postorder-traversals.jpg)

## Search and Delete
## Insert in tree

## BST

## Heaps
heaps is similar to tree, it has any number of children. it has two types
- max Heap(root has the Max. number, value of the childrens are less than parents)
- Min Heap (root has the Min. Number, value of the childres are greater than parents)
![Tyeps of heap](https://media.geeksforgeeks.org/wp-content/cdn-uploads/20221220165711/MinHeapAndMaxHeap1.png)

We can also use HEAP has Binary Heap,(means parents has 1 or 2 children only)

**Search**\
worst: O(n)\
Average: O(n/2) ~= O(n), since we know all the element below the parent node are below or above the find_val, based on the type of heap we used. so, based on the simple companision we can omit the sub tree if the value is greater or less than the node value.(based on the heap type)

**Insert**\ (heapify)
Worst: O(log(n)) also for deletion

## Balanced Tree
**Self-Balancing trees:** In the tree world, a balanced tree has nodes condensed to only a few levels, while an **unbalaned tree** has nodes spread out among many levels. 

Most common example is **Red-Black Tree**\
Red-Black tree is a binary search tree in which every node is colored with either red or black. It is a type of self balancing binary search tree. It has a good efficient worst case running time complexity.

**Properties of Red Black Tree:**
The Red-Black tree satisfies all the properties of binary search tree in addition to that it satisfies following additional properties –

1. Root property: The root is black.

2. External property: Every leaf (Leaf is a NULL child of a node) is black in Red-Black tree.

3. Internal property: The children of a red node are black. Hence possible parent of red node is a black node.

4. Depth property: All the leaves have the same black depth.

5. Path property: Every simple path from root to descendant leaf node contains same number of black nodes. 

The result of all these above-mentioned properties is that the Red-Black tree is roughly balanced.

**Rules That Every Red-Black Tree Follows:** 
Every node has a color either red or black.
The root of the tree is always black.
There are no two adjacent red nodes (A red node cannot have a red parent or red child).
Every path from a node (including root) to any of its descendants NULL nodes has the same number of black nodes.
 Every leaf (e.i. NULL node) must be colored BLACK.
Why Red-Black Trees?
Most of the BST operations (e.g., search, max, min, insert, delete.. etc) take O(h) time where h is the height of the BST. The cost of these operations may become O(n) for a skewed Binary tree. If we make sure that the height of the tree remains O(log n) after every insertion and deletion, then we can guarantee an upper bound of O(log n) for all these operations. The height of a Red-Black tree is always O(log n) where n is the number of nodes in the tree. 

Sr. No.	Algorithm	Time Complexity
1.	Search	O(log n)
2.	Insert	O(log n)
3.	Delete	O(log n)
![red black tree](https://media.geeksforgeeks.org/wp-content/uploads/20220602135051/3NodedRedBlacktree.jpg)

**Tree Rotation**\
The below image shows the simple example of the tree rotation in the red-black tree.(Note: there are many cases and many steps based on the positions of the nodes)

![Tree rotation](https://www2.cs.ccu.edu.tw/~tmh104u/rotate5.png)

## Graph
A Graph is a non-linear data structure consisting of vertices and edges. The vertices are sometimes also referred to as nodes and the edges are lines or arcs that connect any two nodes in the graph. More formally a Graph is composed of a set of vertices( V ) and a set of edges( E ). The graph is denoted by G(E, V).

![Graph](https://media.geeksforgeeks.org/wp-content/uploads/20200630111809/graph18.jpg)

**Components of a Graph**

**Vertices:** Vertices are the fundamental units of the graph. Sometimes, vertices are also known as vertex or nodes. Every node/vertex can be labeled or unlabelled.

**Edges:** Edges are drawn or used to connect two nodes of the graph. It can be ordered pair of nodes in a directed graph. Edges can connect any two nodes in any possible way. There are no rules. Sometimes, edges are also known as arcs. Every edge can be labeled/unlabelled.

Graphs are used to solve many real-life problems. Graphs are used to represent networks. The networks may include paths in a city or telephone network or circuit network. Graphs are also used in social networks like linkedIn, Facebook. For example, in Facebook, each person is represented with a vertex(or node). Each node is a structure and contains information like person id, name, gender, locale etc.

### Direction and Cycles
Cycles are allowed in graphs unlike tree
![Directed and undirected graph](https://media.geeksforgeeks.org/wp-content/uploads/20200630114438/directed.jpg)

**Connectivity**
Connected graph has no disconnected vertices(node)
consider graph a graph 1 has less firends and graph 2 has more fiends. Graph 2 has more connectivity,

Graph 1:\
![less connectivity graph](https://media.geeksforgeeks.org/wp-content/uploads/simplegraph.png)

Graph 2:\
![High connectivity graph](https://media.geeksforgeeks.org/wp-content/uploads/simple2-1.png)

**Graph Representations:**
