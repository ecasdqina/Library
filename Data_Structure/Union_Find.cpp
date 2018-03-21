struct UnionFind{
	vector<int> data;

	UnionFind(int sz){
		data.assign(sz, -1);
	}
	
	void unite(int x, int y){
		x = find(x); y = find(y);
		if(x == y) return ;
		if(data[x] > data[y]) swap(x, y);
		data[x] += data[y];
		data[y] = x;
	}
	
	bool same(int x, int y){
		x = find(x); y = find(y);
		if(x == y) return true;
		else return false;
	}
	
	int find(int k){
		if(data[k] < 0) return k;
		return data[k] = find(data[k]);
	}
	
	int size(int k){
		return -data[find(k)];
	}
};
