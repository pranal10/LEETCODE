class Solution {
public:
    struct Node {
        char leftChar, rightChar;
        int prefix, suffix, best, len;
    };

    string str;
    vector<Node> tree;

    Node merge(Node a, Node b) {
        Node res;

        res.len = a.len + b.len;
        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        res.prefix = a.prefix;
        if (a.prefix == a.len && a.rightChar == b.leftChar)
            res.prefix = a.len + b.prefix;

        res.suffix = b.suffix;
        if (b.suffix == b.len && a.rightChar == b.leftChar)
            res.suffix = b.len + a.suffix;

        res.best = max(a.best, b.best);

        if (a.rightChar == b.leftChar)
            res.best = max(res.best, a.suffix + b.prefix);

        return res;
    }

    void build(int idx, int l, int r) {
        if (l == r) {
            tree[idx] = {str[l], str[l], 1, 1, 1, 1};
            return;
        }

        int mid = (l + r) / 2;

        build(idx * 2, l, mid);
        build(idx * 2 + 1, mid + 1, r);

        tree[idx] = merge(tree[idx * 2], tree[idx * 2 + 1]);
    }

    void update(int idx, int l, int r, int pos, char ch) {
        if (l == r) {
            tree[idx] = {ch, ch, 1, 1, 1, 1};
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(idx * 2, l, mid, pos, ch);
        else
            update(idx * 2 + 1, mid + 1, r, pos, ch);

        tree[idx] = merge(tree[idx * 2], tree[idx * 2 + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices) {

        str = s;
        int n = s.size();

        tree.resize(4 * n);
        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            int pos = queryIndices[i];
            char ch = queryCharacters[i];

            update(1, 0, n - 1, pos, ch);

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};