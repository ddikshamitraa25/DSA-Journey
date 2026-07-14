class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isEnd = false;
    }
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    void addWord(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->children[index] == NULL) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }

    bool dfs(string& word, int pos, TrieNode* node) {
        if (pos == word.size()) {
            return node->isEnd;
        }
        if (word[pos] == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->children[i] != NULL &&
                    dfs(word, pos + 1, node->children[i])) {
                    return true;
                }
            }
            return false;
        }
        int index = word[pos] - 'a';
        if (node->children[index] == NULL) {
            return false;
        }
        return dfs(word, pos + 1, node->children[index]);
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */