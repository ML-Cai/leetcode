#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <stack>
#include <unordered_map>
// Runtime: 8 ms, faster than 98.50% of C++ online submissions for Simplify Path.
// Memory Usage: 8.8 MB, less than 41.55% of C++ online submissions for Simplify Path.
class Solution {
public:
    std::string simplifyPath(std::string path) {
        size_t ret_size = 0;
        std::string ret;
        std::stack<std::pair<size_t, size_t> > slot_list;

        auto iter = path.cbegin();
        while (iter != path.cend()) {
            // get next slot
            auto iter_op = iter;
            char cur_c;
            while ((cur_c = *iter) != '/' && iter != path.end()) {
                iter++;
            }

            int slot_size = iter - iter_op;
            bool skip = false;
            switch (slot_size) {
            case 0:
                skip = true;
                break;
            case 1:
                if (*iter_op == '.') {
                    skip = true;
                }
                break;
            case 2:
                if (*iter_op == '.' && *(iter_op+1) == '.') {
                    if (slot_list.size() > 0) slot_list.pop();
                    skip = true;
                }
                break;
            default:
                break;
            }

            if (!skip) {
                slot_list.emplace(std::pair<size_t, size_t>(iter_op - path.cbegin(), iter - iter_op));
            }

            if (cur_c == '/') iter++;
        }

        if (slot_list.size() == 0) {
            return "/";
        } else {
            while (slot_list.size() > 0) {
                // const std::pair<size_t, size_t> & p = slot_list[i];
                const std::pair<size_t, size_t> & p = slot_list.top();
                ret = "/" + path.substr(p.first, p.second) + ret;
                slot_list.pop();
            }
            return ret;
        }
    }
};

int main()
{
    Solution ss;
    printf("[%s]\n", ss.simplifyPath("/home/").c_str());
    printf("[%s]\n", ss.simplifyPath("/../").c_str());
    printf("[%s]\n", ss.simplifyPath("/home//foo/").c_str());
    printf("[%s]\n", ss.simplifyPath("/a/./b/../../c/").c_str());
    printf("[%s]\n", ss.simplifyPath("/a/../../b/../c//.//").c_str());
    printf("[%s]\n", ss.simplifyPath("/a/\/b/\/\/\/c/d/\/././\/..").c_str());
    return 0;
}