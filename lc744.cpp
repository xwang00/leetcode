/*https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/
744. Find Smallest Letter Greater Than Target

Example 1:

Input: letters = ["c","f","j"], target = "a"
Output: "c"
Explanation: The smallest character that is lexicographically greater than 'a' in letters is 'c'.
Example 2:

Input: letters = ["c","f","j"], target = "c"
Output: "f"
Explanation: The smallest character that is lexicographically greater than 'c' in letters is 'f'.
Example 3:

Input: letters = ["x","x","y","y"], target = "z"
Output: "x"
Explanation: There are no characters in letters that is lexicographically greater than 'z' so we return letters[0].
*/

#include <iostream>
#include <vector>

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int m = 0, n = letters.size(), i = 0, result = 0;
        while(m<n){
            i = m+(n-m)/2;
            if (letters[i]>target) {result = i;n=i;}
            else if (letters[i]<=target) m=i+1;
        }
        return letters[result];
    }
};