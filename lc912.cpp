#include <iostream>
#include <vector>

class Solution {
   public:
    void function(int a, int b, std::vector<int>& nums,
                  std::vector<int>& temp) {
        if (b - a > 1) {
            int m = a + (b - a) / 2;
            function(a, m, nums, temp);
            function(m, b, nums, temp);
            int i = a;
            int j = m;
            int count = i;
            while (i < m && j < b) {
                if (temp[i] < temp[j])
                    nums[count++] = temp[i++];
                else
                    nums[count++] = temp[j++];
            }
            while (i < m) nums[count++] = temp[i++];
            while (j < b) nums[count++] = temp[j++];
            for (int k = a; k < b; k++) temp[k] = nums[k];
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
    std::vector<int> nums = {5, 1, 1, 2, 0, 0};
    // std::vector<int>& nums2 = nums;  //
    // nums2和nums是同个东西。引用实现了指针的功能
    std::vector<int> ans;
    Solution solution;
    solution.sortArray(nums);
    for (int i = 0; i < nums.size(); i++) {
        std::cout << nums[i];
    }
    return 0;
}