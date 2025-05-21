#include<iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int y=x,n=0,c;
        if(x==0)
        return true;
        while(y>0)
        {
            c=y%10;
            n*=10;
            n+=c;
            y/=10;
        }
        if(n==x)
        return true;
        return false;
    }
};

int main()
{
    Solution a;
    cout<<a.isPalindrome(121);
}






/*

#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter a two-digit number: ";
    cin >> num;

    if(num < 10 || num > 99) {
        cout << "Please enter a valid two-digit number." << endl;
        return 1;
    }

    int digit1 = num / 10; // First digit
    int digit2 = num % 10; // Second digit

    int sumDigits = digit1 + digit2;
    int productDigits = digit1 * digit2;


    if (sumDigits + productDigits == num) {
        cout << "Special 2-digit number" << endl;
    } else {
        cout << "Not a Special 2-digit number" << endl;
    }

    return 0;
}

*/







/*

#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    int charCount[256] = {0};
    int vowelCount = 0;
    int uppercaseCount = 0;
    int lowercaseCount = 0;
    int digitCount = 0;
    int totalCharacterCount = 0;

    cout << "Enter a string: ";
    getline(cin, input);

    for (char ch : input) {
        charCount[static_cast<unsigned char>(ch)]++;  // Count occurrences of each character

        char lowerCh = (ch >= 'A' && ch <= 'Z') ? ch + 32 : ch; // Convert to lowercase if it's uppercase
        if (lowerCh == 'a' || lowerCh == 'e' || lowerCh == 'i' || lowerCh == 'o' || lowerCh == 'u') {
            vowelCount++;
        }


        if (ch >= 'A' && ch <= 'Z') {
            uppercaseCount++;
        } else if (ch >= 'a' && ch <= 'z') {
            lowercaseCount++;
        }

        if (ch >= '0' && ch <= '9') {
            digitCount++;
        }

        totalCharacterCount++;
    }


    cout << "\nCharacter occurrences:\n";
    for (int i = 0; i < 256; i++) {
        if (charCount[i] > 0) {
            cout << static_cast<char>(i) << ": " << charCount[i] << '\n';
        }
    }

    cout << "\nNumber of vowels: " << vowelCount << '\n';
    cout << "Number of uppercase letters: " << uppercaseCount << '\n';
    cout << "Number of lowercase letters: " << lowercaseCount << '\n';
    cout << "Number of digits: " << digitCount << '\n';
    cout << "Total number of characters: " << totalCharacterCount << '\n';

    return 0;
}

*/










/*

#include <iostream>
#include <cmath> 

using namespace std;

int main() {
    char productType;
    float purchaseAmount, discount = 0.0, netPayment;
    int age;

    cout << "Enter product type (F for Food, C for Cloth): ";
    cin >> productType;

    cout << "Enter purchase amount: ";
    cin >> purchaseAmount;

    if (productType == 'C' || productType == 'c') {
        cout << "Enter age: ";
        cin >> age;
    }

    switch (productType) {
        case 'F': 
        case 'f':
            if (purchaseAmount >= 5000) {
                discount = 0.50 * purchaseAmount;
            } else if (purchaseAmount >= 2000) {
                discount = 0.20 * purchaseAmount;
            } else if (purchaseAmount >= 500) {
                discount = 0.10 * purchaseAmount;
            } else {
                discount = 0;
            }
            break;

        case 'C': 
        case 'c':
            if (age >= 40) {
                if (purchaseAmount >= 5000) {
                    discount = 0.50 * purchaseAmount;
                } else if (purchaseAmount >= 2000) {
                    discount = 0.20 * purchaseAmount;
                } else if (purchaseAmount >= 500) {
                    discount = 0.10 * purchaseAmount;
                } else {
                    discount = 0;
                }
            } else if (age >= 20) {
                if (purchaseAmount >= 5000) {
                    discount = 0.30 * purchaseAmount;
                } else if (purchaseAmount >= 2000) {
                    discount = 0.15 * purchaseAmount;
                } else if (purchaseAmount >= 500) {
                    discount = 0.10 * purchaseAmount;
                } else {
                    discount = 0;
                }
            } else {
                if (purchaseAmount >= 2500) {
                    discount = 0.60 * purchaseAmount;
                } else {
                    discount = 0;
                }
            }
            break;

        default:
            cout << "Invalid product type!" << endl;
            return 1;
    }

    netPayment = purchaseAmount - discount;

    cout << "Product Type: " << productType << endl;
    cout << "Purchase Amount: $" << round(purchaseAmount * 100) / 100 << endl;
    cout << "Discount: $" << round(discount * 100) / 100 << endl;
    cout << "Net Payment: $" << round(netPayment * 100) / 100 << endl;

    return 0;
}

*/