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

5. ***Floor***
    - Here we need to find the largest valued element from bst which smaller than or equal to the given element.
    <br />

6. ***Ceil***
    - Here we need to find the Smallest valued element from bst which larger than or equal to the given element.
    <br />

7. ***Ceil on left side in array***
    - Here we find ceiling of every element present on left side to it in  the array. If not found we return -1.
    <br />
        
    1. Naive
        - Use 2 for Loops and manually find it.
        - TC - O(n^2),  SC - O(n)
        <br />
        
    2. Efficient
        - Use set in c++ and start inserting elements one by one, before every insertion use lower bound funtion to find ceil in the current set.
        - TC - O(n*Log(n)),  SC - O(n)
        <br />

8. Check for BST
    
    
    1. Method 1
        - At every node go to left subtree and find max element, then go to right and get min  value. Now our current element should lie between this min max.
        - Same way check for every node using any traversal.
        - TC - O(n^2),  SC - O(n)
        <br />
        
    2. Method 2
        - Keep a range (min,max) at every point and check the current node’s values lies between it or not.
        - While going to further nodes modify the range according to current node’s value and pass these range in next function call.
        - TC - O(n),  SC - O(n)
        <br />
        
    3. Method 3
        - As we know that inorder traversal of BST gives us a sorted output.
        - Using this fact we will traverse the tree in inorder fashion and keep a prev element in hand to compare the current element with it.
        - TC - O(n),  SC - O(n)
        <br />

9. isPair
    1. Method 1 (inorder traversal)
        - Traverse the tree in inorder fashion and create a array of elements which will be sorted.
        - Now we use 2 pointer technique on sorted array to find the pair.
        <br />
        
    2. Mehthod 2 ( Hashing )
        - Traverse in inorder fashion and keep storing the elements in set of c++.
        - at every node check that; if the current node is included, do we find a pair to make up a target with it. If yes return true. Else store the current element in set and move ahead in our traversal.
        <br />




## Types of Self Balancing Trees

1. ***AVL Trees***
    
    - Height difference of left and right subtree of node should be strictly less than 2 at any point of time.
    - Re-balancing is done when heights of two child subtrees of a node differ by more than one.
    - Faster retrievals as strictly balanced.
    - Due to its strict self-balancing, searching for a element is better than other trees on average. On the other hand insert and delete operations are a bit costlier than others as it requir strict balancing.
    - AVL trees store **balance factors or heights** with each node, thus requires storage for an integer per node whereas Red Black Tree requires only 1 bit of information per node.
    <br />
    
2. ***Red Black Trees***
    
    - Every node is painted with one of the two colors(Red or Black).
    - Root is always black.
    - Both children of red node are black, hence no two consecutive nodes are red.
    - Every simple path from a given node to any of its descendant leaves contains the same number of blacknodes.
    - When Tree is modified ( insert and delete ) , new tree is subsequently rearranged and repainted.
    - It requires 1 bit of color information for each node in tree.
    - Comparing to AVL trees it does not require strict balancing. Path form root to farthest leaf is no more than twice as long as path from root to nearest leaf..
    - Due to this characteristics, insert and delete operation are better than other self balancing trees. On the other hand search operations are a bit costlier.
    - Red Black Trees are used in most of the language libraries like ****map, multimap, multiset ****in C++ whereas AVL trees are used in **databases** where faster retrievals are required.
    <br />

