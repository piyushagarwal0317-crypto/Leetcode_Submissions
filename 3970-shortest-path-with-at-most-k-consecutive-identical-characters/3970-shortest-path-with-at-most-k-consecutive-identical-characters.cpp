class Solution {
public:
#define ll long long 
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        int sz = edges.size();

        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        

        vector<vector<ll>>dist(n, vector<ll>(k+1, INT_MAX));
         priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;

         dist[0][1] = 0;
         pq.push({0,0,1});

         while(!pq.empty()){
            auto e = pq.top(); 
            pq.pop();
            ll d = e[0];
            int u = e[1];
            int cur = e[2];

            if (d != dist[u][cur]) continue;

            for (auto &vec : adj[u]) {
                int v = vec.first, w = vec.second;
                int newcur = (labels[v] == labels[u]) ? cur + 1 : 1;
                if (newcur > k) continue;

                if (dist[v][newcur] > d + w) {
                    dist[v][newcur] = d + w;
                    pq.push({dist[v][newcur], v, newcur});
                }
            }
         }

         
        ll ans = INT_MAX;
        for (int i = 1; i <= k; i++) ans = min(ans, dist[n - 1][i]);
        return ans == INT_MAX ? -1 : ans;

    }
};