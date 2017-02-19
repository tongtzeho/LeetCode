struct TrieNode {
    struct TrieNode **children;
    bool isend;
};

void init(struct TrieNode *node)
{
    node->isend = false;
    node->children = (struct TrieNode**)malloc(sizeof(struct TrieNode*)*26);
    int i;
    for (i = 0; i < 26; i++)
    {
        node->children[i] = NULL;
    }
}

bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    struct TrieNode root;
    struct TrieNode *node;
    init(&root);
    int i, j;
    for (i = 0; i < wordDictSize; i++)
    {
        node = &root;
        for (j = 0; wordDict[i][j] != '\0'; j++) {
            if (node->children[wordDict[i][j]-'a'] == NULL)
            {
                node->children[wordDict[i][j]-'a'] = (struct TrieNode*)malloc(sizeof(struct TrieNode));
                init(node->children[wordDict[i][j]-'a']);
            }
            node = node->children[wordDict[i][j]-'a'];
        }
        node->isend = true;
    }
    int len = strlen(s);
    bool *mem = (bool*)malloc(sizeof(bool)*(len+1));
    mem[len] = true;
    for (i = len-1; i >= 0; i--)
    {
        node = &root;
        mem[i] = false;
        for (j = i; j < len; j++)
        {
            if (node->children[s[j]-'a'] == NULL)
            {
                break;
            }
            else
            {
                node = node->children[s[j]-'a'];
                if (mem[j+1] && node->isend)
                {
                    mem[i] = true;
                    break;
                }
            }
        }
    }
    return mem[0];
}