class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def reverseKGroup(head, k):
    # Function to reverse a linked list segment
    def reverseLinkedList(head, k):
        prev, curr = None, head
        while k:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt
            k -= 1
        return prev

    # Count total nodes
    count = 0
    node = head
    while node:
        node = node.next
        count += 1

    dummy = ListNode(0)
    dummy.next = head
    group_prev = dummy

    while count >= k:
        kth = group_prev.next
        # Find the kth node
        for i in range(k-1):
            kth = kth.next

        group_next = kth.next
        # Reverse k nodes
        prev, curr = group_next, group_prev.next
        for _ in range(k):
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp

        temp = group_prev.next
        group_prev.next = prev
        group_prev = temp
        count -= k

    return dummy.next

# Helper to print linked list
def printList(head):
    while head:
        print(head.val, end=" -> ")
        head = head.next
    print("NULL")

# Example usage
head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
k = 2
new_head = reverseKGroup(head, k)
printList(new_head)
