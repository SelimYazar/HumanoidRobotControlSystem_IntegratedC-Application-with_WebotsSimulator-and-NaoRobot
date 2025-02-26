/**
* @file Encryption.cpp
* @Author Gurkan Kayi (152120191092@ogrenci.ogu.edu.tr)
* @date December, 2023
*/

#include "Encryption.h"

int Encryption::encrypt(int number) {
    //! @param digit1 is an integer variable to store the first digit of the number.
    //! @param digit2 is an integer variable to store the second digit of the number.
    //! @param digit3 is an integer variable to store the third digit of the number.
    //! @param digit4 is an integer variable to store the fourth digit of the number.
    int digit1, digit2, digit3, digit4;

    //! Extracting digits.
    digit1 = number / 1000;
    digit2 = (number / 100) % 10;
    digit3 = (number / 10) % 10;
    digit4 = number % 10;

    //! Encryption algorithm.
    digit1 = (digit1 + 7) % 10;
    digit2 = (digit2 + 7) % 10;
    digit3 = (digit3 + 7) % 10;
    digit4 = (digit4 + 7) % 10;

    //! Swapping digits.
    //! @param encryptedNumber is an integer variable to store the encrypted number.
    int encryptedNumber = digit3 * 1000 + digit4 * 100 + digit1 * 10 + digit2;

    return encryptedNumber;
}

int Encryption::decrypt(int number) {
    //! @param digit1 is an integer variable to store the first digit of the number.
    //! @param digit2 is an integer variable to store the second digit of the number.
    //! @param digit3 is an integer variable to store the third digit of the number.
    //! @param digit4 is an integer variable to store the fourth digit of the number.
    int digit1, digit2, digit3, digit4;

    //! Extracting digits.
    digit1 = number / 1000;
    digit2 = (number / 100) % 10;
    digit3 = (number / 10) % 10;
    digit4 = number % 10;

    //! Decryption algorithm.
    digit1 = (digit1 + 3) % 10;
    digit2 = (digit2 + 3) % 10;
    digit3 = (digit3 + 3) % 10;
    digit4 = (digit4 + 3) % 10;

    //! Swapping digits.
    //! @param decryptedNumber is an integer variable to store the decrypted number.
    int decryptedNumber = digit3 * 1000 + digit4 * 100 + digit1 * 10 + digit2;

    return decryptedNumber;
}