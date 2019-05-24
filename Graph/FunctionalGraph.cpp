class functionalGraph {
	std::vector<std::vector<int>> revGraph;
	std::vector<int> to;
	
	std::vector<std::vector<int>> loop, group, root;
	std::vector<int> indexOfGroup;
	std::vector<bool> isInLoop;
	
	public:
	functionalGraph(size_t n) : revGraph(n), to(n, -1) {};
	void addEdge(int a, int b) {
		assert(to[a] == -1);
		
		to[a] = b;
		revGraph[b].push_back(a);
	}
	void decomposition() {
		const size_t N = to.size();
		
		isInLoop.resize(N, false);
		indexOfGroup.resize(N, -1);
		
		std::vector<bool> used(N, false);
		for(int i = 0; i < N; i++) {
			if(used[i]) continue;
			
			loop.push_back({});
			
			std::vector<int> tmp;
			std::function<void (int)> dfs = [&](int v) {
				if(used[v]) {
					reverse(begin(tmp), end(tmp));
					for(auto u: tmp) {
						loop.back().push_back(u);
						
						if(u == v) break;
					}
					return;
				}
				
				used[v] = true;
				tmp.push_back(v);
				dfs(to[v]);
			};
			dfs(i);
			
			for(auto v: loop.back()) isInLoop[v] = true;
			
			root.push_back({});
			group.push_back({});
			for(auto v: loop.back()) {
				std::function<bool (int, int)> dfs = [&](int v, int par) {
					if(isInLoop[v]) return false;
					
					used[v] = true;
					group.back().push_back(v);
					
					bool ret = false;
					for(auto e: revGraph[v]) {
						if(e == par) continue;
						ret |= dfs(e, v);
					}
					
					return ret;
				};
				if(dfs(v, -1)) root.back().push_back(v);
			}
			
			for(auto v: group.back()) indexOfGroup[v] = (int)group.size() - 1;
		}
	}
	std::vector<std::vector<int>> getRevGraph() { return revGraph; }
	std::vector<std::vector<int>> getGroup() { return group; }
	std::vector<std::vector<int>> getLoop() { return loop; }
	std::vector<std::vector<int>> getRoot() { return root; }
	std::vector<int> getTo() { return to; }
	bool getIsInLoop(int k) { return isInLoop[k]; }
	size_t size() {
		return group.size();
	}
	int operator[](int k) {
		return indexOfGroup[k];
	}
};
