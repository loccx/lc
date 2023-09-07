# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:

        #depth is 0 if there isn't a root
        if not root:
            return 0

        #load the stack with a tuple of the root node and the stored depth
        stack = [(root, 1)]
        #max_depth is 0 for now
        max_depth = 0

        while stack:
            #processes one node at a time, order does not really matter, each node keeps track of it's own depth since it is passed down through each stack.append call.
            node, depth = stack.pop()
            #there will be multiple different depths depending on how complex the tree is, this will store the largest depth at any moment
            max_depth = max(max_depth, depth)

            #if node.left is not empty, then there is another node, so the new node will be queued up for depth calculation, while it stores it's own depth, which will be the current node depth + 1
            if node.left:
                stack.append((node.left, depth + 1))
            #same thing here
            if node.right:
                stack.append((node.right, depth + 1))

        #finally return the max depth
        eturn max_depth
