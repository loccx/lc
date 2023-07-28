# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        stasis = curr = head
        count = 0
        while curr:
            curr = curr.next
            count += 1

        if n == count:
            return stasis.next

        prev = ListNode()
        prev.next = stasis
        for x in range(count - n):
            stasis = stasis.next
            prev = prev.next
        prev.next = stasis.next

        return head

