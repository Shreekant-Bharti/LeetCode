#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        vector<int> in_degree(n, 0);
        
        for (const auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            in_degree[e[1]]++;
        }

        vector<int> topo;
        topo.reserve(n);
        queue<int> q;
        
        for (int i = 0; i < n; ++i) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for (const auto& edge : adj[u]) {
                if (--in_degree[edge.first] == 0) {
                    q.push(edge.first);
                }
            }
        }

        int low = 0, high = 1e9, ans = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            vector<long long> dist(n, 1e18);
            dist[0] = 0;
            
            for (int u : topo) {
                if (dist[u] == 1e18) continue;
                if (u != 0 && u != n - 1 && !online[u]) continue;
                
                for (const auto& edge : adj[u]) {
                    int v = edge.first;
                    long long c = edge.second;
                    
                    if (c >= mid) {
                        if (dist[u] + c < dist[v]) {
                            dist[v] = dist[u] + c;
                        }
                    }
                }
            }
            
            if (dist[n - 1] <= k) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};