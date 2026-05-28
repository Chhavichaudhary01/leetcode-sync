class TrieNode {
public:
    int child[26];
    int idx;

    TrieNode() {
        memset(child, -1, sizeof(child));
        idx = -1;
    }
};

class Solution {
public:

    vector<TrieNode> trie;
    vector<string> words;

    bool better(int a, int b) {

        if(b == -1) return true;

        if(words[a].size() < words[b].size())
            return true;

        if(words[a].size() == words[b].size() && a < b)
            return true;

        return false;
    }

    void insert(string &s, int id) {

        int node = 0;

        if(better(id, trie[node].idx))
            trie[node].idx = id;

        for(int i = s.size() - 1; i >= 0; i--) {

            int c = s[i] - 'a';

            if(trie[node].child[c] == -1) {
                trie[node].child[c] = trie.size();
                trie.push_back(TrieNode());
            }

            node = trie[node].child[c];

            if(better(id, trie[node].idx))
                trie[node].idx = id;
        }
    }

    int query(string &s) {

        int node = 0;

        for(int i = s.size() - 1; i >= 0; i--) {

            int c = s[i] - 'a';

            if(trie[node].child[c] == -1)
                break;

            node = trie[node].child[c];
        }

        return trie[node].idx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        words = wordsContainer;

        trie.push_back(TrieNode());

        for(int i = 0; i < wordsContainer.size(); i++) {
            insert(wordsContainer[i], i);
        }

        vector<int> ans;

        for(auto &q : wordsQuery) {
            ans.push_back(query(q));
        }

        return ans;
    }
};
