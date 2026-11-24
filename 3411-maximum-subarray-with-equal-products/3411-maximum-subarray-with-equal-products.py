class Solution:
    def maxLength(self, nums: List[int]) -> int:
        n = len(nums)

        maxi = 0

        for i in range(n):
            prod = 1
            lcmm = 1 
            gcdd = 0
            for j in range(i, n):
                prod *= nums[j]
                lcmm = lcm(lcmm, nums[j])
                gcdd = gcd(gcdd, nums[j])
            
                if prod == lcmm * gcdd:
                    maxi = max(maxi, j - i + 1)

        return maxi