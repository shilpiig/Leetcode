class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            long long totalHours = 0;

            for (int bananas : piles) {
                totalHours += (bananas + mid - 1) / mid;
            }

            if (totalHours <= h) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};


// class Solution {
// public:
//     int minEatingSpeed(vector<int>& piles, int h) {
//         int n = piles.size();

//         int m = *max_element(piles.begin(), piles.end());

//         for (int k = 1; k <= m; k++) {
//             long long totalHours = 0;

//             for (int i = 0; i < n; i++) {
//                 totalHours += (piles[i] + k - 1) / k; 
//             }

//             if (totalHours <= h) {
//                 return k;
//             }
//         }

//         return -1;
//     }
// };