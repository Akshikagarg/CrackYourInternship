class Solution {
public:
    vector<unordered_set<int>> tree;
    vector<int> ans, count;
    int N;
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        this->N=N;
        tree.resize(N);
        ans.assign(N, 0);
        count.assign(N, 1);
        for (auto e : edges) {
            tree[e[0]].insert(e[1]);
            tree[e[1]].insert(e[0]);
        }
        dfs(0, -1);
        dfs2(0, -1);
        return ans;

    }

      void dfs(int node, int parent) {
        for (int child: tree[node])
            if (child != parent) {
                dfs(child, node);
                count[node] += count[child];
                ans[node] += ans[child] + count[child];
            }
    }

       void dfs2(int node, int parent) {
        for (int child: tree[node])
            if (child != parent) {
                ans[child] = ans[node] - count[child] + N - count[child];
                dfs2(child, node);
            }
    }

};
