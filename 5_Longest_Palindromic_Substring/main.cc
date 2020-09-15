#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <unordered_map>

// Runtime: 12 ms, faster than 94.02% of C++ online submissions for Longest Palindromic Substring.
// Memory Usage: 6.8 MB, less than 79.25% of C++ online submissions for Longest Palindromic Substring.
// or
// Runtime: 8 ms, faster than 97.93% of C++ online submissions for Longest Palindromic Substring.
// Memory Usage: 6.8 MB, less than 79.86% of C++ online submissions for Longest Palindromic Substring.

// class Solution {
// public:
//     std::string longestPalindrome(std::string s) {
//         int result_start = 0;
//         int result_length = 0;

//         if (s.size() == 0) {
//             return "";
//         }
//         if (s.size() == 1) {
//             return s.substr(0, 1);
//         }

//         for (int ref_A = 0 ; ref_A < (s.size() -1); ref_A++) {
//             const char vA = s[ref_A];


//             for (int ref_B = s.size()-1 ; ref_B >= ref_A; ref_B--) {
//                 if (vA != s[ref_B]) continue;

//                 int idx_A = ref_A;
//                 int idx_B = ref_B;
//                 bool valid = true;
//                 while (idx_A <= idx_B) {
//                     if (s[idx_A] != s[idx_B]) {
//                         valid = false;
//                         break;
//                     }
//                     idx_A++;
//                     idx_B--;
//                 }

//                 if (valid) {
//                     int new_length =  (ref_B - ref_A) +1;
//                     if (new_length > result_length) {
//                         result_length = new_length;
//                         result_start = ref_A;
//                     }
//                     break;
//                 }
//             }
//         }

//         return s.substr(result_start, result_length);
//     }
// };


class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int result_start = 0;
        int result_length = 0;

        if (s.size() == 0) {
            return "";
        }
        if (s.size() == 1) {
            return s.substr(0, 1);
        }

        int size_limit = (s.size() -1);
        for (int ref_i = 0 ; ref_i < size_limit; ref_i++) {
            int idx_A = ref_i;
            int idx_B = ref_i;

            while ((idx_B +1) <= size_limit && s[idx_B]== s[idx_B +1]) {
                idx_B++;
            }
            ref_i = idx_B;  // set as next pissible center

            while (idx_A >= 0 && idx_B <= size_limit) {
                if (s[idx_A] != s[idx_B]) {
                    break;
                }
                idx_A--;
                idx_B++;
            }


            idx_B--;
            idx_A++;
            int new_length =  (idx_B - idx_A) +1;
            if (new_length > result_length) {
                result_length = new_length;
                result_start = idx_A;
            }
            
        }

        return s.substr(result_start, result_length);
    }
};


int main()
{
    Solution ss;

    // printf("[%s]\n", ss.longestPalindrome("babad").c_str());
    printf("[%s]\n", ss.longestPalindrome("cbbd").c_str());
    printf("[%s]\n", ss.longestPalindrome("").c_str());
    printf("[%s]\n", ss.longestPalindrome("a").c_str());
    printf("[%s]\n", ss.longestPalindrome("ac").c_str());
    printf("[%s]\n", ss.longestPalindrome("aaabaaaa").c_str());
    printf("[%s]\n", ss.longestPalindrome("aaaabaaa").c_str());
    printf("[%s]\n", ss.longestPalindrome("aaaaaaaaaaaaaaaaaaaaabaaa").c_str());
    printf("[%s]\n", ss.longestPalindrome("aaaaaaaaaaaaaaaaaaaaabaaa").c_str());


    return 0;
}