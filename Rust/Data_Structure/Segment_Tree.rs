struct SegmentTree{
	seg: Vec<i64>,
	sz: usize,
}
	
impl SegmentTree {
	fn new(n: usize) -> SegmentTree {
		let mut sz: usize = 1;
		while sz < n { sz *= 2; }
		
		SegmentTree {
			seg: vec![0; 2 * sz],
			sz : sz,
		}
	}
	
	fn add(&mut self, mut k: usize, x: i64) {
		k += self.sz - 1;
		self.seg[k] += x;
		
		while k > 0 {
			k = (k - 1) / 2;
			self.seg[k] = self.seg[2 * k + 1] + self.seg[2 * k + 2];
		}
	}
	
	fn _get(&self, a: usize, b: usize, k: usize, l: usize, r: usize) -> i64 {
		if b <= l || r <= a { return 0; }
		if a <= l && r <= b { return self.seg[k]; }
		
		self._get(a, b, 2 * k + 1, l, (l + r) / 2) + self._get(a, b, 2 * k + 2, (l + r) / 2, r)
	}
	
	fn get(&self, a: usize, b: usize) -> i64 {
		self._get(a, b, 0, 0, self.sz)
	}
}
