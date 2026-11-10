class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // Maintain a stack of monotonically decreasing elements by index
        // When we encounter a element which is larger than the previous,
        // continue to pop indices off the stack until every element in 
        // stack is greater than or equal to this element

        stack<int> indices;
        vector<int> result = {};
        for (int i = 0; i < temperatures.size(); i++) {
            result.push_back(0);
        }

        int prev = temperatures[0];
        for (int i = 0; i < temperatures.size(); i++) {
            printf("\nStack\n");
            print_stack(indices, temperatures);
            int curr = temperatures[i];
            if (curr <= prev) {
                printf("prev before pushing to stack: %d\n", prev);
                indices.push(i);
                prev = curr;
            } else {
                while (curr > prev) {
                    // pop from stack
                    int idx = indices.top();
                    indices.pop();
                    result[idx] = (i - idx);
                    if (indices.empty()) {
                        // printf("i: %d\n", i);
                        prev = curr;
                    } else {
                        prev = temperatures[indices.top()];
                        printf("at %d prev: %d\n", i, prev);
                    }
                }
                indices.push(i);
                prev = temperatures[indices.top()];
            }

            if (i == temperatures.size() - 1) {
                printf("stack at last index ");
                print_stack(indices, temperatures);
                printf("prev: %d", prev);
            }
        }
        return result;
    }

    void print_stack(stack<int> stk, vector<int>& temperatures) {
        while (!stk.empty()) {
            int i = stk.top();
            stk.pop();
            printf("%d ", temperatures[i]);
        }
        printf("\n");
    }
};
