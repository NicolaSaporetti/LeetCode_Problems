class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        d = {}
        x = 0
        for i in nums:
            if i in d and x-d[i]<=k:
                return True
            d[i]=x
            x=x+1
        return False