#include <iostream>
#include <vector>

class Solution {
   public:
    int binary_search(long long q, int a, int b, std::vector<int>& nums) {
        int m = a + (b - a) / 2;
        if (b - a > 1) {
            if (nums[m - 1] <= q && nums[m] > q)
                return m;
            else if (nums[m] > q)
                return binary_search(q, a, m, nums);
            else if (nums[m] <= q)
                return binary_search(q, m + 1, b, nums);
        }
        if (a == b || nums[a] <= q)
            return b;
        else
            return a;
    }
    int comp_num(int a, int m, int b, std::vector<int>& nums,
                 std::vector<int>& temp) {
        int res = 0, p = a, q = m, i = a;
        while (p < m && q < b) {
            if (nums[p] >= nums[q]) {
                int j = binary_search((long long)nums[q] * 2, a, m, nums);
                std::cout << q << '\t' << j << '\n';
                res += m - j;
                // for (int j = a; j < m; j++) {
                //     if (nums[j] > 2 * (long long)nums[q]) {
                //         res += m-j;
                //         break;
                //          //std::cout << a << '\t'<< p << '\t'<< q <<
                //          '\t'<< b
                //          << '\t'<< j << '\n';
                //         //<< '\t'<< nums[q] << '\n';
                //     }
                // }
                temp[i++] = nums[q++];
            } else
                temp[i++] = nums[p++];
        }
        while (q < b) {
            int j = binary_search((long long)2 * nums[q], a, m, nums);
            std::cout << q << '\t' << j << '\n';
            res += m - j;
            // for (int j = a; j < m; j++) {
            //     if (nums[j] > 2 * (long long)nums[q]) {
            //         res += m-j;
            //         break;
            //              //std::cout << a << '\t'<< p << '\t'<< q << '\t'<< b
            //              << '\t'<< j << '\n';
            //         // <<'\t'<< nums[q] << '\n';
            //     }
            // }
            temp[i++] = nums[q++];
        }
        while (p < m) {
            temp[i++] = nums[p++];
        }

        for (int i = a; i < b; i++) nums[i] = temp[i];
        std::cout << '\n';
        return res;
    }

    void function(int a, int b, std::vector<int>& nums, std::vector<int>& temp,
                  int* res) {
        if (b - a <= 1) return;
        int m = a + (b - a) / 2;
        function(a, m, nums, temp, res);
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
//                     // std::cout << res << " is " << nums[i] << " and "
//                     << nums[j] << " then \n";
//                 }
//             }
//         }
//         return res;
//     }
// };

int main() {
    std::vector<int> nums = {500, 201, 100, 47, 23, 11, 5, 4, 3, 2, 1};
    Solution solution;
    long long n = solution.reversePairs(nums);
    std::cout << n;
    return 0;
}