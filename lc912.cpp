#include <iostream>
#include <vector>

class Solution {
   public:
    void function(int a, int b, std::vector<int>& nums, std::vector<int>& temp) {
        if (b - a > 1) {
            int m = b / 2;
            function(a, m, nums, temp);
            function(m, b, nums, temp);
            int i = a;
            int j = m;
            while (i < m && j < b) {
                if (temp[i] < temp[j]) {
                    nums[i] = temp[i++];
                } else {
                    nums[i++] = temp[j++];
                }
            }
            while (i < m) nums[i] = temp[i++];
            while (j < m) nums[i++] = temp[j++];
        }
    }
    std::vector<int> sortArray(std::vector<int>& nums) {
        std::vector<int> temp = nums;
        int n = nums.size();
        function(0, n, nums, temp);
        return nums;
    }
};

int main() {
    std::vector<int> nums = {5, 2, 3, 1};
    std::vector<int>& nums2 =
        nums;  // nums2和nums是同个东西。引用实现了指针的功能
    std::vector<int> ans;
    Solution solution;
    solution.sortArray(nums);
    for (int i = 0; i < nums.size(); i++) {
        std::cout << nums[i++];
    }
    return 0;
}