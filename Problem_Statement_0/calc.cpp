
#include <iostream>
#include <vector>
#include <string>

using namespace std;

double ln(double a) {
    int terms = 30000;
    double y = (a - 1) / (a + 1);
    double yPower = y;
    double result = 0.0;

    for (int n = 1; n <= terms; n += 2) {
        result += yPower / n;
        yPower = yPower * y * y;
    }
    return 2 * result;
}

double log(double a){
double result= ln(a)/ln(10);
return result;
}

double exponential(double x) {
    int terms = 30000;
    double result = 1.0;
    double term = 1.0;
    for (int i = 1; i <= terms; i++) {
        term *= x / i;
        result += term;
    }
    return result;
}

double Pow(double base, double exponent) {
    return exponential(exponent * ln(base));
}

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

        if(exp.substr(0,3) == "log"){
            string explog;
            string numinl10;
            double numinlog;
          
            for (char c : exp)
            {
                if (c == 'l' || c == 'o'|| c == 'g')
                {
                    explog = explog + c;
                }
                else
                {
                    numinl10 = numinl10 + c;
                }
            }
            numinlog = stold(numinl10);
            if (explog == "log")
            {
                if (numinlog < 0)
                {
                    cout << "Error" << endl;
                }
                else
                {
                    cout << log(numinlog) << endl;
                }
            }
        }
        else if(exp.substr(0,2) == "ln"){
            string expln;
            string numinle;
            double numinln;
          
            for (char c : exp)
            {
                if (c == 'l' || c == 'n')
                {
                    expln = expln + c;
                }
                else
                {
                    numinle = numinle + c;
                }
            }
            numinln = stold(numinle);
            if (expln == "ln")
            {
                if (numinln < 0)
                {
                    cout << "Error" << endl;
                }
                else
                {
                    cout << ln(numinln) << endl;
                }
            }
        }
         else if (exp.substr(0,4) == "sqrt")
        {
            string expsqrt;
            string numinroot;
            double numinsqrt;

            for (char c : exp)
            {
                if (c == 's' || c == 'q' || c == 'r' || c == 't')
                {
                    expsqrt = expsqrt + c;
                }
                else
                {
                    numinroot = numinroot + c;
                }
            }
            numinsqrt = stold(numinroot);

            if (expsqrt == "sqrt")
            {
                if (numinsqrt < 0)
                {
                    cout << "Error" << endl;
                }
                else
                {
                    cout << sqrt(numinsqrt) << endl;
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
                if (c != '+' && c != '-' && c != '=' && c != '*' && c != '/'&& c!= '^')
                {
                    numstr = numstr + c;
                }
                else if (c == '.')
                {
                    numstr = numstr + c;
                }
                else if (c == '+' || c == '-' || c == '=' || c == '*' || c == '/'|| c== '^')
                {
                    numbers.push_back(stold(numstr));
                    ops.push_back(c);
                    numstr = "";
                }
            }
            ops.pop_back();


            // vectors to answer
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
                else if (ops[i] == '^')
                {
                    ans = Pow(ans , numbers[i + 1]);
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}