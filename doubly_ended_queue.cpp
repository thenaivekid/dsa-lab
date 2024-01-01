#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <vector>
using namespace std;

class Queue{
    private:
    static const int MAX_SIZE = 10;
        int top = -1, bottom = -1;
        int data[10];
    
    public:
        bool is_full(){
            return top == MAX_SIZE - 1;
        }

        bool is_empty(){
            return bottom > top;
        }
        void enqueue_from_top(int item){
            if(is_full()) cout << "full" << endl;
            else if(top == -1){
                top = bottom = 0;
                data[top] = item;
                cout << "Enqueued from top at first: " << item << endl;
            }
            else{
                top++;
                data[top] = item;
                cout << "Enqueued: " << item << endl;
            }
        }

        int dequeue_from_bottom(){
            if(is_empty()) cout << "empty" << endl;
            else{
                cout << "dequeued: " << data[bottom] << endl;
                return data[bottom++];
            }
        }

        void enqueue_from_buttom(int item){
            if(bottom == 0) cout << "can't enqueue at bottom" << endl;
            else{
                cout << "bottom:" << bottom << endl;
                bottom--;
                data[bottom] = item;
                cout << "Enqueued from bottom: " << item << endl;
            }
        }

        int dequeue_from_top(){
            if(is_empty()) cout << "empty" << endl;
            else{
                cout << "dequeued from top: " << data[top] << endl;
                return data[top--];
            }
        }

        void print(){
            for (int i = bottom; i <= top; ++i) {
                cout << data[i] << " ";
            }
            cout << endl;
        }

        int length(){
            return top - bottom + 1;
        }
};

int main(){
    Queue q;
    q.enqueue_from_top(5);
    q.enqueue_from_top(7);
    q.dequeue_from_bottom();
    q.dequeue_from_bottom();
    q.enqueue_from_top(39);
    q.enqueue_from_top(9);
    q.enqueue_from_top(10);
    q.enqueue_from_buttom(6);
    q.enqueue_from_buttom(37);
    q.enqueue_from_buttom(38);
    q.print();
    // q.enqueue_from_top(40);
    // q.enqueue_from_top(41);
    // q.enqueue_from_top(42);
    // q.enqueue_from_top(6);
    // q.enqueue_from_top(6);
    // q.print();
    // cout << "length: " << q.length() << endl;
    // for (int i = 0; i < 12; ++i) {
    //     q.dequeue_from_bottom();
    // }
    // q.print();
    // cout << "length: " << q.length() << endl;

    return 0;
}