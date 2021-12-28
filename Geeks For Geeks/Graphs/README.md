# Graph

1. **Adjacency List and Matrix**
    
2. **BFS**
    
3. **Application of BFS**
    1. Shortest path in an unweighted graph
    2. Social networking search
    3. Cycle detection
    4. Topological sorting
    
4. **DFS**
    
5. **Application of DFS**
    1. Cycle detection
    2. Topological sorting
    3. Path finding
    
6. **Shortest path in Undirected unweighted Graph**
    1. BFS based solution
    
7. **Detect cycle in undirected graph**
    1. **DFS based solution ( passing parent in dfs recursion )
    2. BFS based solution ( storing parent of every node in vector )
    
8. **Topological sorting**
    1. **BFS based solution ( using indegree, and pushing to answer at indegree == 0 )
    2. DFS based solution ( store answer in stack, push the node to stack when dfs of all its child gets completed )
    
9. **Detect cycle in directed graph**
    1. **DFS based solution ( using recursion stack to keep track of nodes in present in same recursion stack or not )
    2. BFS based solution ( topological based, using indegree, and keeping count  of number of nodes visited )
    
10. **Shortest path in direct acyclic unweighted graph**
    1. DFS based ( make topological sort and then calculate distance of adjacent nodes )
    
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