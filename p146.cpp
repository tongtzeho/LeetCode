struct LinkListNode {
    LinkListNode *prev, *next;
    int key, val;
};

class LRUCache {
public:

    unordered_map<int, LinkListNode*> dict;
    unordered_map<int, LinkListNode*>::iterator dict_iter;
    LinkListNode *head, *tail;
    int capacity;
    int size;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = tail = NULL;
        size = 0;
    }
    
    int get(int key) {
        dict_iter = dict.find(key);
        if (dict_iter == dict.end()) return -1;
        LinkListNode *node = dict_iter->second;
        if (head == node) return node->val;
        if (tail == node) tail = node->prev;
        else node->next->prev = node->prev;
        node->prev->next = node->next;
        node->prev = NULL;
        node->next = head;
        head->prev = node;
        head = node;
        return node->val;
    }
    
    void put(int key, int value) {
        dict_iter = dict.find(key);
        if (dict_iter == dict.end())
        {
            if (size == capacity)
            {
                LinkListNode *rmnode = tail;
                dict.erase(rmnode->key);
                if (size == 1)
                {
                    head = tail = NULL;
                    //delete rmnode;
                }
                else
                {
                    rmnode->prev->next = NULL;
                    tail = rmnode->prev;
                    //delete rmnode;
                }
                size--;
            }
            LinkListNode *node = new LinkListNode;
            node->key = key;
            node->val = value;
            node->prev = NULL;
            if (head == NULL)
            {
                node->next = NULL;
                head = node;
                tail = node;
            }
            else
            {
                node->next = head;
                head->prev = node;
                head = node;
            }
            size++;
            dict.insert(pair<int, LinkListNode*>(key, node));
            return;
        }
        else
        {
            LinkListNode *node = dict_iter->second;
            node->key = key;
            node->val = value;
            if (head == node) return;
            if (tail == node) tail = node->prev;
            else node->next->prev = node->prev;
            node->prev->next = node->next;
            node->prev = NULL;
            node->next = head;
            head->prev = node;
            head = node;
            return;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */