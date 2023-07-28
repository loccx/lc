from collections import deque
class Solution:
    def findTarget(self, root, k):
        if not root:
            return False
        q, diff = deque([root]), set()
        
        while q:
            curr = q.popleft()
            if curr.val in diff:
                return True
            else:
                diff.add(k - curr.val)
                if curr.left:
                    q.append(curr.left)
                if curr.right:
                    q.append(curr.right)
        return False



'''def findTarget(self, root, k):
        values = set()
        def traverse(r):
            if not r:
                return None
            else:
                traverse(r.left)
                values.add(r.val)
                traverse(r.right)
        traverse(root)

        seen = []
        for value in values:
            remaining = k - value
            if remaining in seen:
                return True
            else:
                seen.append(value)'''