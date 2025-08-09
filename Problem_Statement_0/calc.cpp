
#include <iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
    while (true) {
        string ex;
        cout << "-->";
        getline(cin, ex);
        vector<long double> numbers;
        vector<char> ops;
        string numstr;
        
        for (char c : ex) {
            if (c != '+' && c != '-' && c != '=' && c != '*' && c != '/') {
                numstr = numstr + c;
            }
            else if (c == '+' || c == '-' || c == '=' || c == '*' || c == '/') {
                numbers.push_back(stoll(numstr));
                ops.push_back(c);
                numstr = "";
            }

        }
        ops.pop_back();

        long double ans = numbers[0];

        for (int i = 0; i < ops.size(); i++) {
            if (ops[i] == '+') {
                ans = ans + numbers[i + 1];
            }
            else if (ops[i] == '-') {
                ans = ans - numbers[i + 1];
            }
            else if (ops[i] == '*') {
                ans = ans * numbers[i + 1];
            }
            else if (ops[i] == '/') {
                ans = ans / numbers[i + 1];
            }
        }
        cout << ans<<endl;

    }
    return 0;
}