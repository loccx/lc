# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        curr = head
        seen = {}

        while curr:
            if curr not in seen:
                seen[curr] = 0
            else:
                return True
            curr = curr.next
        return False
