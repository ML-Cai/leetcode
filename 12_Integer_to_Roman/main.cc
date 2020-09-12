#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <unordered_map>

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Integer to Roman.
// Memory Usage: 6.1 MB, less than 55.51% of C++ online submissions for Integer to Roman.
class Solution {
public:
    std::string intToRoman(int num) {
        std::string ret ="";
        int base = 1;
        while (num > 0) {
            int v = num % 10;

            ret = getRoman(v, base) + ret;

            base *= 10;
            num /= 10;
        }
        return ret;
    }

    std::string getRoman(const int v, const int base) const {
        switch (base) {
            case 1:
                return getRoman_base_1(v);
            case 10:
                return getRoman_base_10(v);
            case 100:
                return getRoman_base_100(v);
            case 1000:
                return getRoman_base_1000(v);
            default:
                return "?";
        }
    }

    std::string getRoman_base_1(const int v) const {
        switch (v) {
            case 1: return "I";
            case 2: return "II";
            case 3: return "III";
            case 4: return "IV";
            case 5: return "V";
            case 6: return "VI";
            case 7: return "VII";
            case 8: return "VIII";
            case 9: return "IX";
        }
        return "";
    }

    std::string getRoman_base_10(const int v) const {
        switch (v) {
            case 1: return "X";
            case 2: return "XX";
            case 3: return "XXX";
            case 4: return "XL";
            case 5: return "L";
            case 6: return "LX";
            case 7: return "LXX";
            case 8: return "LXXX";
            case 9: return "XC";
        }
        return "";
    }

    std::string getRoman_base_100(const int v) const {
        switch (v) {
            case 1: return "C";
            case 2: return "CC";
            case 3: return "CCC";
            case 4: return "CD";
            case 5: return "D";
            case 6: return "DC";
            case 7: return "DCC";
            case 8: return "DCCC";
            case 9: return "CM";
        }
        return "";
    }

    std::string getRoman_base_1000(const int v) const {
        switch (v) {
            case 1: return "M";
            case 2: return "MM";
            case 3: return "MMM";
        }
        return "";
    }

};

int main()
{
    Solution ss;
    // printf("%s\n", ss.intToRoman(1).c_str());
    // printf("%s\n", ss.intToRoman(3).c_str());
    // printf("%s\n", ss.intToRoman(4).c_str());
    // printf("%s\n", ss.intToRoman(9).c_str());
    // printf("%s\n", ss.intToRoman(12).c_str());
    // printf("%s\n", ss.intToRoman(14).c_str());
    // printf("%s\n", ss.intToRoman(18).c_str());
    // printf("%s\n", ss.intToRoman(58).c_str());
    // printf("%s\n", ss.intToRoman(1994).c_str());
    printf("%s\n", ss.intToRoman(10).c_str());
    printf("%s\n", ss.intToRoman(100).c_str());
    printf("%s\n", ss.intToRoman(1000).c_str());

    return 0;
}