# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return []
        stack = [(root, float("-inf"), float("inf"))]
        while stack:
            node, min_val, max_val = stack.pop()
            new_stack = []
            if node.val <= min_val or node.val >= max_val:
                return False
            if node.left:
                new_stack.append((node.left, min_val, node.val))
            if node.right:
                new_stack.append((node.right, node.val, max_val))
            stack = new_stack
        return True
