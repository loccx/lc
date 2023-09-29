# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Codec:
    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        cereal = []
        def dfs(node):
            if not node:
                cereal.append('_')
                return

            cereal.append(str(node.val))
            dfs(node.left)
            dfs(node.right)

        dfs(root)
        return ' '.join(cereal)

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        listData = data.split()
        def dfs(ls):
            value = ls.pop(0)
            if value == '_':
                return None

            currNode = TreeNode(value)
            currNode.left = dfs(ls)
            currNode.right = dfs(ls)
        return currNode

        root = dfs(listData)
        return root

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
