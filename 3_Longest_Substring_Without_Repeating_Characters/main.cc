#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <unordered_map>

// Runtime: 8 ms, faster than 98.92% of C++ online submissions for Longest Substring Without Repeating Characters.
// Memory Usage: 6.8 MB, less than 98.88% of C++ online submissions for Longest Substring Without Repeating Characters.
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        if (s.size() == 0) return 0;
        if (s.size() == 1) return 1;

        int max_counter = -1;
        int counter = 0;
        size_t first_index[256] = {0};      // keep the index when char first touch.
        size_t valid_left = 0;

        for (size_t i = 0 ; i < s.size() ; i++) {
            int c = static_cast<int>(s[i]);

            if (first_index[c] != 0 && valid_left < first_index[c]) {
                valid_left = first_index[c];

                // max_counter check A
                if (max_counter < counter) {
                    max_counter = counter;
                }
            }

            /** in default, maybe we will want check counter here, but for performance tuning, 
              * we can move the max_counter check at "max_counter check A" and "max_counter check B"
              * to get same result and better performance, 12ms---> 8ms
            */
            // if (max_counter < counter) {
            //     max_counter = counter;
            // }

            counter = (i - valid_left) +1;

            first_index[c] = i +1;
        }

        // max_counter check B
        if (max_counter < counter) {
            max_counter = counter;
        }

        return max_counter;
    }
};

int main()
{
    Solution ss;

    printf("%d\n", ss.lengthOfLongestSubstring("au"));
    printf("%d\n", ss.lengthOfLongestSubstring("abcabcbb"));
    printf("%d\n", ss.lengthOfLongestSubstring("bbbbb"));
    printf("%d\n", ss.lengthOfLongestSubstring("pwwkew"));
    printf("%d\n", ss.lengthOfLongestSubstring(""));
    printf("%d\n", ss.lengthOfLongestSubstring("dvdf"));
    printf("%d\n", ss.lengthOfLongestSubstring("abba"));

    return 0;
}