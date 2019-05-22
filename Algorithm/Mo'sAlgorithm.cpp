class Mo {
	// segment: [left, right)
	class Query {
		public:
		int left;
		int right;
		int id;
		
		Query(const int left, const int right, const int id) 
			: left(left), right(right), id(id) {};
	};
	
	std::vector<Query> queries;
	const size_t N;
	
	size_t getSqrt(const size_t t) {
		size_t sqrt = 0;
		while(sqrt * sqrt <= t) sqrt++;
		return sqrt - 1;
	}
	void build(const size_t sqrtQ) {
		sort(begin(queries), end(queries), [&](Query a, Query b) {
			const int bucketA = a.left / sqrtQ, bucketB = b.left / sqrtQ;
			if(bucketA == bucketB) {
				if(bucketA & 1) return a.right > b.right;
				return a.right < b.right;
			}
			return bucketA < bucketB;
		});
	}
	public:
	Mo(size_t n) : N(n) {}
	inline void addQuery(int left, int right) {
		queries.push_back(Query(left, right, (int)queries.size()));
	}
	inline int process() {
		static int left = 0, right = 0, index = 0;
		if(!index) build(getSqrt(queries.size()));
		
		Query q = queries[index++];
		while(left > q.left) add(--left);
		while(left < q.left) del(left++);
		while(right < q.right) add(right++);
		while(right > q.right) del(--right);
		return q.id;
	}
	inline void add(int i);
	inline void del(int i);
};

// :::impl:::
inline void Mo::add(int i) {};
inline void Mo::del(int i) {};
