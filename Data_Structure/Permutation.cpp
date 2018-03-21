struct Permutation{
	vector<int> A;
	
	Permutation(){}
	Permutation(size_t n){A.assign(n, 0);}
	size_t size() const{return A.size();}
	inline const int &operator[](int k) const{return A.at(k);}
	inline int &operator[](int k){return A.at(k);}
	Permutation operator*(const Permutation B){
		Permutation C(size());
		for(int i = 0; i < size(); i++) C[i] = B[A[i]];
		return C;
	}
	Permutation operator*=(const Permutation B){
		return *this = *this * B;
	}
	Permutation operator^(long long n){
		Permutation B(size());
		while(n){
			if(n & 1) B *= *this;
			*this *= *this;
			n >>= 1;
		}
		
		return B;
	}
	Permutation operator^=(long long n){
		return *this = *this^n;
	}
};
