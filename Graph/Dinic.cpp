template<typename T>
struct Dinic{
	struct edge{
		int to;
		T cap;
		int rev;
	};
	
	const T INF;
	std::vector<std::vector<edge>> g;
	std::vector<T> min_cost;
	std::vector<int> itr;
	
	Dinic(int n) : INF(std::numeric_limits<T>::max()){
		g.resize(n);
	}
	
	void add_edge(int from, int to, T cap){
		g[from].push_back(edge{to, cap, (int)g[to].size()});
		g[to].push_back(edge{from, 0, (int)g[from].size() - 1});
	}
	
	bool bfs(int s, int t){
		min_cost.assign(g.size(), -1);
		std::queue<int> qu; qu.push(s); min_cost[s] = 0;
		
		while(!qu.empty()){
			auto p = qu.front(); qu.pop();
			
			for(auto e:g[p]){
				if(e.cap <= 0 or min_cost[e.to] != -1) continue;
				min_cost[e.to] = min_cost[p] + 1;
				qu.push(e.to);
			}
		}
		
		return min_cost[t] != -1;
	}
	
	T dfs(int idx, const int t, T flow){
		if(idx == t) return flow;
		for(int &i = itr[idx]; i < g[idx].size(); i++){
			edge &e = g[idx][i];
			
			if(e.cap <= 0 or min_cost[idx] >= min_cost[e.to]) continue;
			T d = dfs(e.to, t, std::min(flow, e.cap));
			if(d > 0){
				e.cap -= d;
				g[e.to][e.rev].cap += d;
				return d;
			}
			
		}
		
		return 0;
	}
	
	T max_flow(int s, int t){
		T flow = 0;
		while(bfs(s, t)){
			itr.assign(g.size(), 0);
			T f = 0;
			while((f = dfs(s, t, INF)) > 0) flow += f;
		}

		return flow;
	}
};
