#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <string.h>
#include <unordered_map>
class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        /*
            00000001
                  11
        
            1111111
                  1
        
           ascii 0 :48 0b110000
           ascii 1 :49 0b110001
        */
        //
        
        // remove head zero.
        std::string ret;
        std::string *p0;
        std::string *p1;
        if (a.size() < b.size()) {
            p0 = &b;
            p1 = &a;
        } else {
            p0 = &a;
            p1 = &b;
        }
        
        auto iter0 = p0->rbegin();
        auto iter1 = p1->rbegin();
        uint32_t vC = 0;
        while (iter0 != p0->rend()) {
            uint8_t v0 = 0, v1 = 0;
            
            if (iter0 != p0->rend()) {
                v0 = (*iter0 & 0x01);
                iter0++;
            }
            
            if (iter1 != p1->rend()) {
                v1 = (*iter1 & 0x01);
                iter1++;
            }

            vC = vC + v0 + v1;
            if (vC & 0x01) {
                ret = '1' +ret;
            } else {
                ret = '0' +ret;
            }
            // printf("%d %d %d\n", v0, v1, vC);
            vC = vC >> 1;
            // printf("%d %d %d\n", v0, v1, vC);
        }
        
        if (vC)
            ret ="1" + ret;
        else if (ret.size() == 0)
            ret ="0";
        
        return ret;
    }
};

int main()
{
    Solution ss;
    printf("%s\n ", ss.addBinary("1010",
                                 "1011").c_str());
// "1010"
// "1011"
    // "1111101110010100110101101001001100011101111000101010 101011111011100111100101100111"
    // "1111101110010100110101101001001100011101111000101010 0101011111011100111100101100111"
        // 1111101110010100110101101001001100011101111000101010101011111011100111100101100111
    return 0;
}