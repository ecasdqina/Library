//Range Sum Query

struct Node{
	int data;
	
	Node(int data) : data(data) {};
	
	Node operator*(const Node r) const{
		return Node(data + r.data);		
	}
} e(0);

struct SegmentTree{
	vector<Node> data;
	int sz = 1;
	
	SegmentTree(int n){
		while(sz < n) sz *= 2;
		data.assign(2 * sz, e);
	}
	
	void update(int k, int x){
		sz += k - 1;
		data[k] = Node(x);
		
		while(k){
			k = (k - 1) / 2;
			data[k] = data[2 * k + 1] * data[2 * k + 2];
		}
	}
	
	int get(int a, int b){
		return get(a, b, 0, 0, sz).data;
	}
	
	Node get(int a, int b, int k, int l, int r){
		if(b<=l||r<=a) return e;
		if(a<=l&&r<=b) return data[k];
		
		return get(a, b, 2 * k + 1, l, (l + r) / 2) * get(a, b, 2 * k + 2, (l + r) / 2, r);
	}
};
