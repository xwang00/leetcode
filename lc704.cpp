#include <iostream>
#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int result = -1, m = 0, n = nums.size(),i;
        while(m<n)
        {
            i = (m+n)/2;
            if (nums[i] == target) {result = i; break;}
            else if (m +1 ==n) break;
            else if (nums[i]<target) m = i;
            else if (nums[i]>target) n = i;
        }
        return result;
    }
};

int main()
{
    std::vector<int> nums = {9};
    int target = 9;
    Solution solution;
    int n = solution.search(nums, target);
    std::cout << n;
    return 0;
}
