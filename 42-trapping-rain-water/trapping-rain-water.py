class Solution:
    def trap(self, height: List[int]) -> int:
        left, right = 0, len(height)-1
        left_max,right_max = 0,0
        ans =0
        while left<right:
            if height[left]<height[right]:
                if height[left]>left_max: 
                    left_max = height[left]
                else:
                    ans+= left_max-height[left]
                left += 1

            else:
                if height[right] >= right_max: 
                     right_max= height[right]
                else: 
                    ans += (right_max - height[right])
                right -= 1

        return ans

# left = 0
# right = 5
# left_max = 0,
# right_max = 5
# ans = 0

# i=1 we ans =2, left_max =4, right_max=5 , 
# i=3 ans = 6, left

