class Solution {
public:
    struct Node{
        long long val = 0; // value after MOD
        int sum = 0; // sum of digits
        int len = 0;  // no. of non zero digits in right so, we can predict pow10
    };

    vector<Node> segTree;
    vector<long long> pow10;
    long long MOD = 1e9 + 7;

    void buildSegmentTree(int i, int l, int r, const string& s){
        // Base case
        if (l == r) {
            int digit = s[r] - '0';
            segTree[i].sum = digit;
            if (digit != 0) {
                segTree[i].val = digit;
                segTree[i].len = 1;
            } else {
                segTree[i].val = 0;
                segTree[i].len = 0;
            }
            return;
        }

        int mid = l + (r - l) / 2;
        buildSegmentTree(2*i+1, l, mid, s);
        buildSegmentTree(2*i+2, mid+1, r, s);

        Node leftNode = segTree[2*i+1];
        Node rightNode = segTree[2*i+2];

        segTree[i].sum = leftNode.sum + rightNode.sum;
        segTree[i].len = leftNode.len + rightNode.len;
        segTree[i].val = (leftNode.val * pow10[rightNode.len] + rightNode.val) % MOD;
    }

    Node query(int i, int l, int r, int ql, int qr){
        // Completely outside range (return empty node properties)
        if (qr < l || r < ql){
            return Node(); 
        }
        // Fully inside range
        if (ql <= l && r <= qr){
            return segTree[i];
        }

        // Partially inside
        // then take result from left and take result from right
        int mid = l + (r - l) / 2;
        Node leftNode = query(2 * i + 1, l, mid, ql, qr);
        Node rightNode = query(2 * i + 2, mid + 1, r, ql, qr);

        // merge the left and right results
        Node res;
        res.sum = leftNode.sum + rightNode.sum;
        res.len = leftNode.len + rightNode.len;
        // left -> 1, right -> 2, ans should be 12
        // 1*10 + 2 = 12
        res.val = (leftNode.val * pow10[rightNode.len] + rightNode.val) % MOD;
        
        return res;
    }

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        segTree.resize(4 * n);
        pow10.resize(n + 1, 1);

        for (int i = 1; i <= n; i++){
            pow10[i] = (pow10[i-1] * 10) % MOD;
        }

        // building the segment tree
        buildSegmentTree(0, 0, n - 1, s);

        vector<int> ans;
        for (auto& q : queries){
            int l = q[0], r = q[1];

            Node res = query(0, 0, n-1, l, r);
            
            long long finalAns = (res.val * res.sum) % MOD;
            ans.push_back(finalAns);
        }

        return ans;
    }
};