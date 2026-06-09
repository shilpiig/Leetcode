class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            maxArea = max(maxArea, (right - left) * min(height[left], height[right]));

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;        
    }
};


// class Solution {
// public:
//     int maxArea(vector<int>& heights) {
//         int n = heights.size();
//         int maxArea = 0;

//         for(int i = 0; i < n; i++) {
//             for(int j = i + 1; j < n; j++) {
//                 int area = min(heights[i], heights[j]) * (j - i);
//                 maxArea = max(maxArea, area);
//             }
//         }

//         return maxArea;
//     }
// };