class RandomizedSet {
public:

    unordered_map<int, int> dict;
    int v[10000];
    int size;

    /** Initialize your data structure here. */
    RandomizedSet() {
        dict.clear();
        size = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (dict.find(val) != dict.end())
        {
            return false;
        }
        dict.insert(pair<int, int>(val, size));
        v[size++] = val;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (dict.find(val) == dict.end())
        {
            return false;
        }
        int pos = dict[val];
        if (pos == size-1)
        {
            dict.erase(val);
            size--;
            return true;
        }
        v[pos] = v[size-1];
        dict[v[size-1]] = pos;
        dict.erase(val);
        size--;
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return v[rand()%size];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
