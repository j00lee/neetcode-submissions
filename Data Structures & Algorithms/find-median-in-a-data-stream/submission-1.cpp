class MedianFinder {
private: 
    double lmed;   // always > max of lower
    double rmed;   // always < min of higher
    int size;
    priority_queue<int> lower;
    priority_queue<int, vector<int>, greater<int>> higher;

public:
    MedianFinder() {
        size = 0;
    }
    
    void addNum(int num) {
        printf("adding num: %d\n", num);
        double median;
        if (size == 0) lmed = num;
        else if (size == 1) {
            if (num > lmed) { 
                rmed = num;
                printf("lmed: %f, rmed: %f\n", lmed, rmed);
            } else {
                rmed = lmed;
                lmed = num;
                printf("lmed: %f, rmed: %f\n", lmed, rmed);
            }
        } 
        else if (size % 2 == 0) {    // size is even
            median = (lmed + rmed) / 2;
            printf("case is EVEN median is: %f\n", median);
            if (num > median) {
                // put num in the higher and rebalance
                printf("adding nuber greater than median\n");
                higher.push(std::max(rmed, (double)num));
                lower.push(lmed);
                lmed = std::min(rmed, (double)num);
            } else if (num == median) {
                higher.push(rmed);
                lower.push(lmed);
                lmed = num;
            } else {
                lower.push(num);
                higher.push(rmed);
            }
        } else {    // size is odd
            median = lmed;
            if (num > median) {
                higher.push(num);
                int top = higher.top();
                higher.pop();
                rmed = top;
            } else if (num == median) {
                rmed = num;
            } else {
                lower.push(num);
                int top = lower.top();
                lower.pop();
                rmed = lmed;
                lmed = top;
            }
        }
        size++;
    }
    
    double findMedian() {
        printf("lmed: %f, rmed: %f\n", lmed, rmed);
        if (size % 2 == 0) return (lmed + rmed) / 2;
        else return lmed;
    }
};
