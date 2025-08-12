#include <iostream>
#include <string>
using namespace std;

//encode
string encode(string message, int shift) {
    string result = "";
    shift = shift % 26;

    for (int i = 0; i < message.size(); i++) {
        char c = message[i];

        if (c >= 'A' && c <= 'Z') {
            result += char((c - 'A' + shift + 26) % 26 + 'A');
        }
        else if (c >= 'a' && c <= 'z') {
            result += char((c - 'a' + shift + 26) % 26 + 'a');
        }
        else {
            result += c;
        }
    }
    return result;
}

//decode
string decode(string message, int shift) {
    return encode(message, -shift);
}

int main()
{
    while (true) {

        cout << "*** Caesar Cipher Challenge ***\n" << endl;

        // encode or decode
        cout << "-> press 1 to encode" << endl;
        cout << "-> press 2 to decode" << endl <<endl<< ">>>";

        string input;
        int shift;
        int a{};
        cin >> a;
        cin.ignore(1000, '\n');

        while (a != 1 && a != 2) {
            cout <<endl<< "Read the text carefully" << endl;
            cout << "-> Press 1 to encode" << endl;
            cout << "-> Press 2 to decode" << endl << ">>>";
            cin >> a;
            cin.ignore(1000, '\n');
        }

        // Take input
        cout<< endl << "-> enter the message: ";
        getline(cin, input);
        cout << "-> enter shift: ";
        cin >> shift;

        // Give Output
        if (a == 1) {
            cout << ">>> encode = " << encode(input, shift) << endl;
        }
        else if (a == 2) {
            cout << ">>> decode = " << decode(input, shift) << endl;
        }
        cout << endl;
    }
    return 0;
}


