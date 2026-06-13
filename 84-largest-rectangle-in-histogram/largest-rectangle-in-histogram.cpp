class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            int currHeight = (i == n) ? 0 : heights[i];

            while (!st.empty() && heights[st.top()] > currHeight) {
                int height = heights[st.top()];
                st.pop();

                int width;

                if (st.empty()) {
                    width = i;
                } else {
                    width = i - st.top() - 1;
                }

                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        return maxArea;
    }
};



// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         int ans = 0;

//         for(int i = 0; i < n; i++) {
//             int minHeight = heights[i];

//             for(int j = i; j < n; j++) {
//                 minHeight = min(minHeight, heights[j]);

//                 int width = j - i + 1;
//                 int area = minHeight * width;

//                 ans = max(ans, area);
//             }
//         }

//         return ans;
//     }
// };