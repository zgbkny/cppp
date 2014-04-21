#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return head;
        map<RandomListNode *, RandomListNode *> mp;
        RandomListNode *node = head;
        while (node) {
            mp[node] = new RandomListNode(node->label);
            node = node->next;
        }
        node = head;
        while (node) {
            mp[node]->next = mp[node->next];
            mp[node]->random = mp[node->random];
            node = node->next;
        }
        return mp[head];
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        map<UndirectedGraphNode *, UndirectedGraphNode *> mp;
        UndirectedGraphNode *tmpNode = node;
        queue<UndirectedGraphNode *> q;
        if (tmpNode) {
            mp[tmpNode] = new UndirectedGraphNode(tmpNode->label);
            q.push(tmpNode);
            while (!q.empty()) {
                tmpNode = q.front();q.pop();
                for (int i = 0; i < tmpNode->neighbors.size(); i++) {
                    if (mp[tmpNode->neighbors[i]] == 0) {
                        mp[tmpNode->neighbors[i]] = new UndirectedGraphNode(tmpNode->neighbors[i]->label);
                        q.push(tmpNode->neighbors[i]);
                    }
                    mp[tmpNode]->neighbors.push_back(mp[tmpNode->neighbors[i]]);
                }
            }
        }
        return mp[node];
    }
};

int main()
{
    Solution s;
    RandomListNode *node = new RandomListNode(-1);
	//int i = 5 >? 4;
    cout << "test" << NULL << endl;
    std::cout << s.copyRandomList(node)->label << std::endl;
    return 0;
}