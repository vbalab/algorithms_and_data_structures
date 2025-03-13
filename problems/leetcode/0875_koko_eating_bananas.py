from typing import List


class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l: int = 1
        r: int = max(piles)

        while l < r:
            m: int = l + (r - l) // 2

            if self.hoursToEat(piles, m) > h:
                l = m + 1
            else:
                r = m

        return l


    def hoursToEat(self, piles: List[int], k: int) -> int:
        # return sum(map(piles, lambda x: x // k + int(x % k != 0)))
        return sum(map(lambda x: (x + (k - 1)) // k, piles))
