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

