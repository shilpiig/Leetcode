
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;

        for (int j = 0; j < nums.size(); j++) {
            if (k < 2 || nums[j] != nums[k - 2]) {
                nums[k] = nums[j];
                k++;
            }
        }

        return k;
    }
};
