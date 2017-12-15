#include <iostream>
#include "CreditAccount.h"
#include "CreditAccount.cpp"

using std::cout;
using std::endl;

int main()
   {
   char code1[20] = "1111-1111-1111-1111";
   char name1[21] = "Jermaine Arnold";
   char code2[20] = "2222-2222-2222-2222";
   char name2[21] = "Vanessa Long";

   // Test default constructor
   CreditAccount account1;

   // Test alternate constructor
   CreditAccount account2(code1, name1, 1000.00, 520.25);

   // Account with negative balance
   CreditAccount account3(code2, name2, 1500.00, -62.95);

   // Test print() method and whether constructors
   // properly initialized objects
   cout << "Printing account1\n\n";
   account1.print();
   cout << endl;

   cout << "Printing account2\n\n";
   account2.print();
   cout << endl;

   cout << "Printing account3\n\n";
   account3.print();
   cout << endl;

   // Test accessor methods
   cout << "Testing accessor methods for account2\n\n";

   cout << account2.getAccountNumber() << endl;
   cout << account2.getName() << endl;
   cout << account2.getLimit() << endl;
   cout << account2.getBalance() << endl << endl;

   // Test the processCharge() method with a successful charge
   bool chargeAccepted = account2.processCharge(400.00);
   if (chargeAccepted)
      cout << "Charge of $400.00 accepted, new balance on account2 is $" << account2.getBalance() << endl;
   else
      cout << "Charge of $400.00 on account2 declined\n";
      
   cout << endl;
   
   // Test the processCharge() method with a failed charge
   chargeAccepted = account2.processCharge(620.00);
   if (chargeAccepted)
      cout << "Charge of $620.00 accepted, new balance on account2 is $" << account2.getBalance() << endl;
   else
      cout << "Charge of $620.00 on account2 declined\n";
      
   cout << endl;

   // Test the processPayment() method
   cout << "Payment of $500.00 on account2\n\n";
   account2.processPayment(500.00);   
   account2.print();

   cout << endl;
      
   // Test the processPayment() method by overpaying - should now have a 
   // credit on the account
   cout << "Payment of $750.00 on account2\n\n";
   account2.processPayment(750.00);
   account2.print();

   return 0;
   }
