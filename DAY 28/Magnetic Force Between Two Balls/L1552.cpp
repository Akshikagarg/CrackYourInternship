class Solution {
public:
    bool isValid(long long &m, vector<int> &pos, int &n, int &k) {
        int p = pos[0];
        int e = 1;
        for(int i=1; i<n; i++) {
            if (pos[i] - p  >= m) {
                p = pos[i];
                e++;
            }
            if (e == k) return true;
        }
        return false;
    }
    int maxDistance(vector<int>& pos, int k) {
        sort(pos.begin(), pos.end());
        int n = pos.size();
        if (n == 0) return 0;
         long long  l = 1;
        
        long long res = -1;
        long long r = 1e9 + 7;
        while(l < r) {
            long long m = (l+r)/2;
            if (isValid(m, pos, n, k)) {
                res = max(res, m);
                l = m+1;
            } else {
                r = m;
            }
        }
        return res;
    }
};
