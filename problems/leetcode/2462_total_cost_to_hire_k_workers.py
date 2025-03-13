from typing import List
import heapq

class Solution:
    def totalCost(self, costs: List[int], k: int, candidates: int) -> int:
        lhp = []
        rhp = []

        l = 0
        r = len(costs) - 1

        total_cost = 0

        for _ in range(k):
            while l <= r and len(lhp) < candidates:
                heapq.heappush(lhp, costs[l])
                l += 1
            while l <= r and len(rhp) < candidates:
                heapq.heappush(rhp, costs[r])
                r -= 1

            if (lhp and rhp and lhp[0] <= rhp[0]) or not rhp:
                total_cost += heapq.heappop(lhp)
            else:
                total_cost += heapq.heappop(rhp)

        return total_cost

if __name__ == "__main__":
    Solution.totalCost(Solution(), [17,12,10,2,7,2,11,20,8], 3, 4)
