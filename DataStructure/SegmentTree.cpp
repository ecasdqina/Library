template<typename Monoid>
class SegmentTree {
	std::vector<Monoid> data;
	size_t sz;
	
	using F = std::function<Monoid(Monoid, Monoid)>;
	
	const F f;
	const Monoid E;
	
	public:
	SegmentTree(const size_t n, const F f, const Monoid E) : f(f), E(E) {
		sz = 1;
		while(sz < n) sz <<= 1;
		data.assign(sz << 1, E);
	}
	void set(int k, const Monoid x) {
		data[k + sz] = x;
	}
	void build() {
		for(int k = sz - 1; k > 0; k--) data[k] = f(data[2 * k + 0], data[2 * k + 1]);
	}
	void change(int k, const Monoid x) {
		k += sz;
		data[k] = x;
		
		while(k >>= 1) data[k] = f(data[k << 1 ^ 0], data[k << 1 ^ 1]);
	}
	void update(int k, const Monoid x) {
		k += sz;
		data[k] = f(data[k], x);
		
		while(k >>= 1) data[k] = f(data[k << 1 ^ 0], data[k << 1 ^ 1]);
	}
	Monoid query(int a, int b) {
		Monoid L = E, R = E;
		for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
			if(a & 1) L = f(L, data[a++]);
			if(b & 1) R = f(data[--b], R);
		}
		return f(L, R);
	}
	const Monoid operator[](const int k) const {
		return data[k + sz];
	}
};
