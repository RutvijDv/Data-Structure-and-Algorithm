# BST

1. ***Need***
    
    | Process | O(Log(n)) |
    | --- | --- |
    | Insert  | O(Log(n)) |
    | Delete | O(Log(n)) |
    | Find closest | O(Log(n)) |
    | Sorted Traversal | O(n) |
    <br />

2. ***Search***
<br />
    
    
3. ***Insert***
    
    Search appropriate place and add a node
    <br />
    
4. ***Delete***
    - Basic idea is, we will will delete the required node and in place of that, we will replace it with its successor element in inorder traversal.
    - Case - 1 - left of node to be deleted is empty, —>  delete the node and return node→right.
    - Case - 2 - right of node to be deleted is empty, —>  delete the node and return node→left.
    - Case - 3 - left and right subtree of node to be deleted exists  —> replace our node with next element from its inorder traversal and delete that element from its original place. For finding that next element we just go to right of our current node and then keep going let till we encounter a leaf, that leaf node is our tagret node.
    <br />

    