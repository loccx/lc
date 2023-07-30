"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

def cloneGraph(self, node: 'Node') -> 'Node':
    # if the initial node is null, then there is nothin to clone
    if not node:
        return None
        
    # keys: original node, values: copied node
    old_to_new = {}
    
    # recursive call for each node
    def clone(node):

        # if the node for processing is already processed, then return the copied node
        if node in old_to_new:
            return old_to_new[node]
        
        #creates copy of node that got fed into recursion
        copy = Node(node.val)
        old_to_new[node] = copy

        #for every node in node.neighbors; list of nodes
        for curr in node.neighbors:
            #copy.neighbors initially empty
            #if curr node is already in hashmap, then it returns the clone of the node to append to the clone.neighbors
            copy.neighbors.append(clone(curr))
        # after making recursive calls to the each node's link, return the copied node if it wasn't already existing.
        # if it existed already, it wouldn't have been copied anyways, it would just be returned from the hashmap
        return copy 
    
    #return the recursive call
    return clone(node)
