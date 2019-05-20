template<typename Monoid>
class SegmentTree {
	using F = std::function<Monoid(Monoid, Monoid)>;
	const F f;
	const Monoid M1;
	
	std::vector<Monoid> seg;
	int sz;
	
	bool built;
	
	private:
	void set(int k, const Monoid x) {
		built = false;
		seg[k + sz] = x;
	}
	void build() {
		if(built) return;
		built = true;
		for(int k = sz - 1; k > 0; k--) {
			seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
		}
	}
	
	public:
	SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
		sz = 1;
		built = true;
		while(sz < n) sz <<= 1;
		seg.assign(sz * 2, M1);
	}
	SegmentTree(std::vector<Monoid> array, const F f, const Monoid &M1) : f(f), M1(M1) {
		sz = 1;
		built = true;
		while(sz < array.size()) sz <<= 1;
		seg.assign(sz * 2, M1);
		update(array);
	}
	bool update(int k, Monoid x) {
		if(k > sz) return false;		
		k += sz;
		seg[k] = x;
		while(k >>= 1) {
			seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
		}
		return true;
	}
	bool update(std::vector<Monoid> array) {
		if(array.size() > sz) return false;
		for(int i = 0; i < array.size(); i++) set(i , array[i]);
		build();
		return true;
	}
	Monoid get(int a, int b) {
		build();
		Monoid L = M1, R = M1;
		for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
			if(a & 1) L = f(L, seg[a++]);
			if(b & 1) R = f(seg[--b], R);
		}
		return f(L, R);
	}
	Monoid operator[](const int k) const {
		return seg[k + sz];
	}
};
