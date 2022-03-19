#include <iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define input for (int i= 0 ; i<n ;i++)

string encrypt (string message , string keyword) {
    string encrypted_message ;

    while (keyword.length() != message.length()) {
        for (int i = 0; i < keyword.length(); ++i) {
            if (keyword.length() == message.length()) break;
            keyword += keyword[i];
        }
    }

    for (int i = 0; i < message.length(); ++i) {
        if (isalpha(message[i])) {
            encrypted_message += char (((message[i] + keyword[i]) % 26) + 65);
        }
        else encrypted_message += message[i];
    }
    return encrypted_message;
}

string decrypt (string decrypted , string keyword) {

    string message;

    while (decrypted.length() != keyword.length()) {

        for (int i = 0; i < keyword.length(); ++i) {
            if (decrypted.length() == keyword.length()) break;
            keyword += keyword[i];
        }
    }

    for (int i = 0; i < keyword.length(); ++i) {
        if (isalpha(decrypted[i])) {

            if (decrypted[i] - keyword[i] >= 0) {
                message += char((decrypted[i] - keyword[i]) + 65);
            }
            else {
                message += char (((decrypted[i] - keyword[i]) + 26) + 65);
            }
        }
        else message += decrypted[i];

    }

    return message;
}


int main() {


    cout<< "this Vignere cipher, give us your message and its keyword and no one will know it\n\n";

    while (true) {
        string choice ;
        cout<<"choose what you want to do on your message\n"
              "1- enter 1 to encrypt your message\n"
              "2- enter 2 to decrypt your message\n"
              "3- enter 3 to end this programme\n\n";

        cout<< "enter the number of operation you want to do : ";
        cin>>choice;
        while (true){
            if (choice == "1" || choice == "2" || choice == "3") break;
            else {
                cout <<"your choice must be 1 ,2 or 3 \n";
                choice = "";
                cout<< "try again but this time choose carefully : ";
                cin>>choice;
            }
        }

        if (choice  == "3" ){
            cout<< "you choose to end this programme\n\n";
            break;
        }
        if (choice == "1") {

            string message, keyword;
            cout<< "your information must be classified to make you come here and encrypt it,\n"
                   " don`t worry we will encrypt it for you, enter what you want : ";
            while (message.empty()) getline(cin, message);

            cout<<"enter a helpful keyword to make sure that your information"
                  "will be decrypted by this keyword : ";
            while (keyword.empty()) getline(cin, keyword);

//            it is better to make all characters in uppercase
            for (int i = 0; i < message.length(); ++i) {
                message[i] = toupper(message[i]);
            }

            for (int i = 0; i < keyword.length(); ++i) {
                keyword[i] = toupper(keyword[i]);
            }

//    defensive to make the length of the message does not exceed 80
            while (message.length() > 80) {
                message = "";
                cout << " this message is too long and can be decrypted by others, try a shorter one : ";
                while (message.empty()) getline(cin, message);
            }

//            defensive to make sure that the keyword`s length does not exceed 8
            while (keyword.length() > 8) {
                keyword = "";
                cout << "this key word is a bit long, try something less than or equal to 8 characters : ";
                while (keyword.empty()) getline(cin, keyword);
            }

            cout<< "here is your encrypted message : " << encrypt(message , keyword)<<"\n\n";
        }


        if (choice == "2") {
            cout<< "you choose to enter an encrypted word and we will decrypt for you. \n\n";

            string encrypted_word ,keyword;
            cout<< "enter your encrypted word : ";
            while (encrypted_word.empty()) getline(cin, encrypted_word);

            for (int i = 0; i < encrypted_word.length(); ++i) {
                encrypted_word[i] = toupper(encrypted_word[i]);
            }

            cout<< "enter the keyword to help with the decryption : ";
            while (keyword.empty()) getline(cin , keyword);

            for (int i = 0; i < keyword.length(); ++i) {
                keyword[i] = toupper(keyword[i]);
            }


            cout<< "that is what we came out with after the decryption of "<<encrypted_word<<" : "<< decrypt(encrypted_word, keyword)<<"\n\n";
        }

    }
    return 0;
}
