#include <iostream>
using namespace std;




int main() {
    double a, b;
    char op;


    while (true) {
        cout << ">>>";
        cin >> a >> op >> b;

        if (op == '+') {
            cout << a + b<<endl;
        }
        else if (op == '-') {
            cout << a - b<<endl;
        }
        else if (op == '*') {
            cout << a * b<<endl;
        }
        else if (op == '/') {
            if (b == 0) {
                cout << "undefined \n";
                continue;
            }
            cout << a / b<<endl;
        }
    }
    return 0;
}