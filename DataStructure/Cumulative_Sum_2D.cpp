template<typename T>
struct CumulativeSum2D{
	vector<vector<T>> data;
	
	CumulativeSum2D(int w, int h) : data(w + 1, vector<T>(h + 1, 0)) {}
	void update(int x, int y, T z){data[x + 1][y + 1] = z;} //0 - indexed
	void add(int x, int y, T z){data[x + 1][y + 1] += z;} //0 - indexed
	
	void build(){
		for(int i = 0; i < data.size() - 1; i++){
			for(int j = 0; j < data[0].size() - 1; j++){
				data[i + 1][j + 1] = data[i + 1][j] + data[i][j + 1] - data[i][j];
			}
		}
	}
	
	T get(int sx, int sy, int gx, int gy){ //1 - indexed
		return data[gx][gy] - data[sx - 1][gy] - data[gx][sy - 1] + data[sx - 1][sy - 1];
	}
	
	T get(int gx, int gy){ //1 - indexed
		return data[gx][gy];
	}
};
