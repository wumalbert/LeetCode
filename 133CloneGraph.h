/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (NULL == node) return NULL;
        queue<UndirectedGraphNode*> node_queue;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> node_map;
        node_queue.push(node);
        node_map[node] = new UndirectedGraphNode(node->label);
        while (!node_queue.empty()) {
            UndirectedGraphNode *current = node_queue.front(), *cloned = node_map[current];
            node_queue.pop();
            for (int i = 0; i < current->neighbors.size(); ++i) {
                if (node_map.find(current->neighbors[i]) == node_map.end()) {
                    node_map[current->neighbors[i]] = new UndirectedGraphNode(current->neighbors[i]->label);
                    cloned->neighbors.push_back(node_map[current->neighbors[i]]);
                    node_queue.push(current->neighbors[i]);
                } else {
                    cloned->neighbors.push_back(node_map[current->neighbors[i]]);
                }
            }
        }
        return node_map[node];
    }
};
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (NULL == node) return NULL;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> graph_map;
        clone(node, graph_map);
        return graph_map[node];
    }
private:
    UndirectedGraphNode *clone(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> &graph_map) {
        if (graph_map.find(node) != graph_map.end()) return graph_map[node];
        UndirectedGraphNode *cloned = new UndirectedGraphNode(node->label);
        graph_map[node] = cloned;
        cloned->neighbors.resize(node->neighbors.size());
        for (int i = 0; i != node->neighbors.size(); ++i) {
            cloned->neighbors[i] = clone(node->neighbors[i], graph_map);
        }
        return cloned;
    }
};