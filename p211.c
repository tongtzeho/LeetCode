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
} WordDictionary;

/** Initialize your data structure here. */
WordDictionary* wordDictionaryCreate() {
    WordDictionary *dict = (WordDictionary*)malloc(sizeof(WordDictionary));
    init(&(dict->root));
    return dict;
}

/** Adds a word into the data structure. */
void wordDictionaryAddWord(WordDictionary* obj, char* word) {
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

bool find(struct TrieNode *node, char *word) {
    for ( ; *word != '.' && *word != '\0'; word++)
    {
        if (node->child[(*word)-'a'] == NULL)
        {
            return false;
        }
        node = node->child[(*word)-'a'];
    }
    if (*word == '\0') return node->isend;
    int i;
    word++;
    for (i = 0; i < 26; i++)
    {
        if (node->child[i] != NULL && find(node->child[i], word))
        {
            return true;
        }
    }
    return false;
}

/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
bool wordDictionarySearch(WordDictionary* obj, char* word) {
    return find(&(obj->root), word);
}

void wordDictionaryFree(WordDictionary* obj) {
    
}

/**
 * Your WordDictionary struct will be instantiated and called as such:
 * struct WordDictionary* obj = wordDictionaryCreate();
 * wordDictionaryAddWord(obj, word);
 * bool param_2 = wordDictionarySearch(obj, word);
 * wordDictionaryFree(obj);
 */
