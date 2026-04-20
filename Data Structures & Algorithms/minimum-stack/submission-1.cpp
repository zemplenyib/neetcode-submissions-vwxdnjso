class MinStack {
public:
    MinStack() {
        mTop = 0;
        mSize = 0;
        mMinVal = 0;
    }

    ~MinStack() {
        while(!isEmpty()) pop();
    }
    
    void push(int val) {
        if (isEmpty()) {
            mSize = 1;
            mTop = 1;
            mMinVal = val;
            mData = new int[mSize];
            mMinData = new int[mSize];
            mData[0] = val;
            mMinData[0] = val;
            return;
        }
        
        if (isFull()) {
            int oldSize = mSize;
            mSize *= 2;
            int* tmpData = mData;
            int* tmpMinData = mMinData;
            mData = new int[mSize];
            mMinData = new int[mSize];
            for (int i = 0; i < oldSize; ++i) {
                mData[i] = tmpData[i];
                mMinData[i] = tmpMinData[i];
            }
            delete[] tmpData;
            delete[] tmpMinData;
        }
        int minVal = std::min(mMinData[mTop-1], val);
        mMinData[mTop] = minVal;
        mData[mTop++] = val;
    }
    
    void pop() {
        mTop--;
    }
    
    int top() {
        return mData[mTop-1];
    }
    
    int getMin() {
        return mMinData[mTop-1];
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
    int mMinVal;
    int* mData;
    int* mMinData;
};