template<typename T>
class GarnerAlgorithm {
	std::vector<T> b, m;
	const T MOD;
	
	private:
	inline T mod(T x, T mod) {
		x %= mod;
		return (x < 0 ? x + mod : x);
	}
	T extGCD(T a, T b, T &p, T &q) {
		if(!b) {
			p = 1;
			q = 0;
			return a;
		}
		T d = extGCD(b, a % b, q, p);
		q -= a / b * p;
		return d;
	}
	T modinv(T a, T m) {
		T x = 0, y = 0;
		extGCD(a, m, x, y);
		return mod(x, m);
	}
	bool isCoprime() {
		if(!b.size()) return false;
		T g = m[0];
		for(auto v : m) g = std::__gcd(g, v);
		return g == 1;
	}
	public:
	GarnerAlgorithm(T mod) : MOD(mod) {
		b.resize(0);
		m.resize(0);
	}
	void add(T B, T M) {
		b.push_back(B);
		m.push_back(M);
	}
	i64 Garner() {
		if(!isCoprime()) return -1;
		m.push_back(MOD);
		std::vector<T> coeffs(m.size(), 1);
		std::vector<T> constants(m.size(), 0);
		for(int k = 0; k < b.size(); ++k) {
			T t = mod((b[k] - constants[k]) * modinv(coeffs[k], m[k]), m[k]);
			for(int i = k + 1; i < m.size(); ++i) {
				(constants[i] += t * coeffs[i]) %= m[i];
				(coeffs[i] *= m[k]) %= m[i];
			}
		}
		m.pop_back();
		return constants.back();
	}
};
