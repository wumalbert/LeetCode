/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution02 {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode *head = new ListNode(0), *tail = head;
        while (true) {
            int min_val = numeric_limits<int>::max();
            int min_index = 0;
            ListNode *min_node = NULL;
            for (int i = 0; i < lists.size(); ++i) {
                if (lists[i] && lists[i]->val < min_val) {
                    min_val = lists[i]->val;
                    min_node = lists[i];
                    min_index = i;
                }
            }
            if (!min_node) break;
            tail->next = min_node;
            tail = tail->next;
            lists[min_index] = lists[min_index]->next;
        }
        tail = head;
        head = head->next;
        delete tail;
        return head;
    }
};
// use set as a minimize heap
class Solution01 {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        set<pair<int, ListNode*> > heap;
        for (int i = 0; i < lists.size(); ++i)
            if (lists[i]) heap.insert(make_pair(lists[i]->val, lists[i]));
        ListNode *head = NULL, **tail = &head;
        while(!heap.empty()) {
            ListNode *node = heap.begin()->second;
            *tail = node;
            heap.erase(heap.begin());
            tail = &((*tail)->next);
            if (node->next) heap.insert(make_pair(node->next->val, node->next));
        }
        *tail = NULL;
        return head;
    }
};
// use priority_queue
struct MyComp {
    bool operator() (ListNode *x, ListNode *y) {
        return x->val > y->val;
    }
};
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        priority_queue<ListNode*, vector<ListNode*>, MyComp> node_priority_queue;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i]) node_priority_queue.push(lists[i]);
        }
        ListNode *head = NULL, **tail = &head;
        while (!node_priority_queue.empty()) {
            ListNode *node = node_priority_queue.top();
            node_priority_queue.pop();
            *tail = node;
            tail = &((*tail)->next);
            if (node->next) node_priority_queue.push(node->next);
        }
        *tail = NULL;
        return head;
    }
};