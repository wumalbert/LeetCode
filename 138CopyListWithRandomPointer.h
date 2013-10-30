/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        unordered_map<RandomListNode*, RandomListNode*> node_map;
        for (RandomListNode *node = head; node != NULL; node = node->next) {
            node_map[node] = new RandomListNode(node->label);
        }
        node_map[NULL] = NULL;
        for (RandomListNode *node = head; node != NULL; node = node->next) {
            node_map[node]->next = node_map[node->next];
            node_map[node]->random = node_map[node->random];
        }
        return node_map[head];
    }
};
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        unordered_map<RandomListNode*, RandomListNode*> node_map;
        node_map[NULL] = NULL;
        for (RandomListNode *node = head; node != NULL; node = node->next) {
            if (node_map.find(node) == node_map.end()) 
                node_map[node] = new RandomListNode(node->label);
            if (node->next && node_map.find(node->next) == node_map.end()) 
                node_map[node->next] = new RandomListNode(node->next->label);
            if (node->random && node_map.find(node->random) == node_map.end()) 
                node_map[node->random] = new RandomListNode(node->random->label);
            RandomListNode *copy = node_map[node];
            copy->next = node_map[node->next];
            copy->random = node_map[node->random];
        }
        return node_map[head];
    }
};
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!head) return head;
        for (RandomListNode *node = head; node != NULL; node = node->next->next) {
            RandomListNode *copy = new RandomListNode(node->label);
            copy->next = node->next;
            node->next = copy;
        }
        for (RandomListNode *node = head; node != NULL; node = node->next->next) {
            if (node->random) node->next->random = node->random->next;
        }
        RandomListNode *dummy = new RandomListNode(0), *tail = dummy;
        for (RandomListNode *node = head; node != NULL; node = node->next) {
            tail->next = node->next;
            node->next = node->next->next;
            tail = tail->next;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};