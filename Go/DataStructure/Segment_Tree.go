type SegmentTree struct {
	sz int
	seg []int64
}

func NewSegmentTree(N int) *SegmentTree {
	sz := 1
	for sz < N {
		sz *= 2
	}

	return &SegmentTree {
		sz : sz,
		seg : make([]int64, 2 * sz - 1),
	}
}

func (seg *SegmentTree) update(k int, x int64) {
	k += seg.sz - 1
	seg.seg[k] = x

	for k > 0 {
		k = (k - 1) / 2
		seg.seg[k] = seg.seg[2 * k + 1] + seg.seg[2 * k + 2]
	}
}

func (seg *SegmentTree) add(k int, x int64) {
	k += seg.sz - 1
	seg.seg[k] += x

	for k > 0 {
		k = (k - 1) / 2
		seg.seg[k] = seg.seg[2 * k + 1] + seg.seg[2 * k + 2]
	}
}

func (seg SegmentTree) _get(a, b, k, l, r int) int64 {
	if (b <= l) || (r <= a) {
		return 0
	} else if (a <= l) && (r <= b) {
		return seg.seg[k]
	}

	return seg._get(a, b, 2 * k + 1, l, (l + r) / 2) + seg._get(a, b, 2 * k + 2, (l + r) / 2, r)
}

func (seg SegmentTree) get(a, b int) int64 {
	return seg._get(a, b, 0, 0, seg.sz)
}
