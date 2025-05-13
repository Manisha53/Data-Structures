graph = {
    "a":["b", "d"],
    "b":[],
    "c":[],
    "d":["e","g"],
    "e":["c"],
    "f":[],
    "g":["f"]
}

def bfs(graph, source):
    queue=[]
    queue.append(source)
    while queue:
        node=queue.pop(0)
        print(node)

        for neighbour in graph[node]:
            queue.append(neighbour)
bfs(graph, "a")