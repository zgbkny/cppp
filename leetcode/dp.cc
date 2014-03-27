#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::string;
class Solution {
public:
	void reverseWords(string &s) {

	}
	int maxPoints(vector<Point> &points) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int size = points.size();
        int ans = 0, horz, same;
        map<double, int> mp;
        map<double, int>::iterator it;
        for (int i = 0; i < size; i++) {
            mp.clear(); horz = same = 0;
            for (int j = 0; j < points.size(); j++) {
                if (points[j].x == points[i].x && points[j].y == points[i].y) same++;
                else if (points[j].x == points[i].x) horz ++;
                else mp[(points[j].y-points[i].y)*1.0/(points[j].x-points[i].x)]++;
            }
            if (horz + same > ans) ans = horz + same;
            for (it = mp.begin(); it != mp.end(); it++)
                if (it->second + same > ans) ans = it->second + same;
        }
        return ans;
    }
	bool wordBreak(string s, unordered_set<string> &dict) {
		// 长度为 n 的字符串有 n+1 个隔板
		vector<bool> f(s.size() + 1, false);
		f[0] = true; // 空字符串
		for (int i = 1; i <= s.size(); ++i) {
			for (int j = i - 1; j >= 0; --j) {
				if (f[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
					f[i] = true;
					break;
				}
			}
		}
		return f[s.size()];
	}
};

int main()
{
	//int i = 5 >? 4;
    std::cout << "Solution" << std::endl;
    return 0;
}