//Problem link : https://leetcode.com/problems/roman-to-integer/description/

#include<iostream>
#include<unordered_map>
using namespace std;

//Function to convert roman numeral string to an integer
int romanToInt(string s) {
    //Mapping of Roman numeral characters to their integer values
    unordered_map<char, int> roman = {
        {'I', 1}, {'V', 5}, {'X', 10},
        {'L', 50}, {'C', 100}, {'D', 500},
        {'M', 1000}
    };

    int result = 0; //Stores the final integer result
    int prevValue = 0; //Tracks the previous numeral's value for comparison

    //Iterate through the string from right to left
    for (int i = s.length() - 1; i >= 0; --i) {
        int currentValue = roman[s[i]]; //Get the integer value of the current Roman numeral

        // If the current value is smaller than the previous value, subtract it (e.g., Iv -> 4)
        if(currentValue < prevValue) {
            result -= currentValue;
        } else { // Otherwise , add it to the result
            result+= currentValue;
        }

        prevValue = currentValue; // Update prev value for next iteration

    }

    return result; //Return the final computed integer value
}

int main() {
    string s;
    cout << "Enter a Roman numeral: "; //Prompt user for input
    cin>> s; //Read input string
    cout << "Integer value: "<<romanToInt(s) << endl; //Convert and print result
    return 0;
}