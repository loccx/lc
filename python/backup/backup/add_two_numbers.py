# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        finalSum = ListNode()
        curr = finalSum
        carry = 0
        while l1 and l2:
            curr.val = (l1.val + l2.val) % 10 + carry
            carry = (l1.val + l2.val) // 10
            newDigit = ListNode()
            curr.next = newDigit
            curr = curr.next
        return finalSum

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        if not l1:
            return l2
        if not l2:
            return l1

        curr = l1
        other = l2
        while curr:
            curr.val = (curr.val + other.val) % 10 + carry
            carry = (curr.val + other.val) // 10
            curr, other = curr.next, other.next
