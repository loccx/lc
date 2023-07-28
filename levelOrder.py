from collections import deque
class Solution:
    def levelOrder(self, root):
        if not root:
            return root
        
        dQ = deque([root])
        results = []
        currLevel = []
        counter = len(dQ)
        while dQ:
            counter = len(dQ)
            for n in range(counter):
                curr = dQ.popleft()
                currLevel.append(curr.val)
                if curr.left: currLevel.append(curr.left)
                if curr.right: currLevel.append(curr.right)
            results.append(currLevel)
            currLevel = []
        return results