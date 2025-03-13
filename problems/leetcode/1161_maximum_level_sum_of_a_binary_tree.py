from __future__ import annotations

from typing import Optional
from dataclasses import dataclass
from collections import deque


@dataclass
class TreeNode:
    val: int
    left: Optional[TreeNode]
    right: Optional[TreeNode]


class Solution:
    def maxLevelSum(self, root: TreeNode) -> int:
        max_sum: int = -10**10
        max_sum_ind: int = -1

        que = deque()
        que.appendleft(root)

        ind: int = 0

        while que:
            ind += 1
            level_sum = 0
            n = len(que)

            for _ in range(n):
                node: TreeNode = que.pop()

                if node.left:
                    que.appendleft(node.left)
                if node.right:
                    que.appendleft(node.right)

                level_sum += node.val

            if level_sum > max_sum:
                max_sum = level_sum
                max_sum_ind = ind

        return max_sum_ind
