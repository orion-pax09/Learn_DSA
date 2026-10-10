#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Graph{
    public:
    unordered_map<char , vector<char>>adj;
    unordered_map<char , int>vis;
    void addEdge(char u , char v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void dfs_Search(char curr){
        if (vis[curr]==1){
            return;
        }
        vis[curr]=1;
        cout << curr << " ";
        for (auto it : adj[curr]){
            dfs_Search(it);
        }
    }
    void dfs(char start){
        vis.clear();
        dfs_Search(start);
    }
};

int main(){
    Graph g;
    g.addEdge('A' , 'B');
    g.addEdge('B' , 'C');
    g.addEdge('C' , 'E');
    g.addEdge('C' , 'A');
    g.addEdge('B' , 'F');
    g.addEdge('C' , 'F');
    g.dfs('A');

}
