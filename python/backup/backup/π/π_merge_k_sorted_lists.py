# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists):
        head = ListNode(none)
        curr = head
        #h will be our heap queue
        h = []

        for i in range(len(lists)):
            #if statement because we don't want to push a null value into the heap
            if lists[i]:
                #tuple heap position is determined by the first value in the tuple, and if they are equal, it is determined by the second value, and so forth. "lexigraphically" is the word to describe it.
                #pushes tuple into the heap
                #THIS ONLY PUSHES THE FIRST NODE FROM EACH LINKED LIST, the rest of the nodes are added as they are removed in the second while loop down there
                heapq.heappush(h, (lists[i].val, i))
                #iterates to next node within the currently selected linked list
                lists[i] = lists[i].next
        
        #continues running while the heap is not empty
        while h:
            #heap right now contains the first node from each linkedlist in the array
            #heappop removes and returns the smallest item in the heap
            #heappop returns IndexError if the heap is empty, thankfully the while loop only runs when the heap is non-empty
            val, i = heapq.heappop(h)
            #create node for each minimum value removed, and link it to the head to build the new linked list
            curr.next = ListNode(val)
            #increment curr to continue adding
            curr = curr.next
            #if the linked list is not empty at the current selected linkedlist
            #the "lists[i] = lists[i].next" shifts the node, so lists[i] points to an incremented node in the linkedlist. when reaching the end of a linkelist or if it was empty, it becomes None
            if lists[i]:
                #then push into the heap the next node in the linkedlist at index i
                heapq.heappush(h, (lists[i].val, i))
                #increment to the next node, the heappop will automatically reach every single node as they are popped because we are removing them while adding the next node in a selected linked list based on the index that is passed (i).
                lists[i] = lists[i].next

        #head is a dummy node, return head.next for the created linkedlist
        return head.next
