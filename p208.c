struct TrieNode {
    struct TrieNode **child;
    bool isend;
};

void init(struct TrieNode *node) {
    node->isend = false;
    node->child = (struct TrieNode**)malloc(sizeof(struct TrieNode*)*26);
    for (int i = 0; i < 26; i++)
    {
        node->child[i] = NULL;
    }
}

typedef struct {
    struct TrieNode root;
} Trie;

/** Initialize your data structure here. */
Trie* trieCreate() {
    Trie *trie = (Trie*)malloc(sizeof(Trie));
    init(&(trie->root));
    return trie;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char* word) {
    int i;
    struct TrieNode *node = &(obj->root);
    for (i = 0; word[i] != '\0'; i++)
    {
        if (node->child[word[i]-'a'] == NULL)
        {
            node->child[word[i]-'a'] = (struct TrieNode*)malloc(sizeof(struct TrieNode));
            init(node->child[word[i]-'a']);
        }
        node = node->child[word[i]-'a'];
    }
    node->isend = true;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char* word) {
    int i;
    struct TrieNode *node = &(obj->root);
    for (i = 0; word[i] != '\0'; i++)
    {
        if (node->child[word[i]-'a'] == NULL)
        {
            return false;
        }
        node = node->child[word[i]-'a'];
    }
    return node->isend;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char* prefix) {
    int i;
    struct TrieNode *node = &(obj->root);
    for (i = 0; prefix[i] != '\0'; i++)
    {
        if (node->child[prefix[i]-'a'] == NULL)
        {
            return false;
        }
        node = node->child[prefix[i]-'a'];
    }
    return true;
}

void trieFree(Trie* obj) {
    
}

/**
 * Your Trie struct will be instantiated and called as such:
 * struct Trie* obj = trieCreate();
 * trieInsert(obj, word);
 * bool param_2 = trieSearch(obj, word);
 * bool param_3 = trieStartsWith(obj, prefix);
 * trieFree(obj);
 */
