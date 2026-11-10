class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // Create zipped and sorted list of cars
        vector<tuple<int,int>> cars = {};
        for (int i = 0; i < position.size(); i++) {
            cars.push_back(make_tuple(position[i], speed[i]));
        }
        sort(cars.begin(), cars.end());

        stack<tuple<int,int>> fleets;
        for (auto car: cars) {
            printf("Car\n");
            if (fleets.empty()) {
                printf("Fleets is empty\n");
            }
            int pos = get<0>(car);
            int spe = get<1>(car);

            while (!fleets.empty() and will_catch_up(fleets.top(), car, target)) {
                // car is the same fleet as prev
                printf("merging car: %d,%d with car: %d,%d\n", get<0>(car), get<1>(car), get<0>(fleets.top()), get<1>(fleets.top()));
                fleets.pop();
            }

            // Push car to stack
            fleets.push(car);
        }

        return fleets.size();
    }

    bool will_catch_up(tuple<int,int> pursuing, tuple<int,int> leading, int target) {
        // car: y = (speed)x + (position)
        // Find intersection of two cars
        // Will catch up if intersection is after position of leading, but before target
        float b1 = get<0>(pursuing);
        float b2 = get<0>(leading);
        float m1 = get<1>(pursuing);
        float m2 = get<1>(leading);
        printf("Pursuing car: y = %dx+%d\n", m1, b1);
        printf("Leading car: y = %dx+%d\n", m2, b2);

        if (m1 == m2) {
            printf("Cars have same speed\n");
            return false;
        }
        float x = (b2 - b1) / (m1 - m2);
        float y = m1 * x + b1;
        printf("Car will catch up at %f: \n", y);
        if (b2 <= y and y <= target) {
            printf("b2: %d target: %d\n", b2, target);
            return true;
        } else {
            return false;
        }
    }
};
