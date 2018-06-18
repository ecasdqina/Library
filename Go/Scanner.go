import (
	_ "fmt"
	"bufio"
	"os"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)

func nextInt() int {
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())

	if e != nil {
		panic(e)
	}

	return i
}

func nextInt64() int64 {
	sc.Scan()
	i, e := strconv.ParseInt(sc.Text(), 10, 64)

	if e != nil {
		panic(e)
	}

	return i
}

func nextFloat() float32 {
	f, e := strconv.ParseFloat(sc.Text(), 32)

	if e != nil {
		panic(e)
	}

	return float32(f)
}

func nextFloat64() float64 {
	f, e := strconv.ParseFloat(sc.Text(), 64)

	if e != nil {
		panic(e)
	}

	return f	
}

func nextBool() bool {
	sc.Scan()
	b, e := strconv.ParseBool(sc.Text())

	if e != nil {
		panic(e)
	}

	return b
}

func nextStr() string {
	sc.Scan()

	return sc.Text()
}
