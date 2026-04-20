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
            mData[0] = val;
            return;
        }
        
        if (isFull()) {
            int oldSize = mSize;
            mSize *= 2;
            int* tmp = mData;
            mData = new int[mSize];
            for (int i = 0; i < oldSize; ++i) {
                mData[i] = tmp[i];
            }
            delete[] tmp;
        }

        mData[mTop++] = val;
        if (val < mMinVal) mMinVal = val;
    }
    
    void pop() {
        int poppedVal = mData[mTop-1];
        mTop--;
        cout << "Popping: " << poppedVal << endl;
        if (poppedVal == mMinVal) {
            if (!isEmpty()) {
                int minVal = mData[0];
                for (int i = 1; i < mTop; ++i) {
                    if (mData[i] < minVal) minVal = mData[i];
                }
                mMinVal = minVal;
            }
        }
    }
    
    int top() {
        if (!isEmpty()) {
            cout << "Top: " << mData[mTop-1] << endl;
            return mData[mTop-1];
        }
    }
    
    int getMin() {
        cout << "Min: " << mMinVal << endl;
        return mMinVal;
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
};