#include <list>
using namespace std;
class MinStack {
public:
    list<int> nums;
    int topIdx;
    list<int> minValues;
    int minValue;
    MinStack() {
        this->topIdx = -1;
        this->minValue = -1;
    }
    
    void push(int val) {
        if (this->topIdx == -1) {
            this->topIdx = 0;
            this->minValue = val;
            this->nums.push_back(val);
            this->minValues.push_back(val);
        } else {
            this->topIdx++;
            if (val <= this->minValue) {
                this->minValue = val;
                this->minValues.push_back(val);
            }
            this->nums.push_back(val);
        }
    }
    
    void pop() {
        if (this->topIdx < 0) {
            return;
        } else {
            int backElement = this->nums.back();
            this->nums.pop_back();
            if (backElement == this->minValue) {
                this->minValues.pop_back();
                this->minValue = this->minValues.back();
            }
            this->topIdx--;
        }
    }
    
    int top() {
        return this->nums.back();
    }
    
    int getMin() {
        return this->minValue;
    }
};

int main() {
    MinStack* obj = new MinStack();
    obj->push(10);
    obj->pop();
    int param_3 = obj->top();
    int param_4 = obj->getMin();
    
}
