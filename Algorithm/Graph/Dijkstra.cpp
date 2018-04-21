template<typename T>
struct Dijkstra{
	vector<vector<pair<int, T>>> g;
	
	Dijkstra(int n) : g(n) {}
	void add_edge(int u, int v, T cost){
		g[u].push_back({v, cost});
	}
	
	T dijkstra(int s, int t){
		vector<T> min_cost = dijkstra(s);
		
		return min_cost[t];
	}
	
	vector<T> dijkstra(int s = 0){
		priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> qu;
		vector<T> min_cost(g.size(), numeric_limits<T>::max());
		min_cost[s] = 0; qu.push({0, s});
		
		while(!qu.empty()){
			auto p = qu.top(); qu.pop();
			
			for(auto e : g[p.second]){
				if(p.first + e.second >= min_cost[e.first]) continue;
				min_cost[e.first] = p.first + e.second;
				qu.push({min_cost[e.first], e.first});
			}
		}
		
		return min_cost;
	}
};
