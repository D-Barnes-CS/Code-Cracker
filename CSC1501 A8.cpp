// CSC 1501 A8
//

#include <iostream>
using std::cout; using std::cin; using std::endl;
#include <string>
using std::string;

string uppercase(char c, int k) {
    //checking for uppercase value and ensuring we start back at the beginning when reaching "Z"
    if (c + k <= 90) {
        char num = c + k;
        string newC(1, num);
        return newC;
    }
    else {
        char num = ((c - 26) + k);
        string newC(1, num);
        return newC;
    }
}

string lowercase(char c, int k) {
    //checking for lowecase value and ensuring we start back at the beginning when reaching "z"
    if (c + k <= 122) {
        char num = c + k;
        string newC(1, num);
        return newC;
    }
    else {
        char num = ((c - 26) + k);
        string newC(1, num);
        return newC;
    }
}


int main()
{
    //Forcing my input to not be changed(i thought of using a pointer here so that I wouldn't have to deep copy but I don't know how to also make it a const and have something else equal to pointer)
    //then having a temporary word that will change based off the replacement and then restart the program with the original input.
    int count = 0;
    while (count < 5) {
        string tempC; string tempW;
        getline(cin, tempW);
        const string input = tempW;
        for (int i = 1; i <= 26; i++) {
            cout << "Test case " << i << ": " << endl;
            for (int j = 0; j < input.size(); j++) {
                if ((int)input.at(j) <= 90 && (int)input.at(j) >= 65) {
                    tempW.replace(j, 1, uppercase(input[j], i));
                }
                else if ((int)input.at(j) <= 122 && (int)input.at(j) >= 97) {
                    tempW.replace(j, 1, lowercase(input[j], i));
                }
            }
            cout << tempW << endl;
        }
        count++;
    }
}

