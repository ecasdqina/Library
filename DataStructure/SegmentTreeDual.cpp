template<typename Monoid>
class SegmentTreeDual {
	std::vector<Monoid> data;
	size_t sz;
	
	using F = std::function<Monoid (Monoid, Monoid)>;
	
	const F f;
	const Monoid E;
	
	public:
	SegmentTreeDual(const size_t N, const F f, const Monoid E) : f(f), E(E) {
		sz = 1;
		while(sz < N) sz <<= 1;
		data.assign(sz << 1, E);
	}
	void set(int k, const Monoid x) {
		data[k + sz] = x;
	}
	void build() {
		for(int k = sz - 1; k > 0; k--) data[k] = f(data[k << 1 ^ 0], data[k << 1 ^ 1]);
	}
	void update(int a, int b, const Monoid x) {
		for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
			if(a & 1) data[a] = f(data[a++], x);
			if(b & 1) data[--b] = f(data[b], x);
		}
	}
	void update(int k, const Monoid x) {
		k += sz;
		data[k] = f(data[k], x);
	}
	void change(int k, const Monoid x) {
		k += sz;
		data[k] = x;
	}
	Monoid query(int k) {
		k += sz;
		Monoid ret = data[k];
		while(k >>= 1) ret = f(ret, data[k]);
		return ret;
	}
	const Monoid operator[](int k) {
		return query(k);
	}
};
