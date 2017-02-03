struct Node {
    int cnt;
    unordered_set<string> str;
    Node *prev, *next;
};

class AllOne {
public:
    /** Initialize your data structure here. */
    
    unordered_map<string, Node*> dict;
    unordered_map<string, Node*>::iterator iter;
    Node *head, *tail;
    
    AllOne() {
        head = tail = NULL;
    }
    
    /** Inserts a new key <Key> with cntue 1. Or increments an existing key by 1. */
    void inc(string key) {
        iter = dict.find(key);
        if (iter == dict.end())
        {
            if (head == NULL)
            {
                head = new Node;
                head->cnt = 1;
                head->prev = head->next = NULL;
                tail = head;
            }
            else if (head->cnt > 1)
            {
                head->prev = new Node;
                head->prev->next = head;
                head = head->prev;
                head->prev = NULL;
                head->cnt = 1;
            }
            head->str.insert(key);
            dict.insert(pair<string, Node*>(key, head));
        }
        else
        {
            Node *cur = iter->second;
            cur->str.erase(key);
            if (cur->next != NULL && cur->next->cnt == cur->cnt+1)
            {
                cur->next->str.insert(key);
                dict[key] = cur->next;
            }
            else
            {
                Node *ins = new Node;
                ins->next = cur->next;
                ins->prev = cur;
                if (cur->next != NULL) cur->next->prev = ins;
                cur->next = ins;
                ins->cnt = cur->cnt+1;
                ins->str.insert(key);
                if (cur == tail) tail = ins;
                dict[key] = ins;
            }
            if (cur->str.empty())
            {
                cur->next->prev = cur->prev;
                if (cur->prev != NULL) cur->prev->next = cur->next;
                if (head == cur) head = cur->next;
                cur->prev = cur->next = NULL;
                delete cur;
            }
        }
    }
    
    /** Decrements an existing key by 1. If Key's cntue is 1, remove it from the data structure. */
    void dec(string key) {
        iter = dict.find(key);
        if (iter != dict.end())
        {
            Node *cur = iter->second;
            cur->str.erase(key);
            if (cur->cnt != 1)
            {
                if (cur->prev != NULL && cur->cnt == cur->prev->cnt+1)
                {
                    cur->prev->str.insert(key);
                    dict[key] = cur->prev;
                }
                else
                {
                    Node *ins = new Node;
                    ins->next = cur;
                    ins->prev = cur->prev;
                    if (cur->prev != NULL) cur->prev->next = ins;
                    cur->prev = ins;
                    ins->cnt = cur->cnt-1;
                    ins->str.insert(key);
                    if (cur == head) head = ins;
                    dict[key] = ins;
                }
            }
            else
            {
                dict.erase(key);
            }
            if (cur->str.empty())
            {
                if (cur->next != NULL) cur->next->prev = cur->prev;
                if (cur->prev != NULL) cur->prev->next = cur->next;
                if (head == cur) head = cur->next;
                if (tail == cur) tail = cur->prev;
                cur->prev = cur->next = NULL;
                delete cur;
            }
        }
    }
    
    /** Returns one of the keys with maximal cntue. */
    string getMaxKey() {
        if (tail != NULL) return *(tail->str.begin());
        return "";
    }
    
    /** Returns one of the keys with Minimal cntue. */
    string getMinKey() {
        if (head != NULL) return *(head->str.begin());
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */