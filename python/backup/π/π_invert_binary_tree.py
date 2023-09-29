# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        #if root is null, return null
        if not root:
            return root
        #initialize stack with root node
        stack = [root]

        #while the stack is not empty
        while stack:
            #removes top of the stack, and stores it into node
            node = stack.pop()

            #swaps left and right on this node
            node.left, node.right = node.right, node.left

            #if left node is not null
            if node.left:
                # add the left node onto the stack
                stack.append(node.left)
            #if right node is not null
            if node.right:
                # add the right node onto the stack
                stack.append(node.right)
            #eventually stack will become null, then we return the root node which hasn't changed.
            #think of the stack as a double pump shotgun, left and right nodes as shotgun shells. they are swapped, popped out, and refilled if there is more.

        return root

    1
   2 3
 6 7

'''
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return root
        self.invertTree(root.left)
        self.invertTree(root.right)
        root.left, root.right = root.right, root.left
        return root
'''
