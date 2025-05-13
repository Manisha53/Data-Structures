graph = {
    "a":["b", "d"],
    "b":[],
    "c":[],
    "d":["e","g"],
    "e":["c"],
    "f":[],
    "g":["f"]
}

# def dfs(graph, source):
#     stack=[]
#     stack.append(source)
#     while stack:
#         node=stack.pop(-1)
#         print(node)
        
#         for neighbour in graph[node]:
#             stack.append(neighbour)


def dfs(graph, source, visited=None):
    if visited is None:
        visited=set()
    visited.add(source)
    print(source)

    for neighbour in graph[source]:
        if neighbour not in visited:
            dfs(graph, neighbour, visited)
    return visited

dfs(graph, "a")