double calc(double t) {
	double ret = 0;
	
	return ret;
}

double ternary() {
	double left = -1e9, right = 1e9;

	for(int i = 0; i < 100; i++) {
		double ml = (left + left + right) / 3.0;
		double mr = (left + right + right) / 3.0;

		if(calc(ml) <= calc(mr)) {
			right = mr;
		} else {
			left = ml;
		}
	}

	return (left + right) / 2;
}

//Integer
int calc(int t) {
	int ret = 0;
	
	return ret;
}

int ternary() {
	int left = -1e9, right = 1e9;
	
	while(abs(left - right) > 1) {
		int mid = (left + right) / 2;
		
		if(calc(mid) <= calc(mid + 1)) right = mid;
		else left = mid;
	}
	
	return right;
}
