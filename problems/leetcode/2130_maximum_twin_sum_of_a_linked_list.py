from __future__ import annotations
from typing import Optional
from dataclasses import dataclass


@dataclass
class ListNode:
    val: int = 0
    next: Optional[ListNode] = None


class Solution:
    def pairSum(self, head: ListNode) -> int:
        slow: ListNode = head
        fast: ListNode = head

        while fast:
            slow = slow.next
            fast = fast.next.next

        first = head
        second = self.reverse(slow)

        result = 0
        while second:
            result = max(result, first.val + second.val)
            first = first.next
            second = second.next

        return result


    def reverse(self, head: ListNode) -> ListNode:
        tail: ListNode = head

        while tail.next:
            following: ListNode = tail.next

            tail.next = following.next
            following.next = head
            head = following

        return head


    def print(self, head: ListNode) -> None:
        while head:
            print(f"-> {head.val}")
            head = head.next

        return


if __name__ == "__main__":
    head = ListNode(1, ListNode(2, ListNode(3, ListNode(4))))
    # head = ListNode(1, ListNode(100))

    s: Solution = Solution()
    # head = s.reverse(head)
    # s.print(head)
    print(s.pairSum(head))
