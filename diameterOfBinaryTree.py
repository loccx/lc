# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterCalc(self, r):
        left = self.diameterCalc(r.left) if r.left else 0
        right = self.diameterCalc(r.right) if r.right else 0
        currDiam = left + right
        if currDiam > self.maxDiam:
            self.maxDiam = currDiam
        return max(left, right) + 1
        

    def diameterOfBinaryTree(self, root):
        self.maxDiam = 0
        self.diameterCalc(root)
        return self.maxDiam



'''
STANDARD TREE QUESTION FORMAT
def solution(self, root):
	def solve(root):
		if not root:
			# do something
		solve(root.left)
		solve(root.right)
		return # something
	solve(root)
	return # something
'''