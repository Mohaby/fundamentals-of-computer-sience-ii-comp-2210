/* Project 1
* Mohab Yousef
* 09-09-22
* used youtube videos to learn more about c++
* Used Dr. Li's slides and hint.
* Used g++ project1_mey0012.cpp to compile code.
*/
#include <iostream>
using namespace std;
int main() {
   float monthlyPaid = -1;               
   float interestRate = -1;
   float loan = -1;               
                               
       // CURRENCY FORMATTING
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
       // USER INPUT
       // NOTE: For valid input, the loan, interest, and monthly payment must
       // be positive. The monthly payment must also be large enough to
       // terminate the loan.
       
   while (loan <= 0) {
      
      cout << "\nLoan Amount: ";
      cin >> loan;
   }
   while (interestRate <= -1) {
      cout << "Interest Rate (% per year): ";
      cin >> interestRate;
   }
       // INTEREST RATES FOR CALCULATIONS
       
   float interestRateC = interestRate / 12 / 100;       
       
   while (monthlyPaid <= 0 || monthlyPaid <= loan * interestRateC) {
      cout << "Monthly Payments: ";
      cin >> monthlyPaid;
   }
      
   cout << endl;
       
       // AMORTIZATION TABLE
   cout << "*****************************************************************\n"
            << "\tAmortization Table\n"
            << "*****************************************************************\n"
            << "Month\tBalance\t  Payment\tRate\tInterest\tPrincipal\n";
       // LOOP TO FILL TABLE
       
   int currentMonth = 0;
   float interestTotal = 0;
       
       
   while (loan > 0) {
      if (currentMonth == 0) {
         cout << currentMonth++ << "\t$" << loan;
         if (loan < 1000) cout << "\t"; // Formatting MAGIC
         cout << "  N/A\t\tN/A\tN/A\t\tN/A\n";
      }
      else {
         float interestP = loan * interestRateC;
         float principalP = monthlyPaid - interestP;
         loan -= principalP;
         interestTotal += interestP;
      
         if (loan < 0) {
            principalP += loan;
            monthlyPaid += loan;
            loan = 0;
         }
         cout << currentMonth++ << "\t$" << loan;
         if (loan < 1000) cout << "\t";
         cout << "  $" << monthlyPaid << "\t" << interestRateC * 100 << "\t$" << interestP << "\t\t$" << principalP << "\n"; 
      
      }
   }
   cout << "****************************************************************\n"; cout << "\nIt takes " << --currentMonth << " months to pay off "
            << "the loan.\n"
            << "Total interest paid is: $" << interestTotal;
   cout << endl << endl;
   return 0;
}
