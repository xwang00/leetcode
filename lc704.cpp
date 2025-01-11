#include <iostream>
#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int result = -1;
        for(int i = 0; i<nums.size(); i++)
        {
            if (nums[i] == target) result = i;
        }
        return result;
    }
};

int main()
{
    std::vector<int> nums = {-1,0,3,5,9,12};
    int target = 2;
    Solution solution;
    int n = solution.search(nums, target);
    std::cout << n;
    return 0;
}
