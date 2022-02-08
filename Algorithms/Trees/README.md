# Trees

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
    
    Iterative solution steps:
    
    1. Use stack to keep track of all the visited nodes. push the root to stack initially
    2. The main fundamental point is we will go left till we reach a null point and store all those node in stack and then one by one we will got to right of those stored nodes.
    3. Main while loop if ( curr≠NULL || !st.empty() ).
    4. Inside it another while loop if( curr≠NULL )  
    5. Here in second loop we will go to left as much as possible.
    6. Out of it we will pop one element from stack and move our curr to right of this popped element.
    7. We will use our printing statement according to our need, at appropriate place in this for loop.
    
3. Height of tree
    - Recursively go down the tree and add a count whenever you go down a step and keep a check on its max value.
    - TC - O(n),  SC - O(n)
    
4. Level order traversal 
    - Traverse the tree in level order.
    - Use simple queue to store the upcoming nodes and search the tree using a while loop.
    - TC - O(n),  SC - O(n)
    
5. Level order traversal line by line
    - use a simple queue once again but here we use a while and a additional for loop inside it to maintain the level one by one, and print them in new line.
    - TC - O(n),  SC - O(n)
    
6. Different view of Binary tree
    
    All the below views of a tree can be achieved using different methods
    
    - Top view
        
        Here we will use the concept of level order traversal and keep track of distance of every node and push this dis along with node in our queue. At every node we will check if we have encountered a node with same distance previously. If no push this nodes data in our map with its distance, else do nothing and continue. At the end empty this whole map in our answer vector.
        
        TC - O(n),  SC - O(n)
        
    - Left view
        - Use level order traverasal line by line and store first element.
        - Use inorder traversal with a counter to keep track of level ( root is at level 0 ), whenever a new max level element is found, store it. This is because the left most element is first to encounter at every level.
        - TC - O(n),  SC - O(h)
        
    - Right view
        - Use level order traverasal line by line and store last element.
        - Use inorder traversal where we visit right side before we visit left one, with a counter to keep track of level ( root is at level 0 ), whenever a new max level element is found, store it. This is because the left most element is first to encounter at every level.
        - TC - O(n),  SC - O(h)
    
    - Bottom view
        
        Same as top view but instead of updating our map only when we encounter that distance first time, here we will update it every time we encounter that same distance.
        
        TC - O(n),  SC - O(n)
        
    
7. Check for balanced binary tree
    - Naive method
        - use inorder traversal or any other.
        - At every node you are supposed to check if it is balanced or not.
        - For that we will recursively call a height function at every node to check its left and right height.
        
    - Efficient method
        - Here we will collectively calculate the height and is balanced or not, hence at every node we will not require to calculate height.
        - Our function isBalanced(Node* root) will return an integer. If that is -1 hence your root node is not balanced, else if its positive, its height of tree from that that node.
    
8. Binary tree to Linked List
    
    Here we convert binary tree to linked list.
    
    - Singly Linked list
        
        ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/4bcce782-809e-4c2e-a02c-c236e006fa59/Untitled.png)
        
        In this conversion left child of every node becomes null, and right child points to next node in linked list.
        
        - Here we will basically follow a pre-order concept. As first node is processed and then left and then right childs are processed.
        - A prev pointer will always point to the tail of the latest linked list prepared.
        - Initially if prev is null root is set to prev, else prev→right  is set to curr-root.
        - prev = root, in every iteration.
        - After this we flatten(left childs), and then flatten(right childs).
        
    - Doubly Linked List
        
        ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/521afab3-e083-4cac-8585-c5c90f847a4e/Untitled.png)
        
        In this conversion left child of every node points to previous node in LL, and right child points to next node in LL.
        
        - Here we will basically follow a in-order concept. As first left is processed and then curr-node and then right childs are processed.
        - A prev pointer will always point to the tail of the latest linked list prepared.
        - Head is returned from flatten(left child).
        - Initially if prev is null Head is set to root, else root→left = prev and prev→right = root.
        - prev = root, in every iteration.
        - After this we flatten (right childs).
    
    TC - O(n),  SC - O(h)
    
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