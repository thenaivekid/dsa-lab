#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <vector>
using namespace std;

class CircularQueue{
    private:
    static const int MAX_SIZE = 10;
        int top = -1, bottom = -1;
        int data[10];
    
    public:
        bool is_full(){
            if ((bottom == 0 && top == MAX_SIZE - 1) || bottom == (top + 1)%MAX_SIZE) return true;
            return false; 
        }

        bool is_empty(){
            if(bottom == -1) return true;
            return false;
        }
        void enqueue(int item){
            if(is_full()) cout << "full" << endl;
            else if (top == -1){
                top = bottom = 0;
                data[top] = item;
                cout << "Enqueued: " << item << endl;
            }
            else{
                top++;
                top %= MAX_SIZE;
                data[top] = item;
                cout << "Enqueued: " << item << endl;
            }
        }

        int dequeue(){
            if(is_empty()) cout << "empty" << endl;
            else{
                cout << "dequeued: " << data[bottom] << endl;
                int ret_val = data[bottom++];
                bottom %= MAX_SIZE;
                return ret_val;
            }
        }

        void print() const {
            if (bottom == -1) {
                std::cout << "\nQueue is Empty" << std::endl;
                return;
            }

            std::cout << "Elements in Circular Queue are: ";
            if (top >= bottom) {
                for (int i = bottom; i <= top; i++)
                    std::cout << data[i] << " ";
            } else {
                for (int i = bottom; i < MAX_SIZE; i++)
                    std::cout << data[i] << " ";

                for (int i = 0; i <= top; i++)
                    std::cout << data[i] << " ";
            }
            std::cout << std::endl;
        }
 



        int get_top(){
            return top;
        }

        int get_bottom(){
            return bottom;
        }
};

int main(){
    CircularQueue q;
    q.enqueue(5);
    q.enqueue(7);
    q.enqueue(6);
    q.enqueue(34);
    q.enqueue(35);
    q.enqueue(36);
    q.dequeue();
    q.dequeue();
    cout << "bottom: " << q.get_bottom() << " top: " << q.get_top() << endl;
    cout << "printing queue: " << endl; q.print();
    q.enqueue(37);
    q.enqueue(38);
    q.enqueue(39);
    q.enqueue(9);
    q.enqueue(10);
    q.enqueue(40);
    q.enqueue(41);
    q.enqueue(42);
    q.enqueue(6);
    q.enqueue(6);
    cout << "printing queue: " << endl; q.print();

    for (int i = 0; i < 12; i++){
        if(i > 9) cout << "empty" << endl;
        q.dequeue();  
    }
    cout << "printing queue: "; q.print();
    cout << "bottom: " << q.get_bottom() << " top: " << q.get_top() << endl;


    return 0;
}