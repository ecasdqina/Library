type UnionFind struct {
	data []int
}

func NewUnionFind(n int) *UnionFind {
	data := make([]int, n)
	for i := 0; i < n; i++ {
		data[i] = -1
	}

	return &UnionFind{data}
}

func (data *UnionFind) unite(x, y int) bool {
	x, y = data.find(x), data.find(y)

	if x == y {
		return false
	}

	if data.data[x] > data.data[y] {
		x, y = y, x
	}

	data.data[x] += data.data[y]
	data.data[y] = x
	return true
}

func (data *UnionFind) find(k int) int {
	if data.data[k] < 0 {
		return k
	} else {
		data.data[k] = data.find(data.data[k])
		return data.data[k]
	}
}

func (data *UnionFind) same(x, y int) bool {
	return data.find(x) == data.find(y)
}

func (data *UnionFind) size(k int) int {
	return -data.data[data.find(k)]
}
