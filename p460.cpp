struct Node1;
struct Node2;

struct Node1 {
    Node1 *prev, *next;
    Node2 *head, *tail;
    unsigned frequency;
};

struct Node2 {
    Node1 *parent;
    Node2 *prev, *next;
    int key;
};

struct CacheVal {
    Node2 *addr;
    int value;
};

class LFUCache {
public:

    unordered_map<int, CacheVal> cache;
    unordered_map<int, CacheVal>::iterator iter;
    Node1 *counter;
    unsigned size;
    unsigned capacity;

    LFUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        counter = NULL;
    }
    
    void update(Node2 *addr) {
        Node1 *par = addr->parent;
        if (addr->prev != NULL) {
            addr->prev->next = addr->next;
        }
        if (addr->next != NULL) {
            addr->next->prev = addr->prev;
        }
        if (par->tail == addr) {
            par->tail = addr->prev;
        }
        if (par->head == addr) {
            par->head = addr->next;
        }
        if (par->next != NULL && (par->next->frequency)-(par->frequency) == 1) {
            par->next->tail->next = addr;
            addr->next = NULL;
            addr->prev = par->next->tail;
            par->next->tail = addr;
            addr->parent = par->next;
        } else {
            Node1 *insertpar = new Node1;
            insertpar->frequency = par->frequency+1;
            insertpar->next = par->next;
            if (insertpar->next != NULL) insertpar->next->prev = insertpar;
            insertpar->prev = par;
            par->next = insertpar;
            insertpar->head = insertpar->tail = addr;
            addr->parent = insertpar;
            addr->prev = addr->next = NULL;
        }
        if (par->tail == NULL) {
            if (par->prev != NULL) {
                par->prev->next = par->next;
            }
            if (par->next != NULL) {
                par->next->prev = par->prev;
            }
            if (counter == par) {
                counter = par->next;
            }
            delete par;
        }
    }
    
    int get(int key) {
        iter = cache.find(key);
        if (iter == cache.end()) return -1;
        else {
            int retval = iter->second.value;
            update(iter->second.addr);
            return retval;
        }
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        iter = cache.find(key);
        if (iter != cache.end()) {
            iter->second.value = value;
            update(iter->second.addr);
            return;
        }
        if (size == capacity) {
            Node2 *rmnode = counter->head;
            counter->head = counter->head->next;
            if (counter->head != NULL) {
                counter->head->prev = NULL;
            } else {
                Node1 *rmpar = counter;
                counter = counter->next;
                if (counter != NULL) counter->prev = NULL;
                delete rmpar;
            }
            cache.erase(rmnode->key);
            delete rmnode;
        } else {
            size++;
        }
        Node2 *insertnode = new Node2;
        insertnode->key = key;
        if (counter != NULL && counter->frequency == 0) {
            counter->tail->next = insertnode;
            insertnode->prev = counter->tail;
            insertnode->next = NULL;
            insertnode->parent = counter;
            counter->tail = insertnode;
        } else {
            Node1 *head = new Node1;
            head->frequency = 0;
            head->prev = NULL;
            head->next = counter;
            if (counter != NULL) counter->prev = head;
            counter = head;
            head->head = head->tail = insertnode;
            insertnode->prev = insertnode->next = NULL;
            insertnode->parent = head;
        }
        CacheVal newval;
        newval.value = value;
        newval.addr = insertnode;
        cache.insert(pair<int, CacheVal>(key, newval));
    }
    
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */