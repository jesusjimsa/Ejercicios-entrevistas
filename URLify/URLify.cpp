/*
    Write a method to replace all spaces in a string with `%20`. You may assume that the string has sufficient space at
    the end to hold the additional characters, and that you are given the "true" length of thr string.

    Example
    Input: "Mr John Smith       ", 13
    Output: "Mr%20John%20Smith"
*/

#include <iostream>
#include <string>

using namespace std;

string trim_end(string input_str) {
    int str_size = input_str.size();

    for (int i = str_size - 1; i > 0; i--) {
        if (input_str[i] == ' ') {
            input_str.erase(i);
        }
        else {
            break;
        }
    }

    return input_str;
}

string trim_start(string input_str) {
    int str_size = input_str.size();

    for (int i = 0; i < str_size; i++) {
        if (input_str[i] == ' ') {
            input_str.erase(i);
        }
        else {
            break;
        }
    }

    return input_str;
}

string trim(string input_str) {
    string result;

    result = trim_start(input_str);
    result = trim_end(result);

    return result;
}

string URLify(string input_str) {
    string result = trim(input_str);


}

int main() {
    cout << URLify("Mr John Smith       ") << endl;
}
