#define N 200005
#define INF 1e9

int visited[N], parent[N], distance[N];
vector<pair<int, int>> adj[N];

void dijkstra(int x) {
	for (int i = 1; i < N; i++) distance[i] = INF;
	distance[x] = 0;
	priority_queue<pair<int, int>> q;
	q.push({0, x});
	while (!q.empty()) {
		int a = q.top().second;
		q.pop();
		if (visited[a]) continue;
		for (auto u : adj[a]) {
			int b = u.first, w = u.second;
			if (distance[a] + w < distance[b]) {
				distance[b] = distance[a] + w;
				parent[b] = a;
				q.push({ -distance[b], b});
			}
		}
	}
}