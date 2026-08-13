class Solution {
public:

    struct Node {
        int len;
        int pref;
        int suff;
        int best;
        char lc, rc;
    };

    vector<Node> seg;

    Node merge(Node a, Node b) {
        Node res;

        res.len = a.len + b.len;
        res.lc = a.lc;
        res.rc = b.rc;

        // Prefix
        res.pref = a.pref;
        if (a.pref == a.len && a.rc == b.lc) {
            res.pref = a.len + b.pref;
        }

        // Suffix
        res.suff = b.suff;
        if (b.suff == b.len && a.rc == b.lc) {
            res.suff = b.len + a.suff;
        }

        // Best answer
        res.best = max(a.best, b.best);

        if (a.rc == b.lc) {
            res.best = max(res.best, a.suff + b.pref);
        }

        return res;
    }

    void build(int idx, int l, int r, string &s) {
        if (l == r) {
            seg[idx] = {1, 1, 1, 1, s[l], s[l]};
            return;
        }

        int mid = (l + r) / 2;

        build(2 * idx, l, mid, s);
        build(2 * idx + 1, mid + 1, r, s);

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    void update(int idx, int l, int r, int pos, char c) {
        if (l == r) {
            seg[idx] = {1, 1, 1, 1, c, c};
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid) {
            update(2 * idx, l, mid, pos, c);
        } else {
            update(2 * idx + 1, mid + 1, r, pos, c);
        }

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        int n = s.size();

        seg.resize(4 * n);

        build(1, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < queryCharacters.size(); i++) {

            update(
                1,
                0,
                n - 1,
                queryIndices[i],
                queryCharacters[i]
            );

            ans.push_back(seg[1].best);
        }

        return ans;
    }
};
