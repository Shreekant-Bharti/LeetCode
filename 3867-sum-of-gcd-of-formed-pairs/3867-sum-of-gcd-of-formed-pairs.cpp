class Solution {
public:
    long long gcdSum(vector<int>& a) {
        int n = a.size();
        int m = 0;
        vector<int> p(n);
        
        for(int i = 0; i < n; i++) {
            m = max(m, a[i]);
            p[i] = gcd(a[i], m);
        }
        
        sort(p.begin(), p.end());
        
        long long s = 0;
        int l = 0, r = n - 1;
        
        while(l < r) {
            s += gcd(p[l], p[r]);
            l++;
            r--;
        }
        
        return s;
    }
};