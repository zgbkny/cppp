#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
class Solution {
public:
    int candy(vector<int> &ratings) {
        map<int, int> candys; 
        map<int, int>::iterator it;
        int i = 0, sum = 0;
        for (; i < ratings.size(); i++) 
            if (i > 0 && ratings[i] > ratings[i - 1]) 
                candys[i] = candys[i - 1] + 1;
        for (i = ratings.size() - 1; i >= 0; i--) 
            if (i < ratings.size() - 1 && ratings[i] > ratings[i + 1]) 
                candys[i] = candys[i + 1] + 1 > candys[i] ? candys[i + 1] + 1 : candys[i];
        for (it = candys.begin(); it != candys.end(); it++)
            sum += it->second;
        return sum + ratings.size();
    }
    int candy2(vector<int> &ratings) {
        int candys[ratings.size()] = {0};
        int i = 0, sum = 0;
        for (; i < ratings.size(); i++) {
            candys[i] = 0;
            if (i > 0 && ratings[i] > ratings[i - 1]) 
                candys[i] = candys[i - 1] + 1;
        }
        for (i = ratings.size() - 1; i >= 0; i--) 
            if (i < ratings.size() - 1 && ratings[i] > ratings[i + 1]) 
                candys[i] = candys[i + 1] + 1 > candys[i] ? candys[i + 1] + 1 : candys[i];
        for (i = 0; i < ratings.size(); i++) 
            sum += candys[i];
        return sum + ratings.size();
    }
};

int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    Solution s;
	//int i = 5 >? 4;
    std::cout << "Solution:" << s.candy2(v) << std::endl;
    return 0;
}