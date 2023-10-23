// Import Cpp Library //
#pragma GCC optimization("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Matrix = vector<vector<ll>>;
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
const int MOD = (int)1e9 + 7;
const int INF = (int)1e9 + 1;
inline ll gcd(ll a, ll b) { ll r; while (b) { r = a % b; a = b; b = r; } return a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

// Your function here
vector<vector<int>> edgesToMatrix(vector<pair<int, int>>& edges, int n) {
    vector<vector<int>> graph(n, vector<int>(n, 0));

    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    return graph;
}

vector<vector<int>> edgesToAdjList(vector<pair<int, int>>& edges, int n) {
    vector<vector<int>> adj(n);

    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return adj;
}

vector<vector<int>> matrixToAdjList(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> adjList(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                adjList[i].push_back(j);
            }
        }
    }

    return adjList;
}

vector<vector<int>> adjListToMatrix(vector<vector<int>>& adjList) {
    int n = adjList.size();
    vector<vector<int>> adjacencyMatrix(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int neighbor : adjList[i]) {
            adjacencyMatrix[i][neighbor] = 1;
            adjacencyMatrix[neighbor][i] = 1;
        }
    }

    return adjacencyMatrix;
}
//

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("errors.txt", "w", stderr);
    #endif
    // Your code here
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    // Biến đổi danh sách cạnh thành ma trận kề
    vector<vector<int>> adjacencyMatrix = edgesToMatrix(edges, n);

    cout << "Ma trận kề:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "--------------" << endl;

    // Biến đổi danh sách cạnh thành danh sách kề
    vector<vector<int>> adjacencyList = edgesToAdjList(edges, n);

    cout << "Danh sách kề:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Danh sách kề của đỉnh " << i << ": ";
        for (int neighbor : adjacencyList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    cout << "--------------" << endl;

    // Biến đổi ma trận kề thành danh sách kề
    vector<vector<int>> adjacencyListFromMatrix = matrixToAdjList(adjacencyMatrix);

    cout << "Danh sách kề từ ma trận kề:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Danh sách kề của đỉnh " << i << ": ";
        for (int neighbor : adjacencyListFromMatrix[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    cout << "--------------" << endl;

    // Biến đổi danh sách kề thành ma trận kề
    vector<vector<int>> adjacencyMatrixFromList = adjListToMatrix(adjacencyList);

    cout << "Ma trận kề từ danh sách kề:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjacencyMatrixFromList[i][j] << " ";
        }
        cout << endl;
    }
    // END
    return 0;
}