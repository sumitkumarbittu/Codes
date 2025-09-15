#include <iostream>
#include <string>
using namespace std;

const char cars[4] = {'A', 'B', 'M', 'V'};
int k, n;
int totalValid = 0;

bool isValid(const string &s) {
    int countKBlocks = 0;
    int len = s.length();

    for (int i = 0; i <= len - k; ++i) {
        bool match = true;
        for (int j = 1; j < k; ++j) {
            if (s[i + j] != s[i]) {
                match = false;
                break;
            }
        }
        if (match) {
            // Make sure it's exactly k (not part of longer segment)
            if ((i > 0 && s[i - 1] == s[i]) || (i + k < len && s[i + k] == s[i])) {
                continue;
            }
            countKBlocks++;
        }
    }
    return countKBlocks == 1;
}

void generate(string s) {
    if ((int)s.length() == n) {
        if (isValid(s)) totalValid++;
        return;
    }
    for (int i = 0; i < 4; ++i) {
        generate(s + cars[i]);
    }
}

int main() {
    cin >> k;
    n = k + 1;
    generate("");
    cout << totalValid << endl;
    return 0;
}
