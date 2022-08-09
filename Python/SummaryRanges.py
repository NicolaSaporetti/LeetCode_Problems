class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        myL = []
        i=0
        while len(nums)>i:
            start = i
            while len(nums)>i+1 and nums[i+1]==nums[i]+1:
                i=i+1
            if start == i:
                myL.append(str(nums[start]))
            else :
                myL.append(str(nums[start])+"->"+str(nums[i]))
            i=i+1
        return myL