class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        # 方法一：快慢指针
        slow, fast = head, head
        while slow and fast and slow.next and fast.next and fast.next.next:
            slow, fast = slow.next, fast.next.next
            if slow == fast:
                return True
        return False
        # 方法二：哈希表，集合
        s = set()
        while head:
            s.add(head)
            head = head.next
            if head in s:
                return True
        return False