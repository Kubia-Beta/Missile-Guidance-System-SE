// Hamming.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <unordered_map>
#include <memory>
#include <string>
using namespace std;

class HammingChannel {
private:
    string alpha, bravo, charlie; // A: I II III V, B: I III IV VI, C: II III IV VII
    int alphaCount, bravoCount, charlieCount, parityValue;

public:
    void SetChannels(vector<int> input);
    void SetCounts();
    void CheckConsistency();
};



/**
 * Finds the values of each sector within a hamming code, including a parity digit.
 *
 * Time: O(n)
 * Space: O(1)
 * @param vector<int> input, the vector we wish to check of size 8.
 * @return N/A
 */
void HammingChannel::SetChannels(vector<int> input) {
    alpha += to_string(input.at(0)); // A: I II III V
    alpha += to_string(input.at(1));
    alpha += to_string(input.at(2));
    alpha += to_string(input.at(4));
    bravo += to_string(input.at(0)); // B: I III IV VI
    bravo += to_string(input.at(2));
    bravo += to_string(input.at(3));
    bravo += to_string(input.at(5));
    charlie += to_string(input.at(1)); // C: II III IV VII
    charlie += to_string(input.at(2));
    charlie += to_string(input.at(3));
    charlie += to_string(input.at(6));
    parityValue = input.at(7); // Now make sure we have our parity check
}

void HammingChannel::SetCounts() {

}

void HammingChannel::CheckConsistency() {
    
}


int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
