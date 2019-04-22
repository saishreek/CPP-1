#include <iostream>
#include <list>
using namespace std;

class Graph {
    int v;
    list<int> * adj;

    public:
        Graph(int v) {
            this->v = v;
            adj = new list<int>[v];
        }

        void addEdge(int v1, int v2) {
            adj[v1].push_back(v2);
        }

        void BFT(int n) {
            bool * visited = new bool[this->v];
            for (int i = 0; i < this->v; i++) {
                visited[i] = false;
            }
            list<int> q;
            visited[n] = true;

            q.push_back(n);

            while (!q.empty()) {
                n = q.front();
                cout << n << " ";
                q.pop_front();

                list<int>::iterator i;

                for (i = this->adj[n].begin(); i != this->adj[n].end(); ++i) {
                    if (!visited[*i]) {
                        visited[*i] = true;
                        q.push_back(*i);
                    }
                }
            }
        }

};

int main() {

    Graph g = Graph(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.BFT(2);

    return 0;
}