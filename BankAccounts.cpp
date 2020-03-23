#include <iostream>
#include <string>
using std::string;

class BankAccount
{
  private:
      // TODO: declare member variables
      int acc_num;
      string owner_name;
      int balance;

  public:
      // TODO: declare setters
      void sAc_num(int acc_num_);
      void sOwner_name(string owner_name_);
      void sBalance(int balance_);
      // TODO: declare getters
      int gAc_num() const;
      string gOwner_name() const;
      int gBalance() const;
};
// TODO: implement setters
    void BankAccount::sAc_num(int acc_num_){BankAccount::acc_num = acc_num_;}
    void BankAccount::sOwner_name(string owner_name_){BankAccount::owner_name = owner_name_;}
    void BankAccount::sBalance(int balance_){BankAccount::balance = balance_;}
    // TODO: implement getters
    int BankAccount::gAc_num() const{return BankAccount::acc_num;}
    string BankAccount::gOwner_name() const{return BankAccount::owner_name;}
    int BankAccount::gBalance() const{return BankAccount::balance;}
int main(){
    // TODO: instantiate and output a bank account    
  BankAccount ba;
  ba.sBalance(100);
  std::cout << ba.gBalance() << std::endl;    
}