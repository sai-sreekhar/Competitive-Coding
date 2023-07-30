#include <iostream>
#include <string>

using namespace std;

// Function to perform bitwise XOR of two strings
string bitwiseXOR(string a, string b)
{
    string result = "";

    int n = b.length();

    // Traverse all bits, if bits are same, then XOR is 0, else 1
    for (int i = 1; i < n; i++)
    {
        if (a[i] == b[i])
            result += "0";
        else
            result += "1";
    }

    return result;
}

// Function to perform modulo-2 division
string modulo2Division(string dividend, string divisor)
{
    int pick = divisor.length(); // Number of bits to be XORed at a time

    string tmp = dividend.substr(0, pick); // Slicing the dividend for the current step
    int n = dividend.length();

    while (pick < n)
    {
        if (tmp[0] == '1')
            tmp = bitwiseXOR(divisor, tmp) + dividend[pick];
        else
            tmp = bitwiseXOR(string(pick, '0'), tmp) + dividend[pick];

        pick += 1; // Increment pick to move further
    }

    if (tmp[0] == '1')
        tmp = bitwiseXOR(divisor, tmp);
    else
        tmp = bitwiseXOR(string(pick, '0'), tmp);

    return tmp;
}

// Function used at the sender side to encode data by appending remainder of modular division
// at the end of data
void encodeData(string data, string key)
{
    int keyLength = key.length();

    // Appends keyLength-1 zeroes at the end of data
    string appendedData = (data + string(keyLength - 1, '0'));

    string remainder = modulo2Division(appendedData, key);

    // Append remainder to the original data to get the codeword
    string codeword = data + remainder;

    cout << "Remainder: " << remainder << "\n";
    cout << "Encoded Data (Data + Remainder): " << codeword << "\n";
}

// Function to check if the received message is correct or not
// If the remainder is all 0, then it is correct; otherwise, it is wrong
void receiver(string data, string key)
{
    string currentXOR = modulo2Division(data.substr(0, key.size()), key);
    int current = key.size();

    while (current != data.size())
    {
        if (currentXOR.size() != key.size())
        {
            currentXOR.push_back(data[current++]);
        }
        else
        {
            currentXOR = modulo2Division(currentXOR, key);
        }
    }

    if (currentXOR.size() == key.size())
    {
        currentXOR = modulo2Division(currentXOR, key);
    }

    if (currentXOR.find('1') != string::npos)
    {
        cout << "There is an error in the received data.\n";
    }
    else
    {
        cout << "Correct message received.\n";
    }
}

int main()
{
    string dataToSend;
    cout << "Enter the data to be sent: ";
    cin >> dataToSend;

    string senderKey;
    cout << "Enter the key at the sender side: ";
    cin >> senderKey;

    string receivedData;
    cout << "Enter the received data: ";
    cin >> receivedData;

    string receiverKey;
    cout << "Enter the key at the receiver side: ";
    cin >> receiverKey;

    cout << "--------------------Sender side--------------------\n";
    cout << "Data to be sent: " << dataToSend << "\n";
    cout << "Key: " << senderKey << "\n";
    encodeData(dataToSend, senderKey);

    cout << "--------------------Receiver side--------------------\n";
    cout << "Received data: " << receivedData << "\n";
    cout << "Key: " << receiverKey << "\n";
    receiver(receivedData, receiverKey);

    return 0;
}
