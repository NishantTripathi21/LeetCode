class MyCircularQueue {
    int *arr;
    int front;
    int size;
    int rear;

public:
    MyCircularQueue(int k) {
        arr=new int[k];
        this->front=-1;
        this->rear=-1;
        this->size=k;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        else{
            if(front == -1 && rear == -1){
                //first element
                front++;
                rear++;
                arr[rear]=value;
            }
            else if (rear == size - 1 & front != 0){
                rear = 0;
                arr[rear] = value;
            }
        // normal pushing
            else{
                rear++;
                arr[rear] = value;
            }
            return true;
        }
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        else{
            if(rear==front){
                //single element
                arr[rear]=-1;
                rear=-1;
                front=-1;
            }
            else if(front==size-1){
                //circular nature
                arr[front]=-1;
                front=0;
            }
            else{
                arr[front]=-1;
                this->front=this->front+1;
            }
            return true;
        }
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return arr[front];
    }
    
    int Rear() {
         if (isEmpty()) return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        cout<<"front:"<<front<<"rear:"<<rear<<endl;
        if(front==-1 && rear==-1)return true;
        return false;
        
    }
    
    bool isFull() {
        cout<<"front:"<<front<<"rear:"<<rear<<endl;
        if ((front == 0 && rear == size - 1) || (rear == front - 1)) return true;
        else {return false;}
        
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
