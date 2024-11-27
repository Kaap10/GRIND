#include<bits/stdc++.h>
using namespace std;

class Queue {
public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int size){
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }

    void pushFront(int val) {
        if((front==0 && rear = size-1) || (rear = front-1)) {
            cout << "Overflow" << endl;
            return;
        } 
        else if(front == -1 && rear == -1) {
            front++;
            rear++;
            arr[front] = val;
        }

        else if (front==1 && rear != size-1){
            front = size-1;
            arr[front] = val;
        }
        else {
            front--;
            arr[front] = val;
        }
    }

    void popFront() {

    }

    void pushBack(int size) {

    }

    void popBack() {

    }

    void print() {

    }
};