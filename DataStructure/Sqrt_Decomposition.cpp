struct Node{
	int data;
	
	Node(int data) : data(data) {}
	
	Node operator*(const Node r) const{
		return Node(data + r.data);
	}
} e(0);

struct SqrtDecomposition{
	vector<Node> data;
	vector<Node> bucket;
	int K, N;
	
	SqrtDecomposition(int n) : N(n){
		K = (N + sqrtN - 1) / sqrtN;
		data.assign(K * sqrtN, e);
		bucket.assign(K, e);
	}
	
	void update(int k, int x){
		data[k] = Node(x);
		k = k / sqrtN;
		
		Node ret = e;
		for(int i = k * sqrtN; i < (k + 1) * sqrtN; i++){
			ret = ret * data[i];
		}
		bucket[k] = ret;
	}
	
	int get(int a, int b){
		Node ret = e;
		for(int k = 0; k < K; k++){
			int l = k * sqrtN, r = (k + 1) * sqrtN;
			
			if(b<=l||r<=a) continue;
			if(a<=l&&r<=b) ret = ret * bucket[k];
			else{
				for(int i = max(a, l); i < min(b, r); i++){
					ret = ret * data[i];
				}
			}
		}
		
		return ret.data;
	}
};
