template<typename Monoid, typename OperatorMonoid = Monoid>
class LazySegmentTree {
	std::vector<OperatorMonoid> lazy;
	std::vector<Monoid> data;
	size_t sz;
	
	using F = std::function<Monoid (Monoid, Monoid)>;
	using G = std::function<Monoid (Monoid, OperatorMonoid)>;
	using H = std::function<Monoid (OperatorMonoid, OperatorMonoid)>;
	using P = std::function<Monoid (OperatorMonoid, size_t)>;
	
	const F f;
	const G g;
	const H h;
	const P p;
	const Monoid E;
	const Monoid OE;
	
	public:
	LazySegmentTree(size_t N, const F f, const G g, const H h, const P p, const Monoid E, const OperatorMonoid OE) : f(f), g(g), h(h), p(p), E(E), OE(OE) {
		sz = 1;
		while(sz < N) sz <<= 1;
		data.assign(sz << 1, E);
		lazy.assign(sz << 1, OE);
	}
	void set(int k, const Monoid x) {
		data[k + sz] = x;
	}
	void build() {
		for(int k = sz - 1; k > 0; k--) data[k] = f(data[k << 1 ^ 0], data[k << 1 ^ 1]);
	}
	Monoid query(int a, int b) {
		return query(a, b, 1, 0, sz);
	}
	void update(int a, int b, OperatorMonoid x) {
		update(a, b, 1, 0, sz, x);
	}
	void update(int k, OperatorMonoid x) {
		update(k, k + 1, x);
	}
	void change(int k, Monoid x) {
		query(k, k + 1);
		
		k += sz;
		data[k] = x;
		while(k >>= 1) data[k] = f(data[k << 1 ^ 0], data[k << 1 ^ 1]);
	}
	Monoid operator[](int k) {
		return query(k, k + 1);
	}
	private:
	void propagate(int k, size_t len) {
		if(lazy[k] == OE) return;
		if(k < sz) {
			lazy[k << 1 ^ 0] = h(lazy[k << 1 ^ 0], lazy[k]);
			lazy[k << 1 ^ 1] = h(lazy[k << 1 ^ 1], lazy[k]);
		}
		data[k] = g(data[k], p(lazy[k], len));
		lazy[k] = OE;
	}
	Monoid query(int a, int b, int k, int l, int r) {
		propagate(k, r - l);
		if(b <= l || r <= a) return E;
		if(a <= l && r <= b) return data[k];
		
		Monoid LeftValue  = query(a, b, k << 1 ^ 0, l, (l + r) >> 1); 
		Monoid RightValue = query(a, b, k << 1 ^ 1, (l + r) >> 1, r);
		return f(LeftValue, RightValue);
	}
	void update(int a, int b, int k, int l, int r, OperatorMonoid x) {
		propagate(k, r - l);
		if(b <= l || r <= a) return;
		if(a <= l && r <= b) {
			lazy[k] = h(lazy[k], x);
			propagate(k, r - l);
			return;
		}
		
		update(a, b, k << 1 ^ 0, l, (l + r) >> 1, x);
		update(a, b, k << 1 ^ 1, (l + r) >> 1, r, x);
		data[k] = f(data[k << 1 ^ 0], data[k << 1 ^ 1]);
	}
};

// f : Monoid 同士の合成
// g : Monoid と OperatorMonoid の合成
// h : OperatorMonoid 同士の合成
// p : OperatorMonoid と幅 len の合成
// E : Identity Element of Monoid
// OE: Identity Element of OperatorMonoid
