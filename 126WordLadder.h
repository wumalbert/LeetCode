struct ArcNode
{
    int head;
    ArcNode *nextarc;
    
    ArcNode() : head(-1), nextarc(NULL) {}
    ArcNode(int h) : head(h), nextarc(NULL) {}
    ~ArcNode() { if (nextarc) delete nextarc; }
};
struct VexNode
{
    string info;
    ArcNode *firstarc;
    
    VexNode() : info(""), firstarc(NULL) {}
    ~VexNode() { if (firstarc) delete firstarc; }
};
struct ALGraph
{
    int nVertex;
    VexNode *vertexs;
    
    ALGraph() : nVertex(0), vertexs(NULL){}
    ~ALGraph() { if (vertexs) delete [] vertexs; }
};

class Solution01 {
private:
    void buildALGraph(const string &start, const string &end, const unordered_set<string> &dict, ALGraph& graph, map<string, int> &ids)
    {
        int count = 0;
        for (unordered_set<string>::const_iterator it = dict.begin(); it != dict.end(); ++it)
        {
            ids[*it] = count++;
        }
        if (dict.find(start) == dict.end()) ids[start] = count++;
        if (dict.find(end) == dict.end()) ids[end] = count++;
        
        graph.nVertex = count;
        graph.vertexs = new VexNode[count];
        
        for (map<string, int>::iterator it = ids.begin(); it != ids.end(); ++it)
        {
            graph.vertexs[it->second].info = it->first;
            
            int len = it->first.length();
            for (int i = 0; i < len; ++i)
            {
                for (int j = 0; j < 26; ++j)
                {
                    string s = it->first;
                    s[i] = 'a' + j;
                    if (s[i] == it->first[i]) continue;
                    map<string, int>::iterator t = ids.find(s);
                    if (t != ids.end())
                    {
                        ArcNode *arc = new ArcNode(t->second);
                        arc->nextarc = graph.vertexs[it->second].firstarc;
                        graph.vertexs[it->second].firstarc = arc;
                    }
                }
            }
        }
    }
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        //build a graph
        ALGraph graph;
        map<string, int> ids;
        
        buildALGraph(start, end, dict, graph, ids);
        
        int from = ids[start];
        int to = ids[end];
        
        vector<bool> visited(graph.nVertex, false);
        queue<int> visitQueue;
        
        visitQueue.push(from);
        visited[from] = true;
        int ret = 0;
        int level0 = 1, level1 = 0;
        while (!visitQueue.empty())
        {
            int current = visitQueue.front();
            visitQueue.pop();
            --level0;
            
            for (ArcNode *arc = graph.vertexs[current].firstarc; arc != NULL; arc = arc->nextarc)
            {
                if (arc->head == to)
                {
                    return ret + 2;
                }
                if (!visited[arc->head])
                {
                    visited[arc->head] = true;
                    visitQueue.push(arc->head);
                    ++level1;
                }
            }
            
            if (!level0)
            {
                ++ret;
                level0 = level1;
                level1 = 0;
            }
        }
        return 0;
    }
};

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        // BFS
        unordered_set<string> visited_set;
        queue<string> to_visit_queue;
        int number_level0 = 1, number_level1 = 0, level = 0;
        to_visit_queue.push(start);
        visited_set.insert(start);
        while (!to_visit_queue.empty()) {
            string word(to_visit_queue.front());
            to_visit_queue.pop();
            --number_level0;
            for (int i = 0; i < word.length(); ++i) {
                int k = word[i] - 'a';
                for (int j = 0; j < 26; ++j) {
                    if (j == k) continue;
                    word[i] = 'a' + j;
                    if (word == end) return level+2;
                    if (dict.find(word) != dict.end() && visited_set.find(word) == visited_set.end()) {
                        to_visit_queue.push(word);
                        visited_set.insert(word);
                        ++number_level1;
                    }
                }
                word[i] = 'a' + k;
            }
            if (0 == number_level0) {
                number_level0 = number_level1;
                number_level1 = 0;
                ++level;
            }
        }
        return 0;
    }
};