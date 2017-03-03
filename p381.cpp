class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    
    unordered_map<int, unordered_set<int>> dict;
    int v[10000];
    int size;
    
    RandomizedCollection() {
        dict.clear();
        size = 0;
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        if (dict.find(val) == dict.end())
        {
            dict.insert(pair<int, unordered_set<int>>(val, unordered_set<int>()));
            dict[val].insert(size);
            v[size++] = val;
            return true;
        }
        dict[val].insert(size);
        v[size++] = val;
        return false;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (dict.find(val) == dict.end())
        {
            return false;
        }
        if (v[size-1] == val)
        {
            dict[val].erase(size-1);
            size--;
        }
        else
        {
            int pos = *(dict[val].begin());
            dict[v[size-1]].erase(size-1);
            dict[v[size-1]].insert(pos);
            v[pos] = v[size-1];
            size--;
            dict[val].erase(pos);
        }
        if (dict[val].empty())
        {
            dict.erase(val);
        }
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return v[rand()%size];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
