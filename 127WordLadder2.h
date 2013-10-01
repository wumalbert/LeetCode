#include <vector>
#include <string>
#include <unordered_set>
#include <map>
#include <queue>
using namespace std;

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
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> words;
        map<string, int> ids;
        int count = 0;
        for (unordered_set<string>::iterator it = dict.begin(); it != dict.end(); ++it)
        {
            words.push_back(*it);
            ids[*it] = count++;
        }
        if (ids.find(start) == ids.end())
        {
            words.push_back(start);
            ids[start] = count++;
        }
        if (ids.find(end) == ids.end())
        {
            words.push_back(end);
            ids[end] = count++;
        }
        vector<int> visitLevel(words.size(), -1);
        vector<vector<int> > previsited(words.size(), vector<int>());

        int level0 = 1, level1 = 0, level = 0;
        queue<int> visitQueue;
        int from = ids[start];
        visitQueue.push(from);
        visitLevel[from] = level++;
        while (!visitQueue.empty())
        {
            int current = visitQueue.front();
            visitQueue.pop();
            --level0;

            if (words[current] == end) break;
            int len = words[current].length();
            for (int i = 0; i < len; ++i)
            {
                for (int j = 0; j < 26; ++j)
                {
                    string s(words[current]);
                    s[i] = 'a' + j;
                    if (ids.find(s) != ids.end())
                    {
                        int t = ids[s];
                        if (-1 == visitLevel[t]) // have not been visited before
                        {
                            visitLevel[t] = level;
                            visitQueue.push(t);
                            previsited[t].push_back(current);
                            ++level1;
                        }
                        else if (visitLevel[t] == level) // have been visited
                        {
                            previsited[t].push_back(current);
                        }
                    }
                }
            }
            if (0 == level0) // traversal the next level
            {
                ++level;
                level0 = level1;
                level1 = 0;
            }
        }

        vector<vector<string> > ret;
        int t = ids[end];
        if (previsited[t].empty()) return ret;
        ret.push_back(vector<string>(1, words[t]));
        while(true)
        {
            for (int i = 0; i < ret.size(); ++i)
            {
                t = ids[ret[i][0]];

                if (previsited[t].empty()) return ret;

                for (int j = 1; j < previsited[t].size(); ++j)
                {
                    vector<string> path(ret[i]);
                    path.insert(path.begin(), words[previsited[t][j]]);
                    ret.insert(ret.begin()+i+1, path);
                }
                ret[i].insert(ret[i].begin(), words[previsited[t][0]]);

                i += previsited[t].size()-1;

            }
        }
    }
};

class Solution {
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
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        //build a graph
        ALGraph graph;
        map<string, int> ids;

        buildALGraph(start, end, dict, graph, ids);

        int from = ids[start];
        int to = ids[end];

        vector<vector<vector<int> > > visitPath(graph.nVertex, vector<vector<int> >());
        vector<int> visited(graph.nVertex, -1);
        queue<int> visitQueue;

        int level0 = 1, level1 = 0, level = 0;
        visitQueue.push(from);
        visited[from] = level++;
        visitPath[from].push_back(vector<int>(1, from));
        //visitPath[from] = vector<vector<int> >(1, vector<int>(1, from));
        while (!visitQueue.empty())
        {
            int current = visitQueue.front();
            visitQueue.pop();
            --level0;

            if (current == to) break;

            for (ArcNode *arc = graph.vertexs[current].firstarc; arc != NULL; arc = arc->nextarc)
            {
                if (-1 == visited[arc->head])
                {
                    visited[arc->head] = level;
                    visitQueue.push(arc->head);
                    ++level1;

                    visitPath[arc->head] = visitPath[current];
                    for (vector<vector<int> >::iterator it = visitPath[arc->head].begin(); it != visitPath[arc->head].end(); ++it)
                        it->push_back(arc->head);
                }
                else if (level == visited[arc->head])
                {
                    vector<vector<int> > v = visitPath[current];
                    for (vector<vector<int> >::iterator it = v.begin(); it != v.end(); ++it)
                    {
                        it->push_back(arc->head);
                        visitPath[arc->head].push_back(*it);
                    }
                }
            }

            if (!level0)
            {
                ++level;
                level0 = level1;
                level1 = 0;
            }
        }

        vector<vector<string> > ret;
        if (visitPath[to].empty()) return ret;
        for (vector<vector<int>>::iterator i = visitPath[to].begin(); i != visitPath[to].end(); ++i)
        {
            vector<string> path;
            for (vector<int>::iterator j = i->begin(); j != i->end(); ++j)
                path.push_back(graph.vertexs[*j].info);
            ret.push_back(path);
        }
        return ret;
    }
};