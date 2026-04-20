class MinStack {
    struct StackData {
        int data;
        int minVal;
    };

public:
    MinStack() {
        mTop = 0;
        mSize = 0;
    }

    ~MinStack() {
        delete[] mData;
    }
    // copy constructor
    MinStack(const MinStack& other) = delete;
    // copy assignment operator
    MinStack& operator=(const MinStack& other) = delete;
    // move constructor
    MinStack(MinStack&& other) = delete;
    // move assignment operator
    MinStack& operator=(MinStack&& other) = delete;
    
    void push(int val) {
        if (isEmpty()) {
            mSize = 1;
            mTop = 1;
            mData = new StackData[mSize];
            mData[0] = {val, val};
            return;
        }
        
        if (isFull()) {
            int oldSize = mSize;
            mSize *= 2;
            StackData* tmp = mData;
            mData = new StackData[mSize];
            for (int i = 0; i < oldSize; ++i) {
                mData[i] = tmp[i];
            }
            delete[] tmp;
        }
        int minVal = std::min(mData[mTop-1].minVal, val);
        mData[mTop++] = {val, minVal};
    }
    
    void pop() {
        mTop--;
    }
    
    int top() {
        return mData[mTop-1].data;
    }
    
    int getMin() {
        return mData[mTop-1].minVal;
    }

private:
    bool isEmpty() {
        return mTop == 0;
    }

    bool isFull() {
        return mTop == mSize;
    }

    int mTop;
    int mSize;
    StackData* mData;
};