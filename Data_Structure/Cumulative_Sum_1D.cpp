template<typename T>
struct CumulativeSum{
	vector<T> data;
	
	CumulativeSum(int n) : data(n + 1, 0) {}
	
	void update(int k, T x){data[k + 1] = x;} //0 - indexed
	void add(int k, T x){data[k + 1] += x;} //0 - indexed
	void build(){
		for(int i = 0; i < data.size() - 1; i++){
			data[i + 1] += data[i];
		}
	}
	
	T get(int a, int b){ //1 - indexed
		a = max(0, a - 1);
		b = min((int)data.size() - 1, b);
		
		return data[b] - data[a];
	}
	
	T get(int a){ //1 - indexed
		return data[a];
	}
};
