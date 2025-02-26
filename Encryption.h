/**
* @file Encryption.h
* @Author Gurkan Kayi (152120191092@ogrenci.ogu.edu.tr)
* @date December, 2023
* @brief Encryption class to be used in robot applications to encrypt and decrypt data.
* 
* Encryption class is used to encrypt and decrypt data. It has encrypt and decrypt functions.
* It has static functions to encrypt and decrypt data taken as integer.
*/

#ifndef ENCRYPTION_H
#define ENCRYPTION_H

class Encryption {
public:
    //! Encrypts the given number.
    static int encrypt(int number);
    //! Decrypts the given number.
    static int decrypt(int number);
};

#endif // ENCRYPTION_H
