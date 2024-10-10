#include <iostream>
#include <vector>

// Basic scaffolding for the project

using namespace std;

// Function to calculate parity bits and return the 7-bit Hamming code
vector<int> generateHammingCode(vector<int> data) {
    vector<int> hammingCode(7);

    // Assign data bits to the appropriate positions
    // Positions: 2, 4, 5, 6 correspond to data bits (d1, d2, d3, d4)
    hammingCode[2] = data[0];  // d1
    hammingCode[4] = data[1];  // d2
    hammingCode[5] = data[2];  // d3
    hammingCode[6] = data[3];  // d4

    // Calculate parity bits using XOR
    // Parity bit p1 is the XOR of data bits d1, d2, d4
    hammingCode[0] = hammingCode[2] ^ hammingCode[4] ^ hammingCode[6];  // p1

    // Parity bit p2 is the XOR of data bits d1, d3, d4
    hammingCode[1] = hammingCode[2] ^ hammingCode[5] ^ hammingCode[6];  // p2

    // Parity bit p4 is the XOR of data bits d2, d3, d4
    hammingCode[3] = hammingCode[4] ^ hammingCode[5] ^ hammingCode[6];  // p4

    return hammingCode;
}

// Function to detect and return the position of an error, if present
int detectError(vector<int> hammingCode) {
    // Recalculate parity bits from the received Hamming code
    // Use the same logic as when generating the code to check consistency

    int p1 = hammingCode[0] ^ hammingCode[2] ^ hammingCode[4] ^ hammingCode[6];  // Check parity for p1
    int p2 = hammingCode[1] ^ hammingCode[2] ^ hammingCode[5] ^ hammingCode[6];  // Check parity for p2
    int p4 = hammingCode[3] ^ hammingCode[4] ^ hammingCode[5] ^ hammingCode[6];  // Check parity for p4

    // The error position is calculated by combining the three parity checks
    // It forms a 3-bit binary number where:
    // - p1 is the least significant bit (LSB)
    // - p2 is the middle bit
    // - p4 is the most significant bit (MSB)
    return (p4 * 4 + p2 * 2 + p1 * 1);  // Binary value represents the position of the error
}

// Function to correct the error if one is detected
void correctError(vector<int>& hammingCode, int errorPosition) {
    if (errorPosition > 0) {
        cout << "Error detected at position: " << errorPosition << endl;
        // Flip the bit at the detected error position (1-based index)
        hammingCode[errorPosition - 1] = hammingCode[errorPosition - 1] ^ 1;  // Correct the error
    }
    else {
        cout << "No error detected." << endl;
    }
}

// Function to decode the 7-bit Hamming code back into the original 4-bit data
vector<int> decodeHammingCode(vector<int> hammingCode) {
    // Extract the original data bits (d1, d2, d3, d4) from the Hamming code
    vector<int> originalData(4);
    originalData[0] = hammingCode[2];  // d1
    originalData[1] = hammingCode[4];  // d2
    originalData[2] = hammingCode[5];  // d3
    originalData[3] = hammingCode[6];  // d4
    return originalData;
}

int main() {
    // Example input: 4-bit data to encode
    vector<int> data = { 1, 0, 1, 1 };  // Example 4-bit data: d1=1, d2=0, d3=1, d4=1

    // Generate the Hamming Code from the 4-bit data
    vector<int> hammingCode = generateHammingCode(data);
    cout << "Generated Hamming Code: ";
    for (int bit : hammingCode) {
        cout << bit;
    }
    cout << endl;

    // Optional: Introduce an error by flipping a bit (for testing error correction)
    hammingCode[3] ^= 1;  // Introduce an error at position 4 (parity bit p4)
    cout << "Hamming Code with error: ";
    for (int bit : hammingCode) {
        cout << bit;
    }
    cout << endl;

    // Detect and correct the error
    int errorPosition = detectError(hammingCode);  // Find the error position
    correctError(hammingCode, errorPosition);      // Correct the error if found

    // Display the corrected Hamming code
    cout << "Corrected Hamming Code: ";
    for (int bit : hammingCode) {
        cout << bit;
    }
    cout << endl;

    // Decode the corrected Hamming code back to the original 4-bit data
    vector<int> decodedData = decodeHammingCode(hammingCode);
    cout << "Decoded Data: ";
    for (int bit : decodedData) {
        cout << bit;
    }
    cout << endl;

    return 0;
}
