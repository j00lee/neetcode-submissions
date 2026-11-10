class MinStack {
    private: 
        int min_elem;
        int length;
        vector<int> ints = {};
        vector<int> min_ints = {};

    public:
        MinStack() {
            length = 0;
        }
        
        void push(int val) {
            if (length == 0 or val <= min_elem) {
                min_elem = val;
                min_ints.push_back(val);
            }
            ints.push_back(val);
            length++;
        }
        
        void pop() {
            if (ints[length - 1] == min_elem) {
                min_ints.pop_back();
                min_elem = min_ints[min_ints.size()-1];
            }
            ints.pop_back();
            length--;
        }
        
        int top() {
            return ints[length - 1];
        }
        
        int getMin() {
            return min_elem;
        }
    };
