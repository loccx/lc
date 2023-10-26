/*

   void make_payment(double amount): Makes a payment towards the credit card balance.

   Your task is to implement the BankCard, DebitCard, and CreditCard classes in C++ with the methods described above, ensuring appropriate inheritance and functionality for each card type.
   */

#include <iostream>
#include <string>

using namespace std;

class BankCard {
    private:
        string cardholder_name;
        string card_number;
        string expiration_date;

    public:
        BankCard() :
            cardholder_name(""),
            card_number(""),
            expiration_date("")
    {}

};

class DebitCard : public BankCard {
    private:
        long long balance;
    public:
        DebitCard() :
            BankCard(),
            balance(0)
        {}
};

int main() {
}
