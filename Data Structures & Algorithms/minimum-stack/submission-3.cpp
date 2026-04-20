class MinStack {
    struct StackData {
        int data;
        int minVal;
    };

public:
    MinStack() : mTop(0), mSize(2), mData(nullptr) {}

    ~MinStack() {
        delete[] mData;
    }
    // copy constructor
    MinStack(const MinStack& other) : mSize(other.mSize), mTop(other.mTop), mData(nullptr) {
        if (other.mData) {
            mData = new StackData[mSize];
            for (int i = 0; i < mSize; ++i) {
                mData[i] = other.mData[i];
            }
        }
    }
    // copy assignment operator
    MinStack& operator=(const MinStack& other) {
        if (this == &other) return *this;

        StackData* newData = nullptr;
        if (other.mData) {
            newData = new StackData[other.mSize];
            for (int i = 0; i < mSize; ++i) {
                mData[i] = other.mData[i];
            }
        }
        delete[] mData;
        mData = newData;        
        mSize = other.mSize;
        mTop = other.mTop;        

        return *this;
    }
    // move constructor
    MinStack(MinStack&& other) noexcept : mSize(other.mSize), mTop(other.mTop), mData(other.mData) {
        other.mSize = 0;
        other.mTop = 0;
        other.mData = nullptr;
    }
    // move assignment operator
    MinStack& operator=(MinStack&& other) noexcept {
        if (this == &other) return *this;

        delete[] mData;
        mSize = other.mSize;
        mTop = other.mTop;
        mData = other.mData;

        other.mData = nullptr;
        other.mSize = 0;
        other.mTop = 0;
        return *this;
    }
    
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