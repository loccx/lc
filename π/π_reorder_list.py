class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reorderList(self, head):
        """
        Do not return anything, modify head in-place instead.
        """
        #slow: pointer to head
        #fast: pointer to head.next
        slow, fast = head, head.next

        #iterates while the fast pointer has 2 nodes existing ahead of it
        while fast and fast.next:
            #slow iterates one at a time, fast iterates two
            slow = slow.next
            fast = fast.next.next

        #slow ends up in the middle, or right before the middle if there are an even # of nodes. second is set to the second half of the nodes, which will now be reversed.
        second = slow.next
        #initializes previous pointer when used to reverse a linked list
        prev = None
        #cuts the connection between first half and second half of nodes
        slow.next = None
        #iterates while the second pointer exists reverse the linkedlist in the second half
        while second:
            temp = second.next
            second.next = prev
            prev = second
            second = temp

        #first gets assigned to the first node in the first half, since head has never changed
        #second gets assigned to prev, because prev stores the very last node in the second half of the list, from when it was reversed
        first, second = head, prev
        #iterates while there is still stuff in the second half to store
        while second:
            #firstTemp: node after the current node in the first half, we want to store this to set it to the second half's current node.next
            #secondTemp: node after the current node in the second half, we need this to update the second half current node in the next iteration
            firstTemp, secondTemp = first.next, second.next
            #second half curr becomes first half's curr.next
            firstTemp.next = second
            #first half's original curr.next becomes second half curr's next
            secondTemp.next = temp1
            # this is where firstTemp is used to update the "first" pointer
            # this is where secondTemp is used to update the "second" pointer
            first, second = firstTemp, secondTemp
