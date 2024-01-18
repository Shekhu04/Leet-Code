	class MinStack {
	public:
		stack<int>s,minn;
		void push(int val) {
			s.push(val); // push val in stack

			if(minn.size()==0 || val<=minn.top()){//push in when empty or lesser than current minElement
				minn.push(val);
			}
		}

		void pop() {

			if(minn.top() == s.top())//pop when last element was min element 
				minn.pop();
			s.pop();
		}

		int top() {//return top of stack
			return s.top();
		}

		int getMin() {//return top of minKeeper
			return minn.top();
		}
	};