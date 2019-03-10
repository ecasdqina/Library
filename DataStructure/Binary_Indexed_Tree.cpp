template<typename T>
struct BinaryIndexedTree{
	vector<T> data;
	
	BinaryIndexedTree(int n) : data(++n, 0) {}
	void add(int k,T x){
		for(k++; k <= data.size(); k += k & -k) data[k] += x;
	}
	
	T get(int k){
		T ret = 0;
		for(k++; k > 0 ; k -= k & -k) ret += data[k];
		
		return ret;
	}    
};
