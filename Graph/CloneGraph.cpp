/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    if(node == NULL) return node;
    unordered_map<UndirectedGraphNode*,UndirectedGraphNode*>sta;
    queue<UndirectedGraphNode* >q;
    q.push(node);
    while(!q.empty())
    {
        auto x = q.front();
        q.pop();
        if(sta.count(x) == 0){
            sta.insert(make_pair(x,new UndirectedGraphNode(x->label)));
            for(int i = 0;i<x->neighbors.size();i++)
            {
                if(sta.count(x->neighbors[i]) == 0)
                {
                    q.push(x->neighbors[i]);
                }
            }
        }
    }
    for(auto x : sta)
    {
        for(int i = 0;i<x.first->neighbors.size();i++)
        {
            x.second->neighbors.push_back(sta[x.first->neighbors[i]]);
        }
    }
    return sta[node];
}
