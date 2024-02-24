#include <limits.h>

#include <iostream>
#include <vector>

class Solution {
   public:
    int maxSubArray(std::vector<int>& nums) {
        int mins = 0;
        int ans = INT_MIN;  // 如果vector是空的情况考虑在内，
                            // 否则nums[0]会segmentation fault
        int cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur += nums[i];
            int temp = cur - mins;
            ans = std::max(temp, ans);
            mins = std::min(cur, mins);  // max min是std::，只在c++可以用，C不行
        }
        return ans;
    }
};

int main() {
    std::vector<int> nums;
    nums = {-2, -1};
    Solution solution;
    std::cout << solution.maxSubArray(nums);
    return 0;
}