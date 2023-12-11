#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <vector>
#define MAX_SIZE 10
using namespace std;

template <class T>
class Stack{
    private:
        int top = -1;
        // const int MAX_SIZE;
        T items[MAX_SIZE];
    
    public:
        void push(T item){
            if (top > MAX_SIZE){
                cout << "stack full" << endl;
            }
            items[++top] = item;
            cout << item << endl;
        }

        T pop(){
            if (top < 1){
                cout << "stack empty" << endl;
            }
            T temp = items[top--];
            return temp;
        }

        void print(){
            for(int i = 0; i < top + 1; i++){
                cout << items[i] << " ";
            }
        }
};

int main(){
    // cout << "Enter max size of the stack: ";
    // int max_size;

    // char type_d[10];
    // cout << "Enter data type for stack: ";
    // cin >> type_d;
    // cout << type_d;

    Stack <int> stack;
    while(1){
        cout << " choose 0 to push, 1 to pop and 2 to print: ";
        int temp;

        cin >> temp;
        if (temp == 0){
            int temp1;
            cout << "enter integer to push: ";
            cin >> temp1;
            stack.push(temp1);
        }
        else if (temp == 1){
        stack.pop();
        }
        else{
            stack.print();
            cout << endl;
        }
    }
    return 0;
}