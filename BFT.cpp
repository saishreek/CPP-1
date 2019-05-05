#include <iostream>
#include <list>
#include <vector>
using std::vector;
using namespace std;

class Graph {
	struct node {
		int num;
		int dist;
	};

	vector<struct node> nodes;
	list<int> * adj;
	int n;

	public:
		Graph(int n) {
			adj = new list<int>[n];
			this->n = n;
			for (int i = 0; i < n; i++) {
				struct node tmp = {i, 0};
				nodes.push_back(tmp);
			}
		}

		void addEdge(int v1, int v2) {
			adj[v1].push_back(v2);
		}

		void bfs(int s, int d) {
			bool * visited = new bool[this->n];
			int dist = 0;

			for (int i = 0; i < this->n; i++) {
				visited[i] = false;
			}

			list<int> queue;
			queue.push_back(s);

			visited[s] = true;

			list<int>::iterator i;

			
			while(!queue.empty()) {
				s = queue.front();
				cout << s << " ";
				queue.pop_front();
				

				for (i = adj[s].begin(); i != adj[s].end(); ++i) {
					if (!visited[*i]) {
						queue.push_back(*i);
						visited[*i] = true;
						nodes[*i].dist = nodes[s].dist + 1;
					}
				}
			}

			cout << endl << "Dist: " << nodes[d].dist << endl;
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

	g.bfs(0, 3);

	return 0;
}
