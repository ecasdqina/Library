struct UnionFind {
	data: Vec<i32>,
}

impl UnionFind {
	fn new(n: usize) -> UnionFind {
		UnionFind {
			data: vec![-1; n],
		}
	}
	
	fn unite(&mut self, x: usize, y: usize) -> bool {
		let mut x = self.find(x);
		let mut y = self.find(y);
		if x == y { return false; }
		if self.data[x] > self.data[y] { std::mem::swap(&mut x, &mut y); }
		self.data[x] += self.data[y];
		self.data[y] = x as i32;
		true
	}
	
	fn find(&mut self, k: usize) -> usize {
		if self.data[k] < 0 {
			k
		}else{
			let l = self.data[k];
			self.data[k] = self.find(l as usize) as i32;
			self.data[k] as usize
		}
	}
	
	fn same(&mut self, x: usize, y: usize) -> bool {
		self.find(x) == self.find(y)
	}
	
	fn size(&mut self, k: usize) -> usize {
		let k = self.find(k);
		-self.data[k] as usize
	}
}
