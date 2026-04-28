class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        int count = 0;

        for (int start = 0; count < n; start++) {
            int current = start;
            int prev = nums[start];

            do {
                int next = (current + k) % n;
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                count++;
            } while (start != current);
        }
    }
};

// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//        int n = nums.size();
//        int i=0;
//        int j=n-1;
//        while(i<=j){
//         swap(nums[i],nums[j]);
//         i++;
//         j--;
//        }
//     }
// };


// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int n = nums.size();
//         k = k % n;
        
//         reverse(nums.begin(), nums.end());
//         reverse(nums.begin(), nums.begin() + k);
//         reverse(nums.begin() + k, nums.end());
//     }
// };