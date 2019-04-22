#include <iostream>
#include <vector>
using namespace std;
using std::vector;

class Graph {
    int v;
    vector<int> * adj;

    public:
        Graph(int v) {
            this->v = v;
            adj = new vector<int>[v];
        }

        void addEdge(int v1, int v2) {
            this->adj[v1].push_back(v2);
        }

        void DFTVisit(int n, bool visited[]) {
            visited[n] = true;
            cout << n << " ";

            for (int i = 0; i < this->adj[n].size(); i++) {
                if (!visited[this->adj[n][i]]) {
                    DFTVisit(this->adj[n][i], visited);
                }
            }

        }

        void DFT(int n) {
            bool * visited = new bool[this->v];
            for (int i = 0; i < this->v; i++) {
                visited[i] = false;
            }
            DFTVisit(n, visited);

        }

};

int main() {

    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    g.DFT(2);

    return 0;
}