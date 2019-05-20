package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"sort"
)

func main() {
	next := NewScanner()

}

// Scanner
type scanner struct {
	r   *bufio.Reader
	buf []byte
	p   int
}

func NewScanner() *scanner {
	return &scanner{r: bufio.NewReaderSize(os.Stdin, 10000)}
}

func (s *scanner) next() string {
	s.pre()
	start := s.p

	for ; s.p < len(s.buf); s.p++ {
		if s.buf[s.p] == ' ' {
			break
		}
	}

	result := string(s.buf[start:s.p])
	s.p++
	return result
}

func (s *scanner) Line() string {
	s.pre()
	start := s.p
	s.p = len(s.buf)

	return string(s.buf[start:])
}

func (s *scanner) Int() int {
	v, _ := strconv.Atoi(s.next())
	return v
}

func (s *scanner) Int64() int64 {
	v, _ := strconv.ParseInt(s.next(), 10, 64)
	return v
}

func (s *scanner) Float() float32 {
	f, _ := strconv.ParseFloat(s.next(), 32)

	return float32(f)
}

func (s *scanner) Float64() float64 {
	f, _ := strconv.ParseFloat(s.next(), 64)

	return f
}

func (s *scanner) Bool() bool {
	b, _ := strconv.ParseBool(s.next())

	return b
}

func (s *scanner) String() string {
	return s.next()
}

func (s *scanner) Byte() []byte {
	return []byte(s.String())
}

func (s *scanner) pre() {
	if s.p >= len(s.buf) {
		s.readLine()
		s.p = 0
	}
}

func (s *scanner) readLine() {
	s.buf = make([]byte, 0)
	for {
		l, p, e := s.r.ReadLine()
		if e != nil {
			panic(e)
		}
		s.buf = append(s.buf, l...)
		if !p {
			break
		}
	}
}

// Functions
func Itob(i int) bool {
	if i == 0 {
		return false
	} else {
		return true
	}
}

func Btoi(f bool) int {
	if f {
		return 1
	} else {
		return 0
	}
}

func min(a ...int) int {
	ret := a[0]
	for _, e := range a {
		if e < ret {
			ret = e
		}
	}

	return ret
}

func max(a ...int) int {
	ret := a[0]
	for _, e := range a {
		if e > ret {
			ret = e
		}
	}

	return ret
}

func minInt64(a ...int64) int64 {
	ret := a[0]
	for _, e := range a {
		if e < ret {
			ret = e
		}
	}

	return ret
}

func maxInt64(a ...int64) int64 {
	ret := a[0]
	for _, e := range a {
		if e > ret {
			ret = e
		}
	}

	return ret
}

func minFloat(a ...float32) float32 {
	ret := a[0]
	for _, e := range a {
		if e < ret {
			ret = e
		}
	}

	return ret
}

func maxFloat(a ...float32) float32 {
	ret := a[0]
	for _, e := range a {
		if e > ret {
			ret = e
		}
	}

	return ret
}

func minFloat64(a ...float64) float64 {
	ret := a[0]
	for _, e := range a {
		if e < ret {
			ret = e
		}
	}

	return ret
}

func maxFloat64(a ...float64) float64 {
	ret := a[0]
	for _, e := range a {
		if e > ret {
			ret = e
		}
	}

	return ret
}

func minOther(comp Comparator, a ...interface{}) interface{} {
	ret := a[0]
	for _, e := range a {
		if comp(e, ret) {
			ret = e
		}
	}

	return ret
}

func maxOther(comp Comparator, a ...interface{}) interface{} {
	ret := a[0]
	for _, e := range a {
		if comp(ret, a) {
			ret = e
		}
	}

	return ret
}

func abs(a int) int {
	if a < 0 {
		return -a
	} else {
		return a
	}
}

func absInt64(a int64) int64 {
	if a < 0 {
		return -a
	} else {
		return a
	}
}

func absFloat(a float32) float32 {
	if a < 0 {
		return -a
	} else {
		return a
	}
}

func absFloat64(a float64) float64 {
	if a < 0 {
		return -a
	} else {
		return a
	}
}

func gcd(a, b int) int {
	if b > 0 {
		return gcd(b, a%b)
	} else {
		return a
	}
}

func lcm(a, b int) int {
	return a / gcd(a, b) * b
}

func gcdInt64(a, b int64) int64 {
	if b > 0 {
		return gcdInt64(b, a%b)
	} else {
		return a
	}
}

func lcmInt64(a, b int64) int64 {
	return a / gcdInt64(a, b) * b
}

func ModPow(x, n, mod int) int {
	ret := 1

	for ; n > 0; n /= 2 {
		if (n & 1) == 1 {
			ret = ret * x % mod
		}

		x = x * x % mod
	}

	return ret
}

func ModPowInt64(x, n, mod int64) int64 {
	var ret int64 = 1

	for ; n > 0; n /= 2 {
		if (n & 1) == 1 {
			ret = ret * x % mod
		}

		x = x * x % mod
	}

	return ret
}

func IntComp(a, b interface{}) bool {
	na := a.(int)
	nb := b.(int)

	return na < nb
}

func Int64Comp(a, b interface{}) bool {
	na := a.(int64)
	nb := b.(int64)

	return na < nb
}

func FloatComp(a, b interface{}) bool {
	na := a.(float32)
	nb := b.(float32)

	return na < nb
}

func Float64Comp(a, b interface{}) bool {
	na := a.(float64)
	nb := b.(float64)

	return na < nb
}

func binary_search(a []interface{}, key interface{}, Less func(a, b interface{}) bool) int {
	ok, ng := -1, len(a)
	for abs(ok-ng) > 1 {
		mid := (ok + ng) / 2

		if Less(a[mid], key) {
			ok = mid
		} else {
			ng = mid
		}
	}

	return ok
}

// Structs
type Merger func(a, b interface{}) interface{}
type Comparator func(a, b interface{}) bool

// Pair
type Pair struct {
	first, second int64
}

func Newpair() *Pair {
	return &Pair{
		first:  0,
		second: 0,
	}
}

func (p Pair) Less(q Pair) bool {
	if p.first < q.first {
		return true
	} else if p.first == q.first {
		return p.second < q.second
	} else {
		return false
	}
}

func PairComp(p, q interface{}) bool {
	np := p.(Pair)
	nq := q.(Pair)

	return np.Less(nq)
}

func (p *Pair) swap(to *Pair) {
	p, to = to, p
}

func (p Pair) String() string {
	return fmt.Sprint("(", p.first, ", ", p.second, ")")
}

type Pairs []Pair

func (p Pairs) Len() int {
	return len(p)
}

func (p Pairs) Less(i, j int) bool {
	return p[i].Less(p[j])
}

func (p Pairs) Swap(i, j int) {
	p[i], p[j] = p[j], p[i]
}

// Stack
type Stack struct {
	data []interface{}
}

func NewStack() *Stack {
	return &Stack{make([]interface{}, 0)}
}

func (st *Stack) push(x interface{}) {
	st.data = append(st.data, x)
}

func (st *Stack) top() interface{} {
	return st.data[len(st.data)-1]
}

func (st *Stack) topInt() int {
	i, _ := st.top().(int)

	return i
}

func (st *Stack) topInt64() int64 {
	i, _ := st.top().(int64)

	return i
}

func (st *Stack) pop() {
	st.data = st.data[:len(st.data)-1]
}

func (st *Stack) size() int {
	return len(st.data)
}

func (st *Stack) empty() bool {
	return st.size() == 0
}

func (st *Stack) swap(to *Stack) {
	st, to = to, st
}

func (st *Stack) each() []interface{} {
	return st.data
}

// Queue
type Queue struct {
	data []interface{}
}

func NewQueue() *Queue {
	return &Queue{make([]interface{}, 0)}
}

func (qu *Queue) push(x interface{}) {
	qu.data = append(qu.data, x)
}

func (qu *Queue) front() interface{} {
	return qu.data[0]
}

func (qu *Queue) frontInt() int {
	e, _ := qu.front().(int)

	return e
}

func (qu *Queue) frontInt64() int64 {
	i, _ := qu.front().(int64)

	return i
}

func (qu *Queue) back() interface{} {
	return qu.data[len(qu.data)-1]
}

func (qu *Queue) backInt() int {
	e, _ := qu.back().(int)

	return e
}

func (qu *Queue) backInt64() int64 {
	i, _ := qu.back().(int64)

	return i
}

func (qu *Queue) pop() {
	qu.data = qu.data[1:]
}

func (qu *Queue) size() int {
	return len(qu.data)
}

func (qu *Queue) empty() bool {
	return qu.size() == 0
}

func (qu *Queue) swap(to *Queue) {
	qu, to = to, qu
}

func (qu *Queue) each() []interface{} {
	return qu.data
}

// Set
type Set struct {
	data map[interface{}]bool
}

func NewSet() *Set {
	return &Set{make(map[interface{}]bool)}
}

func (st *Set) size() int {
	return len(st.data)
}

func (st *Set) empty() bool {
	return st.size() == 0
}

func (st *Set) clear() {
	st.data = make(map[interface{}]bool)
}

func (st *Set) insert(x interface{}) {
	st.data[x] = true
}

func (st *Set) erase(x interface{}) {
	if !st.data[x] {
		return
	}

	delete(st.data, x)
}

func (st *Set) count(x interface{}) int {
	if st.data[x] {
		return 1
	}

	return 0
}

func (st *Set) swap(to *Set) {
	st, to = to, st
}

func (st *Set) each() []interface{} {
	ret := make([]interface{}, 0)

	for k, _ := range st.data {
		ret = append(ret, k)
	}

	return ret
}

// Priority Queue
// push : Push the value to the priority queue.
// top  : Return the (Min / Max) value in the priority queue.
// pop  : Delete the (Min / Max) value in the priority queue.
// size : Return the number of values in the priority queue.
// empty : Return Is priority queue has the values.
type PriorityQueue struct {
	data []interface{}
	comp Comparator
}

func NewPriorityQueue(comp Comparator) *PriorityQueue {
	return &PriorityQueue{make([]interface{}, 0), comp}
}

func (qu *PriorityQueue) push(x interface{}) {
	n := len(qu.data)
	qu.data = append(qu.data, x)

	for n != 0 {
		par := (n - 1) / 2

		if qu.comp(qu.data[par], qu.data[n]) {
			qu.data[par], qu.data[n] = qu.data[n], qu.data[par]
		}

		n = par
	}
}

func (qu *PriorityQueue) pop() {
	n := len(qu.data) - 1
	qu.data[0] = qu.data[n]
	qu.data = qu.data[:n]

	for i, j := 0, 1; j < n; {
		j = 2*i + 1

		if (j != n-1) && qu.comp(qu.data[j], qu.data[j+1]) {
			j++
		}

		if qu.comp(qu.data[i], qu.data[j]) {
			qu.data[i], qu.data[j] = qu.data[j], qu.data[i]
		}

		i = j
	}
}

func (qu *PriorityQueue) top() interface{} {
	return qu.data[0]
}

func (qu *PriorityQueue) topInt() int {
	i, _ := qu.top().(int)

	return i
}

func (qu *PriorityQueue) topInt64() int64 {
	i, _ := qu.top().(int64)

	return i
}

func (qu *PriorityQueue) topPair() Pair {
	p, _ := qu.top().(Pair)

	return p
}

func (qu *PriorityQueue) size() int {
	return len(qu.data)
}

func (qu *PriorityQueue) empty() bool {
	return len(qu.data) == 0
}

func (qu *PriorityQueue) swap(to *PriorityQueue) {
	qu, to = to, qu
}

// Union Find
type UnionFind struct {
	data []int
}

func NewUnionFind(N int) *UnionFind {
	data := make([]int, N)
	for i := 0; i < N; i++ {
		data[i] = -1
	}

	return &UnionFind{data}
}

func (uf *UnionFind) unite(x, y int) bool {
	x, y = uf.find(x), uf.find(y)
	if x == y {
		return false
	}

	if uf.data[x] > uf.data[y] {
		x, y = y, x
	}

	uf.data[x] += uf.data[y]
	uf.data[y] = x
	return false
}

func (uf *UnionFind) find(k int) int {
	if uf.data[k] < 0 {
		return k
	} else {
		uf.data[k] = uf.find(uf.data[k])
		return uf.data[k]
	}
}

func (uf *UnionFind) size(k int) int {
	return -uf.data[uf.find(k)]
}

func (uf *UnionFind) same(x, y int) bool {
	return uf.find(x) == uf.find(y)
}

// Segment Tree
// update : Update k-th value of SegmentTree.data to x
// get	 : Get the merged value in range [a, b)
type SegmentTree struct {
	data  []interface{}
	id    interface{}
	size  int
	merge Merger
}

func NewSegmentTree(n int, id interface{}, merge Merger) *SegmentTree {
	sz := 1
	for sz < n {
		sz *= 2
	}

	data := make([]interface{}, sz*2-1)
	for i := 0; i < sz*2-1; i++ {
		data[i] = id
	}

	return &SegmentTree{data, id, sz, merge}
}

func (seg *SegmentTree) update(k int, x interface{}) {
	k += seg.size - 1
	seg.data[k] = x

	for k > 0 {
		k = (k - 1) / 2

		seg.data[k] = seg.merge(seg.data[2*k+1], seg.data[2*k+2])
	}
}

func (seg *SegmentTree) get(a, b int) interface{} {
	return seg._get(a, b, 0, 0, seg.size)
}

func (seg *SegmentTree) _get(a, b, k, l, r int) interface{} {
	if b <= l || r <= a {
		return seg.id
	}

	if a <= l && r <= b {
		return seg.data[k]
	}

	L := seg._get(a, b, 2*k+1, l, (l+r)/2)
	R := seg._get(a, b, 2*k+2, (l+r)/2, r)
	return seg.merge(L, R)
}

func (seg *SegmentTree) String() string {
	return fmt.Sprint(seg.data[seg.size-1:])
}

// Trie Node
// Node for Trie Tree
const (
	char_size = 26
	margin    = 'a'
)

type TrieNode struct {
	nxt    [char_size]int
	accept []int
	exist  int
}

func NewTrieNode() *TrieNode {
	var nxt [char_size]int
	for i := 0; i < char_size; i++ {
		nxt[i] = -1
	}

	return &TrieNode{nxt, make([]int, 0), 0}
}

// Trie Tree
type TrieTree struct {
	nodes []TrieNode
	root  int
}

func NewTrieTree() *TrieTree {
	return &TrieTree{[]TrieNode{*NewTrieNode()}, 0}
}

func direct_action(node, id int) {
	//virtual function
}

func child_action(node, child, id int) {
	//virtual function
}

func (tree *TrieTree) update_direct(node, id int) {
	tree.nodes[node].accept = append(tree.nodes[node].accept, id)
	direct_action(node, id)
}

func (tree *TrieTree) update_child(node, child, id int) {
	tree.nodes[node].exist += 1
	child_action(node, child, id)
}

func (tree *TrieTree) add(str []byte, str_index, node_index, id int) {
	if str_index == len(str) {
		tree.update_direct(node_index, id)
	} else {
		c := int(str[str_index]) - int(margin)

		if tree.nodes[node_index].nxt[c] == -1 {
			tree.nodes[node_index].nxt[c] = len(tree.nodes)
			tree.nodes = append(tree.nodes, *NewTrieNode())
		}

		tree.add(str, str_index+1, tree.nodes[node_index].nxt[c], id)
		tree.update_child(node_index, tree.nodes[node_index].nxt[c], id)
	}
}

func (tree *TrieTree) InsertWithId(str []byte, id int) {
	tree.add(str, 0, 0, id)
}

func (tree *TrieTree) Insert(str []byte) {
	tree.InsertWithId(str, tree.nodes[0].exist)
}

func (tree *TrieTree) size() int {
	return tree.nodes[0].exist
}

func (tree *TrieTree) nodesize() int {
	return len(tree.nodes)
}

//Namori Graph
type Namori struct {
	g  [][]int
	in []int
}

func NewNamori(N int) *Namori {
	return &Namori{make([][]int, N), make([]int, N)}
}

func (data *Namori) add_edge(a, b int) {
	data.g[a] = append(data.g[a], b)
}

func (data *Namori) decomposition(loop []int, forest [][]int) {
	N := len(data.g)
	for i := 0; i < N; i++ {
		data.in[i] = len(data.g[i])
	}
	forest = make([][]int, N)
	qu := NewQueue()
	v := make([]bool, N)

	for i := 0; i < N; i++ {
		if data.in[i] == 1 {
			qu.push(i)
			v[i] = true
		}
	}

	for !qu.empty() {
		idx := qu.frontInt()
		qu.pop()

		for to := range data.g[idx] {
			if v[to] {
				continue
			}

			data.in[to] -= 1
			forest[to] = append(forest[to], idx)
			forest[idx] = append(forest[idx], to)

			if data.in[to] > 1 {
				continue
			}

			qu.push(to)
			v[to] = true
		}
	}

	var dfs func(idx int)
	dfs = func(idx int) {
		loop = append(loop, idx)

		for to := range data.g[idx] {
			if v[to] {
				continue
			}

			v[to] = true
			dfs(to)
		}
	}

	for i := 0; i < N; i++ {
		if v[i] {
			continue
		}

		v[i] = true
		dfs(i)
		break
	}
}
