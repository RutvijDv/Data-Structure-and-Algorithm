1. Application
    - To represent hierarchical data.
    - Binary Search Trees.
    - Binary heap
    - B and B+ Trees in DBMS
    
2. Traversals
    
    All the below traversals can be performed using recursive and iterative method.
    
    |  |  | Recursive Time | Recursive Space | Iterative Time | Iterative Space |
    | --- | --- | --- | --- | --- | --- |
    | InOrder | left - root - right | O(n)   | O(h)   | O(n)   | O(h)   |
    | PreOrder | root - left - right | O(n)   | O(h)   | O(n)   | O(h)   |
    | PostOrder | left - right - root | O(n)   | O(h)   | O(n)   | O(h)   |
    
    For iterative Solution we need to use stack, which will basically replace the use of call stack in recursion.
    
    1. InOrder ( left - root - right ) 
    2. PreOrder ( root - left - right )
    3. PostOrder ( left - right - root )
    
3. Height of tree
    - Recursively go down the tree and add a count whenever you go down a step and keep a check on its max value.
    
4. Level order traversal
    - Traverse the tree in level order.
    - Use simple queue to store the upcoming nodes and search the tree using a while loop.
    
5. Level order traversal line by line
    - use a simple queue once again but here we use a while and a additional for loop inside it to maintain the level one by one, and print them in new line.
    
6. Different view of Binary tree
    
    All the below views of a tree can be achieved using different methods
    
    - Top view
    - Left view
    - Right view
    - Bottom view
    
7. Check for balanced binary tree
    - Naive method
    - Efficient method
    
8. Binary tree to Doubly Linked List
    
    Here we convert binary tree to doubly linked list.  Left pointer becomes prev and right becomes next pointer.
    
9. Construct Binary tree from different traversals.
    
    A binary tree can only be constructed using following combinations.
    
    - inorder + preorder
    - inorder + postorder
    
    Hence inorder traversals has to be there for building a binary tree.
    
10. Tree traversal in spiral form
    - Method 1
    - Method 2

1. Diameter of Tree
    - Method 1
    - Method 2

1. LCA 
    - Method 1
    - Method 2

1. Burn a Binary tree
    - Naive
    - Efficient

1. Serialise and deserialise binary tree

- Serialise
    
    
- Deserialise

---

---

## Important Questions