# Graph

1. **Adjacency List and Matrix**
    
2. **BFS** (Breath First Search)
    Breadth first search is a graph traversal algorithm that starts traversing the graph from root node and explores all the neighbouring nodes. Then, it selects the nearest node and explore all the unexplored nodes. The algorithm follows the same process for each of the nearest node until it finds the goal.
    
3. **Application of BFS**
    1. Shortest path in an unweighted graph
    2. Social networking search
    3. Cycle detection
    4. Topological sorting
    
4. **DFS**
    Depth first search (DFS) algorithm starts with the initial node of the graph G, and then goes to deeper and deeper until we find the goal node or the node which has no children. The algorithm, then backtracks from the dead end towards the most recent node that is yet to be completely unexplored.
    
5. **Application of DFS**
    1. Cycle detection
    2. Topological sorting
    3. Path finding
    
6. **Shortest path in Undirected Unweighted Graph**
    1. BFS based solution
        - simple bfs algorithm with just one modification
        - we need to update the dist[v] = dist[u] + 1 at point where you push your child nodes to qeueue for further process.
    
7. **Detect cycle in undirected graph**
    1. **DFS based solution ( passing parent in dfs recursion )
        - simple dfs algorithm with one more argument i.e. parent node, initially pass parent as -1.
        - in dfs function check if the child node we are goign to visit is parent or not.
        - if it is parent, leave and continue for next child node.
        - if it is not parent but is already visited then return true, as we found the loop.
        - concept of this algorithm relies on the fact that while finding the child of current nodes we will also encounter the parent node in out child's list, hence we keep check od parent element and handle other nodes normally.

    2. BFS based solution ( storing parent of every node in vector )
        - simple bfs algorithm with one extra set of requirements.
        - we need to maintain the parent of every element in parent vector.
        - same way as above we will check if the child is parent or not.
        - initially everyone's parent would be -1.
        - as we go through the loop we will update the parents accordingly.
        - similarly here also we would check if child is parent or not.
        - if yes, leave and continue to next child.
        - if not and is still visited, return true, as the loop is found.
        - concept of this algorithm relies on the fact that while finding the child of current nodes we will also encounter the parent node in out child's list, hence we keep check od parent element and handle other nodes normally.
    
8. **Topological sorting**
    1. **BFS based solution ( using indegree, and pushing to answer at indegree == 0 )
        - indegree refers to the number of incoming edges to the node.
        - calculate indegree of all the nodes.
        - push the 0 indegree elements to the queue.
        - start the loop for child nodes of elements in queue.
        - everytime we encounter a child node decrease its indegree.
        - at same point if indegree of that element becomes zero, push it to the queue.
        - here the concept is, indegree becomes zero when all its parent are a parent of response array hence now its the turn of current node to be a part of response array.

    2. DFS based solution ( store answer in stack, push the node to stack when dfs of all its child gets completed )
        - keep visited boolean array of nodes.
        - keep stack which will stores nodes in reverse order.
        - simple dfs algorithm with stack as one more argument.
        - at the end of dfs function make stack.push(i).
        - after all the recursion is done push the elements of stack one by on into an array which will be your response.
        - here the concept is you keep going deeper and deeper till the child node which is not a parent of anyone is reached and is pushed to the stack, same way all its parents in back tracking manner gets pushed to the stack.
    
9. **Detect cycle in directed graph**
    1. **DFS based solution ( using recursion stack to keep track of nodes in present in same recursion stack or not )
        - keep visited boolean array of nodes.
        - keep recursion seen boolean which stores data about the node was included in current recursion stack or not.
        - simple dfs algorithm with recursion seen as one more argument.
        - at the start of dfs function make recursion seen[i] = true.
        - at the end of dfs function make recursion seen[i] = false.
        - while visiting child nodes, if node is not even visited go for dfs and return true if that dfs call returns true.
        - else when node is visited, ans is also present in seen array then its is the point we find the loop return true else go for next child node.
        - basically the concept is if a child element is visited and was also seen in the current resursion stack, we confirm that there loop. 

    2. BFS based solution ( topological based, using indegree, and keeping count  of number of nodes visited )
        - use the concept of topological sort.
        - before moving inside the while loop with your queue, assign a counter c = 0.
        - every time you pop a item from queue make c = c+1
        - and at last out of the loop check c == V or not.
        - basically the concept is if there is a loop then the number of node whose indegree will become zero in loop will never be equal to total nodes, hence not all nodes will become indegree = 0.
        - this is because in a loop of directed edges everyone is depenedent on each other hence is a endless loop.
    
10. **Shortest path in directed acyclic unweighted graph**
    1. DFS based ( make topological sort and then calculate distance of adjacent nodes )
        - get topological sort array.
        - pick one by one element of the sorted array as u, and update its al child (v)'s dis value as -> dis[v] = dis[u]+weight(u,v) if dis[v] was greater than the dis[u]-w(u,v) set value
    
11. **Prims’s Algorithm/ Minimum spanning tree ( weighted and undirected connected graph only )**
    
    connecting all nodes ( even through other node ) with minimum total weight.
    
    Algorithm
    
    - number of nodes = V
    - number of edges required for spanning tree = V-1
    - create 2 sets of nodes - i) included in MST ii) not included in MST
    - gradually keep picking the minimum edge that connects the set i) to any node of set ii)
    - this way we shift node one by one from set ii) to set i)
    
12. **Dijikstra’s Algorithm ( weighted and undirected graph, minimum distance from source to all vertices )**
    
13. **BellmanFord’s Algorithm**
    1. Process all edges V times and relax them.
    2. lastly use one more for loop to check negative cycle.