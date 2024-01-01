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
        int top = -1, bottom = 0;
        int data[10];
    
    public:
        bool is_full(){
            return top == MAX_SIZE - 1;
        }

        bool is_empty(){
            return bottom > top;
        }
        void enqueue(int item){
            if(is_full()) cout << "full" << endl;
            else{
                top++;
                data[top] = item;
                cout << "Enqueued: " << item << endl;
            }
        }

        int dequeue(){
            if(is_empty()) cout << "empty" << endl;
            else{
                cout << "dequeued: " << data[bottom] << endl;
                return data[bottom++];
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
    q.enqueue(5);
    q.enqueue(7);
    q.enqueue(6);
    q.enqueue(6);
    q.enqueue(6);
    q.enqueue(6);
    q.enqueue(6);
    q.enqueue(6);
    q.enqueue(6);
    q.enqueue(9);
    q.enqueue(10);
    q.enqueue(6);
    q.enqueue(6);
    q.enqueue(6);
    q.enqueue(6);
    q.enqueue(6);
    q.print();
    cout << "length: " << q.length() << endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.print();
    cout << "length: " << q.length() << endl;

    return 0;
}