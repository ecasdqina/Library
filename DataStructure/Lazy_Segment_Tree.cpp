//Range Add Query AND Range Min Query

struct Node{
	int data, lazy;
	
	Node(int data, int lazy) : data(data), lazy(lazy) {}
	Node operator*(const Node r){return Node(min(data, r.data), lazy);}
	Node operator+(const Node r){return Node(data, lazy + r.lazy);}
	Node operator-(const Node r){return Node(data + r.lazy, 0);}
} e(INF, 0);

struct LazySegmentTree{
	vector<Node> seg;
	int sz = 1;
	
	LazySegmentTree(int n){
		while(sz < n) sz *= 2;
		seg.assign(sz * 2, e);
	}
	
	void update(int k, int x){
		k += sz - 1;
		seg[k] = Node(x, 0);
		while(k){
			k = (k - 1) / 2;
			seg[k] = seg[2 * k + 1] * seg[2 * k + 2];
		}
	}
	
	void push(int k){
		if(k < sz){
			seg[2 * k + 1] = seg[2 * k + 1] + seg[k];
			seg[2 * k + 2] = seg[2 * k + 2] + seg[k];
		}
		
		seg[k] = seg[k] - seg[k];
	}
	
	void add(int a, int b, int x){
		add(a, b, 0, 0, sz, Node(0, x));
	}
	
	void add(int a, int b, int k, int l, int r, Node x){
		push(k);
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b){
			seg[k] = seg[k] + x;
			push(k);
			return;
		}
		
		add(a, b, 2 * k + 1, l, (l + r) / 2, x);
		add(a, b, 2 * k + 2, (l + r) / 2, r, x);
		seg[k] = seg[2 * k + 1] * seg[2 * k + 2];
	}
	
	int get(int a, int b){
		return get(a, b, 0, 0, sz).data;
	}
	
	Node get(int a, int b, int k, int l, int r){
		push(k);
		if(b<=l||r<=a) return e;
		if(a<=l&&r<=b) return seg[k];
		
		return get(a, b, 2 * k + 1, l, (l + r) / 2) * get(a, b, 2 * k + 2, (l + r) / 2, r);
	}
};
