//
//  main.cpp
//  Caesar Cipher
//
//  Created by Jay Tunkie Saunders on 3/25/18.
//  Copyright © 2018 Jay Tunkie Saunders. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void encrypt_decrypt(int key, string f_in, string f_out, string state)
{
    string line;
    ifstream file;
    ofstream encrypt_file;
    file.open (f_in);
    encrypt_file.open (f_out);
    if (file.is_open() and encrypt_file.is_open())
    {
        while ( getline (file, line))
        {
            string newline;
            for (char& c : line)
            {
                if (c != ' ')
                {
                    if (state == "encrypt")
                    {
                        int enc = (int) c + key;
                        char enc_chr = (char) enc;
                        newline += enc_chr;
                    }
                    else if (state == "decrypt")
                    {
                        int enc = (int) c - key;
                        char enc_chr = (char) enc;
                        newline += enc_chr;
                    }
                    else cout << "Error: Invalid State" << endl;

                }
                else if (c == ' ')
                {
                    newline += ' ';
                }
            }
            newline += '\n';
            encrypt_file << newline;
        }
        file.close();
        encrypt_file.close();
    }
    
    else cout << "Unable to open file" << endl;
}

int main(void)
{
    int key = 75;
    string f_in = "void.txt";
    string f_enc = "secret.txt";
    string enc = "encrypt";
    string dec = "decrypt";
    encrypt_decrypt(key, f_in, f_enc, enc);
    string f_denc = "revealed.txt";
    encrypt_decrypt(key, f_enc, f_denc, dec);
    return 0;
}
