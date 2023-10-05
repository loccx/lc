# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:

        def path(node):
            if not node:
                return 0
            leftSum = max(path(node.left), 0)
            rightSum = max(path(node.right), 0)
            self.maximum_sum = max(self.maximum_sum, leftSum + rightSum + node.val)
            return node.val + max(leftSum, rightSum)

        self.maximum_sum = float("-inf")
        path(root)
        return self.maximum_sum
