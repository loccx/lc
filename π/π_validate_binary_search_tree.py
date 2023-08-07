# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        # if there is no tree, return nothing
        if not root:
            return []

        # stack for iterative calls, tuples stores node and the min/max around it
        stack = [(root, float("-inf"), float("inf"))]

        #iterates until stack is empty
        while stack:
            node, min_val, max_val = stack.pop()

            # maximum value of a left node must be <= parent and >= minimum
            # maximum value of a right node must be >= parent and <= maximum
            if node.val <= min_val or node.val >= max_val:
                return False
            if node.left:
                new_stack.append((node.left, min_val, node.val))
            if node.right:
                new_stack.append((node.right, node.val, max_val))
        # if the entire tree adheres to these requirements, then it is a valid tree
        return True
