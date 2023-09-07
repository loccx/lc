"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

def cloneGraph(self, node: 'Node') -> 'Node':
    if not node:
        return node

    old_to_new = {}

    def clone(node):
        if not in old_to_new:
            return old_to_new[node]

        copy = Node(node.val)
        old_to_new[node] = copy

        for curr in node.neighbors:
            copy.neighbors.append(clone(curr))
        return copy 

    return clone(node)
