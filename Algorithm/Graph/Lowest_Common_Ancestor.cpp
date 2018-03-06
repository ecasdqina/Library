struct LowestCommonAncestor{
	vector<vector<int>> g, parent;
	vector<int> depth;
	bool built = false;
	int N;
	
	LowestCommonAncestor(int n) : N(n) {
		g.resize(N);
		parent.resize(logN, vector<int>(N));
		depth.resize(N);
	}
	
	void add_edge(int u, int v){
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	void dfs(int v, int par = -1, int d = 0){
		parent[0][v] = par;
		depth[v] = d;
		
		for(auto e:g[v]){
			if(e == par) continue;
			dfs(e, v, d + 1);
		}
	}
	
	void build(){
		dfs(0);
		for(int k = 0; k < logN - 1; k++){
			for(int i = 0; i < N; i++){
				if(parent[k][i] < 0) parent[k + 1][i] = -1;
				else parent[k + 1][i] = parent[k][parent[k][i]];
			}
		}
	}
	
	int get(int u, int v){
		if(!built) build(); built = true;
		if(depth[u] > depth[v]) swap(u, v);
		
		for(int k = 0; k < logN; k++){
			if(((depth[v] - depth[u]) >> k) & 1){
				v = parent[k][v];
			}
		}
		if(u == v) return u;
		
		for(int k = logN - 1; k >= 0; k--){
			if(parent[k][u] == parent[k][v]) continue;
			u = parent[k][u];
			v = parent[k][v];			
		}
		
		return parent[0][u];
	}
};
