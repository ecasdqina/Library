struct Node{
	int data;
	
	Node(int data) : data(data) {}
	Node operator*(const Node r){return Node(std::min(data, r.data));}
}e(std::numeric_limits<int>::max());

struct SegmentTree{
	std::vector<Node> seg;
	int sz = 1;
	
	SegmentTree(int n){
		while(sz < n) sz *= 2;
		seg.assign(sz * 2, e);
	}
	
	void update(int k, int x){
		k += sz - 1;
		seg[k] = x;
		
		while(k){
			k = (k - 1) / 2;
			seg[k] = seg[2 * k + 1] * seg[2 * k + 2];
		}
	}
	
	int get(int a, int b){
		return get(a, b, 0, 0, sz).data;
	}
	
	Node get(int a, int b, int k, int l, int r){
		if(b<=l||r<=a) return 0;
		if(a<=l&&r<=b) return seg[k];
		
		return get(a, b, 2 * k + 1, l, (l + r) / 2) * get(a, b, 2 * k + 2, (l + r) / 2, r);
	}
};
