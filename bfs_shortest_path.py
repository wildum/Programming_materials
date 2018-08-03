import sys
from collections import deque

class Graph:
    
    def __init__(self, n):
        self.nodes = {}
        for i in range(1, n+1):
            self.nodes[i] = []

def bfs(n, m, edges, s):
    g = Graph(n)
    for e in edges:
        g.nodes[e[0]] += [e[1]]
        g.nodes[e[1]] += [e[0]]
    q = deque([s])
    close = set()
    dist = [-1]*(n+1)
    dist[s] = 0
    close.add(s)
    while q:
        tmp = q.pop()
        for nei in sorted(g.nodes[tmp]):
            if nei not in close:
                dist[nei] = dist[tmp] + 6
                close.add(nei)
                q.appendleft(nei)
    return [x for x in dist if x != 0][1:]

if __name__ == "__main__":
    q = int(input().strip())
    for a0 in range(q):
        n, m = input().strip().split(' ')
        n, m = [int(n), int(m)]
        edges = []
        for edges_i in range(m):
           edges_t = [int(edges_temp) for edges_temp in input().strip().split(' ')]
           edges.append(edges_t)
        s = int(input().strip())
        result = bfs(n, m, edges, s)
        print (" ".join(map(str, result)))