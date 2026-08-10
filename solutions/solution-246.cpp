#include <array>
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases, length;
    cin >> testCases >> length;

    while (testCases--) {
        string composition;
        cin >> composition;

        array<int, 26> frequency{};
        for (char letter : composition) {
            ++frequency[letter - 'a'];
        }

        bool alternates = true;
        for (int index = 1; index < length; ++index) {
            bool previousIsHeavy = frequency[composition[index - 1] - 'a'] > 1;
            bool currentIsHeavy = frequency[composition[index] - 'a'] > 1;
            if (previousIsHeavy == currentIsHeavy) {
                alternates = false;
                break;
            }
        }

        cout << (alternates ? 'T' : 'F') << '\n';
    }
}
