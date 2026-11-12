class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int size = graph.size();
        queue<int>Q;
        vector<int>vis(size , -1);
        for (int i = 0 ; i < size ; i++){
            if (vis[i]==-1){
                Q.push(i);
                vis[i]=0;
                while (!Q.empty()){
                    int x = Q.front();
                    Q.pop();
                    for (auto it : graph[x]){
                        if (vis[it]==-1){
                            vis[it] = 1 - vis[x];
                            Q.push(it);
                        }
                        else if (vis[it]==vis[x]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
