#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
#include <unordered_map>
#include <unordered_set>

// Runtime: 48 ms, faster than 99.53% of C++ online submissions for Group Anagrams.
// Memory Usage: 18.5 MB, less than 90.97% of C++ online submissions for Group Anagrams.

class Solution {
public:

    uint64_t getIndex(const std::string &ss) const {
        static int primes[26] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101 };
        uint64_t count_idx = 1;
        auto iter = ss.cbegin();

        while (iter != ss.cend()) {
            const int idx = static_cast<int>(*iter) - 'a';
            count_idx *= primes[idx];
            iter++;
        }

        return count_idx;
    }

    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::vector<std::vector<std::string> > ret;
        std::unordered_map<uint64_t, size_t> map_data;

        auto iter = strs.begin();
        while (iter != strs.end()) {
            uint64_t page_index = getIndex(*iter);

            auto iter_map = map_data.find(page_index);
            if (iter_map == map_data.end()) {
                // add new one
                std::vector<std::string> tmp;
                tmp.emplace_back(*iter);
                ret.emplace_back(tmp);
                map_data.emplace(page_index, ret.size() - 1);
            } else {
                // get result list an add anagrams
                ret[iter_map->second].emplace_back(*iter);
            }

            iter++;
        }

        return ret;
    }
};
// class DataPage {
//  public:
//     DataPage() {
//         count_idx = 0;
//     }

//     explicit DataPage(const std::string &ss) {
//         num_data.resize(26);    // a ~ z
//         std::fill(num_data.begin(), num_data.end(), 0);

//         auto iter = ss.cbegin();
//         count_idx = 1;
//         while (iter != ss.cend()) {
//             const int idx = static_cast<int>(*iter) - 'a';
//             count_idx += idx;
//             num_data[idx]++;
//             iter++;
//         }
//     }

//     bool compare(const DataPage &target) const {
//         if (target.count_idx != this->count_idx) return false;

//         for (size_t i = 0 ; i < num_data.size() ; i++) {
//             if (target.num_data[i] != this->num_data[i]) return false;
//         }
//         return true;
//     }

//     uint64_t count_idx;
//     std::vector<int> num_data;
//     size_t result_idx;
// };

// class Solution {
// public:
//     std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
//         std::vector<std::vector<std::string> > ret;
//         std::unordered_map<uint64_t, std::vector<DataPage> > map_data;

//         auto iter = strs.begin();
//         while (iter != strs.end()) {
//             DataPage page(*iter);

//             auto iter_map = map_data.find(page.count_idx);
//             if (iter_map == map_data.end()) {
//                 // add new one
//                 std::vector<std::string> tmp;
//                 tmp.emplace_back(*iter);
//                 ret.emplace_back(tmp);

//                 std::vector<DataPage> page_list;
//                 page.result_idx = ret.size() -1;
//                 page_list.emplace_back(page);
//                 map_data.emplace(page.count_idx, page_list);
//             } else {
//                 std::vector<DataPage> &page_list = iter_map->second;

//                 bool duplicated = false;
//                 size_t di;
//                 for (di = 0 ; !duplicated && di < page_list.size(); di++) {
//                     duplicated = page_list[di].compare(page);
//                 }

//                 if (!duplicated) {

//                     // add new one
//                     std::vector<std::string> tmp;
//                     tmp.emplace_back(*iter);
//                     ret.emplace_back(tmp);

//                     page.result_idx = ret.size() -1;
//                     page_list.emplace_back(page);   // add apge which count idx has same value, but map doesn't matched with list.
//                 } else {
//                     // get result list an add anagrams
//                     const int ret_idx = page_list[di -1].result_idx;
//                     ret[ret_idx].emplace_back(*iter);
//                 }
//             }

//             iter++;
//         }

//         return ret;
//     }
// };

int main()
{
    std::vector<std::string> data;
    // data.emplace_back("a");
    data.emplace_back("eat");
    data.emplace_back("tea");
    data.emplace_back("tan");
    data.emplace_back("ate");
    data.emplace_back("nat");
    data.emplace_back("bat");

    Solution ss;
    std::vector<std::vector<std::string>> ret = ss.groupAnagrams(data);


    for (size_t i = 0; i < ret.size(); i++) {
        for (size_t vi = 0 ; vi < ret[i].size(); vi++) {
            printf(">%s< ", ret[i][vi].c_str());
        }
        printf("\n");
    }
 
    return 0;
}