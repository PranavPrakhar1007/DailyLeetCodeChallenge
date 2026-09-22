struct Node {
    int rem[5] = {};
    int prod = 1;
};

class SegmentTree {
    int n, k;
    vector<Node> tree;

    Node merge(const Node& a, const Node& b) {
        Node res;
        res.prod = (a.prod * b.prod) % k;

        for (int i = 0; i < k; ++i)
            res.rem[i] = a.rem[i];

        for (int i = 0; i < k; ++i)
            res.rem[(i * a.prod) % k] += b.rem[i];

        return res;
    }

    void build(vector<int>& nums, int p, int l, int r) {
        if (l == r) {
            tree[p].prod = nums[l];
            tree[p].rem[nums[l]] = 1;
            return;
        }

        int m = (l + r) / 2;
        build(nums, 2 * p + 1, l, m);
        build(nums, 2 * p + 2, m + 1, r);
        tree[p] = merge(tree[2 * p + 1], tree[2 * p + 2]);
    }

    void update(int p, int l, int r, int idx, int val) {
        if (l == r) {
            tree[p] = Node();
            tree[p].prod = val;
            tree[p].rem[val] = 1;
            return;
        }

        int m = (l + r) / 2;

        if (idx <= m)
            update(2 * p + 1, l, m, idx, val);
        else
            update(2 * p + 2, m + 1, r, idx, val);

        tree[p] = merge(tree[2 * p + 1], tree[2 * p + 2]);
    }

    Node query(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return tree[p];

        if (r < ql || qr < l)
            return Node();

        int m = (l + r) / 2;

        return merge(
            query(2 * p + 1, l, m, ql, qr),
            query(2 * p + 2, m + 1, r, ql, qr)
        );
    }

public:
    SegmentTree(vector<int>& nums, int k) : n(nums.size()), k(k), tree(4 * n) {
        build(nums, 0, 0, n - 1);
    }

    void update(int idx, int val) {
        update(0, 0, n - 1, idx, val);
    }

    Node query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        for (int& x : nums)
            x %= k;

        SegmentTree st(nums, k);
        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            st.update(q[0], q[1] % k);
            ans.push_back(st.query(q[2], nums.size() - 1).rem[q[3]]);
        }

        return ans;
    }
};