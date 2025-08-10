
#include <iostream>
#include <vector>
#include <string>

using namespace std;

double sqrt(double n)
{
    int precision = 6;
    int a = n;
    int start{};
    int end = a;
    double ans{};

    // Integer
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if ((double)mid * mid <= n)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    // Decimal
    double deci = 0.1;
    for (int i = 0; i < precision; i++)
    {
        while ((ans + deci) * (ans + deci) <= n)
        {
            ans += deci;
        }
        deci /= 10;
    }

    return ans;
}

int main()
{
    while (true)
    {
        string exp;
        cout << "-->";
        getline(cin, exp);

        if (exp[0] == 's')
        {
            string expression;
            string numm;
            double num;

            for (char c : exp)
            {
                if (c == 's' || c == 'q' || c == 'r' || c == 't')
                {
                    expression = expression + c;
                }
                else
                {
                    numm = numm + c;
                }
            }
            num = stoll(numm);

            if (expression == "sqrt")
            {
                if (num < 0)
                {
                    cout << "Error" << endl;
                }
                else
                {
                    cout << sqrt(num) << endl;
                }
            }
        }
        else
        {
            string ex = exp;
            vector<long double> numbers;
            vector<char> ops;
            string numstr;

            for (char c : ex)
            {
                if (c != '+' && c != '-' && c != '=' && c != '*' && c != '/')
                {
                    numstr = numstr + c;
                }
                else if (c == '+' || c == '-' || c == '=' || c == '*' || c == '/')
                {
                    numbers.push_back(stoll(numstr));
                    ops.push_back(c);
                    numstr = "";
                }
            }
            ops.pop_back();

            long double ans = numbers[0];

            for (int i = 0; i < ops.size(); i++)
            {
                if (ops[i] == '+')
                {
                    ans = ans + numbers[i + 1];
                }
                else if (ops[i] == '-')
                {
                    ans = ans - numbers[i + 1];
                }
                else if (ops[i] == '*')
                {
                    ans = ans * numbers[i + 1];
                }
                else if (ops[i] == '/')
                {
                    ans = ans / numbers[i + 1];
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}