/**
* @file EncryptionTest.cpp
* @Author Gurkan Kayi (152120191092@ogrenci.ogu.edu.tr)
* @date December, 2023
*/

#include "Encryption.h"
#include <iostream>
#include<iomanip>
using namespace std;

//! Tests the Encryption class.
static void EncryptionTest() {
    cout << "EncryptionTest:" << endl;

    //! Test encrypt and decrypt functions with a 4-digit number.
    //! @param originalNumber is an integer variable to store the original number.
    //! @param encryptedNumber is an integer variable to store the encrypted number.
    //! @param decryptedNumber is an integer variable to store the decrypted number.
    int originalNumber = 1234;
    int encryptedNumber = Encryption::encrypt(originalNumber);
    int decryptedNumber = Encryption::decrypt(encryptedNumber);

    //! Display results.
    cout << "Original Number : " << setw(4) << setfill('0') << originalNumber << endl;
    cout << "Encrypted Number: " << setw(4) << setfill('0') << encryptedNumber << endl;
    cout << "Decrypted Number: " << setw(4) << setfill('0') << decryptedNumber << endl;

    //! Test with another 4-digit number.
    originalNumber = 5678;
    encryptedNumber = Encryption::encrypt(originalNumber);
    decryptedNumber = Encryption::decrypt(encryptedNumber);

    //! Display results.
    cout << "Original Number : " << setw(4) << setfill('0') << originalNumber << endl;
    cout << "Encrypted Number: " << setw(4) << setfill('0') << encryptedNumber << endl;
    cout << "Decrypted Number: " << setw(4) << setfill('0') << decryptedNumber << endl;
    cout << endl;
}
