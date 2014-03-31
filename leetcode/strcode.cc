#include <iostream>
#include <map>

using std::map;
using std::cout;
using std::endl;
class Solution {
public:
    bool isNumber(const char *s) {
        bool ret = false, flag = true, ef = false;
        char *start = s;
        while (*start == ' ' && *start != 0) {
            start++;
        }
        if (*start == 0) return ret;
        while (*start != 0 && flag) {
            if (*start >= '0' && *start <= '9') start++;
            if (*start == ' ') ;
            if (*start == 'e') ef = true;

        }

    }
};

int main()
{
    Solution s;
    s.findMedianSortedArrays(NULL, 0, NULL, 2);
	//int i = 5 >? 4;
    std::cout << "Solution" << std::endl;
    return 0;
}