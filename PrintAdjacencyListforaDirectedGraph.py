# Input: V = 4, edges[][] = {{0, 1}, {1, 2}, {1, 3}, {2, 3}, {3, 0}}
# Output:   0 -> 1
#           1 -> 2 3
#           2 -> 3
#           3 -> 0

class Graph:
    def __init__(self, vno):
        self.vertex = vno
        self.adj_list = {v:[] for v in range(vno)}
