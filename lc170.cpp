#include <iostream>
#include <vector>

class Solution {
   public:
    int comp_num(int a, int m, int b, std::vector<int>& nums,
                 std::vector<int>& temp) {
        int res = 0, p = a, q = m, i = a;
        while (p < m && q < b) {
            if (nums[p] >= nums[q]) {
                for (int j = p; j < m; j++) {
                    if (nums[j] > 2 * (long long)nums[q]) {
                        res ++;
                        std::cout << p << m << q << b << '\t' << nums[j] << '\t'<< nums[q] << '\n';
                    }
                }
                temp[i++] = nums[q++];
            } else
                temp[i++] = nums[p++];
        }
        while (q < b) temp[i++] = nums[q++];
        while (p < m) {
            // for (int j = m; j < b; j++) {
            //     if (p < m - 1 && nums[p] > 2 * nums[j]) {
            //         res++;
            //         std::cout << p << '\t' << nums[p] << '\t' << nums[j] << 'n';
            //     }
            // }
            temp[i++] = nums[p++];
        }

        // for (int i = a; i < b; i++) {
        //     if (p < m && q < b && nums[p] > nums[q]) {
        //         temp[i] = nums[q];
        //         if (nums[p] > 2 * nums[q]) res += m - p;
        //         q++;
        //     } else if (p >= m) {
        //         temp[i] = nums[q];
        //         q++;
        //     } else {
        //         temp[i] = nums[p];
        //         p++;
        //     }
        // }
        for (int i = a; i < b; i++) nums[i] = temp[i];
        // std::cout << res << '\n';
        return res;
    }

    void function(int a, int b, std::vector<int>& nums, std::vector<int>& temp,
                  int* res) {
        if (b - a <= 1) return;
        int m = a + (b - a) / 2;
        // if (a < m - 1) function(a, m, nums, temp, res);
        function(a, m, nums, temp, res);
        // if (m < b - 1) function(m, b, nums, temp, res);
        function(m, b, nums, temp, res);
        int t = comp_num(a, m, b, nums, temp);
        *res += t;
    }

    int reversePairs(std::vector<int>& nums) {
        int result = 0;
        int* res = &result;
        std::vector<int> temp = nums;
        function(0, nums.size(), nums, temp, res);
        return result;
    }
};

// class Solution {
// public:
//     long long reversePairs(std::vector<int>& nums) {
//         long long res = 0;
//         for (int i=0; i<nums.size();i++){
//             for (int j=i+1; j<nums.size();j++){
//                 //long long temp = (long long)nums[i] - nums[j];
//                 //强制类型转换只用转换一个，另一个在计算时longlong -
//                 int会自动转换成long long
//                 // float int实数型 整数型，就不会自动转换
//                 if ((long long)nums[i] - nums[j] > nums[j]){
//                     res ++;
//                     // std::cout << res << " is " << nums[i] << " and " <<
//                     nums[j] << " then \n";
//                 }
//             }
//         }
//         return res;
//     }
// };

int main() {
    std::vector<int> nums = {5,4,3,2,1};
    Solution solution;
    long long n = solution.reversePairs(nums);
    std::cout << n;
    return 0;
}