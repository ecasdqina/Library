template<typename T>
class Stackcats {
	std::stack<T> stack_1, stack_2;
	
	private:
	void rolling() {
		if(!stack_2.empty()) return;
		while(!stack_1.empty()) {
			stack_2.push(stack_1.top());
			stack_1.pop();
		}
	}
	public:
	Stackcats() {
		stack_1 = std::stack<T>();
		stack_2 = std::stack<T>();
	}
	void push(T x) {
		stack_1.push(x);
	}
	T front() {
		if(empty()) return T{};
		if(!stack_2.empty()) {
			return stack_2.top();
		}
		rolling();
		return stack_2.top();
	}
	void pop() {
		if(empty()) return;
		if(!stack_2.empty()) {
			stack_2.pop();
			return;
		}
		rolling();
		stack_2.pop();
	}
	void clear() {
		stack_1.clear();
		stack_2.clear();
	}
	bool empty() {
		return !(stack_1.size() + stack_2.size());
	}
	size_t size() {
		return stack_1.size() + stack_2.size();
	}
};
