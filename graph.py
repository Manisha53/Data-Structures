#adjacency list implementation of a graph

class graph:
    def __init__(self, vno):
        self.vertex_count = vno
        self.adj_list = {v:[] for v in range(vno)}
    
    def add_edge(self, u, v, weight=1):
        if 0<=u<self.vertex_count and 0<=v<self.vertex_count:
            self.adj_list[u].append((v,weight))
            self.adj_list[v].append((u,weight))
        else:
            print("Invalid vertex")
    
    def remove_edge(self, u, v):
        if 0<=u<=self.vertex_count and 0<=v<self.vertex_count:
            self.adj_list[u] = [(vertex, weight) for vertex, weight in self.adj_list[u] if vertex!=v]
            self.adj_list[v] = [(vertex, weight) for vertex, weight in self.adj_list[v] if vertex!=u]
        else:
            print("Invalid vertex")
    
    def has_edge(self, u, v):
        if 0<=u<=self.vertex_count and 0<=v<self.vertex_count:
            return any(vertex==v for vertex, weight in self.adj_list[u])
        else:
            print("Invalid vertex")
            return False
    
    def print_adj_list(self):
        for vertex, neighbour in self.adj_list.items():
            print(vertex,":",neighbour)

g = graph(5)
g.add_edge(0,1)
g.add_edge(1,2)
g.add_edge(1,3)
g.add_edge(2,4)
g.add_edge(3,4)

g.print_adj_list()

