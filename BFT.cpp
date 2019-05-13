#include <iostream>
#include <list>
#include <vector>

#define N 3

using std::vector;
using namespace std;

class Graph {
	public:

		struct node {
			int num;
			int dist;
			int group;
		};

		int n;
		vector<int> * adj;
		vector<struct node> nodes;

		Graph(int n) {
			this->n = n;
			adj = new vector<int>[n];
			for (int i = 0; i < n; i++) {
				struct node tmp = {i, 0, 0};
				nodes.push_back(tmp);
			}
		}

		void addEdge(int v1, int v2) {
			this->adj[v1].push_back(v2);
		}

		int allVisited(bool visited[]) {
			int tmp = 0;
			for (int i = 0; i < this->n; i++) {
				tmp += visited[i];
			}
			if (tmp == this->n) {
				return 0;
			}
			return 1;
		}

		int nextNode(bool visited[]) {
			for (int i = 0; i < this->n; i++) {
				if (!visited[i]) {
					return i;
				}
			}
		}

		void BFS(int s, int d) {
			bool * visited = new bool[this->n];
			for (int i = 0; i < this->n; i++) {
				visited[i] = false;
			}
			list<int> q;
			q.push_back(s);
			int grp = 0, keep = 1;
			visited[s] = true;

			while(keep) {
				while(!q.empty()) {
					s = q.front();
					q.pop_front();
					cout << s << " ";
					
					for (int i = 0; i < this->adj[s].size(); i++) {
						if (!visited[this->adj[s][i]]) {
							visited[this->adj[s][i]] = true;
							nodes[this->adj[s][i]].dist = nodes[s].dist + 1;
							nodes[this->adj[s][i]].group = grp;
							q.push_back(this->adj[s][i]);
						}

					}
				}

				cout << endl;

				keep = allVisited(visited);
				if (keep) { 
					grp++;
					q.push_back(nextNode(visited));
					visited[q.front()] = true;
					nodes[q.front()].group = grp;
				}
			}
			cout << endl;

		}	

		void DFS(int s) {
			bool * visited = new bool[this->n];
			for (int i = 0; i < this->n; i++) {
				visited[i] = false;
			}

			DFSUtil(visited, s);
		}

		void DFSUtil(bool visited[], int n) {
			visited[n] = true;
			for (int i : this->adj[n]) {
				if (!visited[i]) {
					DFSUtil(visited, i);
				}
			}
		}

};



int main() {
	Graph g(8);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(4, 5);

	g.addEdge(6, 7);

	g.BFS(2, 4);

	for (int i = 0; i < g.n; i++) {
		cout << g.nodes[i].num << " : Group - " << g.nodes[i].group << endl;
	}

}
