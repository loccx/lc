class Solution:
    def mergeTwoLists(self, list1, list2):
        dummy = ListNode()
        curr = dummy
        
        while list1 and list2:
            if list1.val < list2.val:
                curr.next = list1
                list1 = list1.next
                curr = list1
            else:
                curr.next = list2
                list2 = list2.next
                curr = list2

        if list1 or list2:
            curr.next = list1 if list1 else list2

        return dummy.next
