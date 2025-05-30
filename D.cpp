#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> tree;
vector<int> subtreeSize;
int totalNodes;
int maxDisconnectedPairs = -1;
int criticalNode;

void dfs(int u, int parent){
    subtreeSize[u] = 1;
    vector<int> childSizes;

    for(int v : tree[u]){
        if(v == parent) continue;

        dfs(v, u);
        subtreeSize[u] += subtreeSize[v];
        childSizes.push_back(subtreeSize[v]);
    }

    int rest = totalNodes - subtreeSize[u];
    if(parent != -1){
        childSizes.push_back(rest);
    }

    int disconnectedPairs = 0;
    int sum = 0;
    for(int size : childSizes){
        disconnectedPairs += size * sum;
        sum += size;
    }

    if(disconnectedPairs > maxDisconnectedPairs){
        maxDisconnectedPairs = disconnectedPairs;
        criticalNode = u;
    }
}

int countSubtreeSize(int u, int parent, int banned){
    int size = 1;
    for(int v : tree[u]){
        if(v != parent && v != banned){
            size += countSubtreeSize(v, u, banned);
        }
    }
    return size;
}

int main(){
    int n;
    cin>>n;

    tree = vector<vector<int>>(n+1);
    subtreeSize = vector<int>(n+1, 0);
    totalNodes = n + 1;

    for(int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(0, -1);

    vector<int> componentSizes;
    for(int neighbor : tree[criticalNode]){
        int size = countSubtreeSize(neighbor, criticalNode, criticalNode);
        componentSizes.push_back(size);
    }

    int bestSaved = 0;
    for(int i=0;i<componentSizes.size();i++){
        for(int j=i+1;j<componentSizes.size();j++){
            int saved = componentSizes[i] * componentSizes[j];
            if(saved > bestSaved){
                bestSaved = saved;
            }
        }
    }

    int resultAfterAdd = maxDisconnectedPairs - bestSaved;

    cout<<maxDisconnectedPairs<<" "<<resultAfterAdd<<endl;

    return 0;
}
