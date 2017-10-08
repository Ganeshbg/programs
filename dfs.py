
import collections

graph = {'A': set(['B', 'C']),
         'B': set(['A', 'D', 'E']),
         'C': set(['A', 'F']),
         'D': set(['B']),
         'E': set(['B', 'F']),
         'F': set(['C', 'E'])}
         
def dfs(graph, start):
    visited, stack = collections.OrderedDict(), [start]
    while stack:
        print (stack)
        vertex = stack.pop()
        if vertex not in visited:
            visited[vertex]=None
            stack.extend(graph[vertex] - visited.keys())
    return visited

print (dfs(graph, 'A').keys()) # {'E', 'D', 'F', 'A', 'C', 'B'}

