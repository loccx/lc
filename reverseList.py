# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head):
        
        prev = None
        curr = head
        
        while head:
            next = head.next
            head.next = prev
            prev = head
            curr = next
        
        return prev