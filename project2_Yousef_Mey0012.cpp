/**
* Mohab Yousef
* project 2
* 09/21/22
**/

#include <iostream> 
#include <stdlib.h> 
#include <assert.h> 
#include <ctime> 
using namespace std;

//Variables
const double A_Hit = (1.0/3.0) * 100.0;
const double B_Hit = (1.0/2.0) * 100.0;
const double C_Hit = 100;
const int TOTAL_DUELS = 10000;

bool A_alive = true;
bool B_alive = true;
bool C_alive = true;

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
void Aaron_shoots1(bool& B_alive, bool& C_alive);
void Bob_shoots(bool& A_alive, bool& C_alive);
void Charlie_shoots(bool& A_alive, bool& B_alive);
void Aaron_shoots2(bool& B_alive, bool& C_alive);
void strat1(void);
void duel_strat2(void);

void  test_at_least_two_alive(void);
void  test_Aaron_shoots1(void);
void  test_Bob_shoots(void);
void  test_Charlie_shoots(void);
void  test_Aaron_shoots2(void);

/*
* Input: A_alive indicates Aaron is alive true for alive, false for dead
* B_alive indicates Bob is alive
* C_alive indicates Charlie is alive
* Return: true if at least two are alive otherwise return false
*/
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
   if ((A_alive && B_alive) || (A_alive && C_alive) || (B_alive && C_alive)) {
      return true;
   }

   return false;
}

/*
* Call by reference
* Strategy 1: Everyone shoots to kill the highest accuracy player alive 
* Input: B_alive indicates Bob is alive or dead
* C_alive indicates Aaron is alive or dead
* Return: Change B_alive into false if Bob is killed
*
*/

void Aaron_shoots1(bool& B_alive, bool& C_alive) {
   int shoot = rand() % 100;
   if (shoot <= A_Hit) {
      if (C_alive) {
         C_alive = false;
      }
      else {
         B_alive = false;
      }
   }
}
/*
* Call by reference
* Input: A_alive indicates Aaron is alive or dead
* C_alive indicates Charlie is alive or dead
* Return: Change A_alive into false if Aaron is killed * Change C_alive into false if Charlie is killed
Change C_alive into false if Charlie is killed
*/
void Bob_shoots(bool& A_alive, bool& C_alive) {
   int shoot = rand() % 100;
   if (shoot <= B_Hit) {
      if (C_alive) {
         C_alive = false;
      }
      else {
         A_alive = false;
      }
   }
}

/*
* Call by reference
* Input: A_alive indicates Aaron is alive or dead
* B_alive indicates Bob is alive or dead
* Return: Change A_alive into false if Aaron is killed
* Change B_alive into false if Bob is killed
*/
void Charlie_shoots(bool& A_alive, bool& B_alive) {
   if (B_alive) {
      B_alive = false;
   }
   else {
      A_alive = false;
   }
}

/*
* Call by reference
* Strategy 2: Aaron intentionally misses if both are alive * Input: B_alive indicates Bob is alive or dead
* C_alive indicates Aaron is alive or dead
* Return: Change B_alive into false if Bob is killed
* Change C_alive into false if charlie is killed
*/
void Aaron_shoots2(bool& B_alive, bool& C_alive) {
   int shoot;
   shoot = rand()%100;
   if (!(B_alive && C_alive)) {
      if (shoot <= 33) {
         if (C_alive) {
            C_alive = false;
         }
         else if (B_alive) {
            B_alive = false;
         }
      }
   }
}


int main() {
   
   cout << "*** Welcome to Mohab's Duel Simulator ***" << endl; 
   srand(time(0));
   int A_win = 0;
   int A_win2 = 0;
   int B_win = 0;
   int B_win2 = 0;
   int C_win = 0;
   int C_win2 = 0;
   int strategy1;
   int strategy2;
   test_at_least_two_alive();
   cout << "Press any key to continue..." << endl;
   cin.get();
   test_Aaron_shoots1();
   cout << "Press any key to continue..." << endl;
   cin.get();
   test_Bob_shoots();
   cout << "Press any key to continue..." << endl;
   cin.get();
   test_Charlie_shoots();cout << "Press any key to continue..." << endl;
   cin.get();
   
   test_Aaron_shoots2();
   
   
   cout << "Press any key to continue..." << endl;
   cin.get();
   
   cout << "Ready to test strategy 1 (run 10000 times):" << endl;
   cout << "Press any key to continue..." << endl;
   cin.get();
   
   
   
  
   
   for (int i = 0; i < TOTAL_DUELS; i++) {
   
   	//reset variables to true
      
      A_alive = true;
      B_alive = true;
      C_alive = true;
   
      strategy1 = A_win;
      
      
      while (at_least_two_alive(A_alive, B_alive, C_alive)) {
         if (A_alive) {
            Aaron_shoots1(B_alive, C_alive);
         }
         if (B_alive) {
            Bob_shoots(A_alive, C_alive);
         }
         if (C_alive) {
            Charlie_shoots(A_alive, B_alive);
         }
      }
      if (A_alive) {
         A_win++;
      	
      }
      else if (B_alive) {
         B_win++;
      	
      }
      else if (C_alive) {
         C_win++;
         
      }
   }
      
            
      
   cout << "Aaron won " << A_win << "/" << TOTAL_DUELS << " duels or " << (A_win / 100.0) << "%" << endl;
   cout << "Bob won " << B_win << "/" << TOTAL_DUELS << " duels or " << (B_win / 100.0) << "%" << endl;
   cout << "Charlie won " << C_win << "/" << TOTAL_DUELS << " duels or " << (C_win / 100.0) << "%\n" << endl;      
      
      
   cout << "Ready to test strategy 2 (run 10000 times):" << endl;
   cout << "Press any key to continue..." << endl;
   cin.get();
   
      
      
   for (int i = 0; i < TOTAL_DUELS; i++) {
      
      //reset variables to true each time to run duel correctly
      
      A_alive = true;
      B_alive = true;
      C_alive = true;
      
      
      strategy2 = A_win2;
   
      while (at_least_two_alive(A_alive, B_alive, C_alive)) {
         if (A_alive) {
            Aaron_shoots2(B_alive, C_alive);
         }
         if (B_alive) {
            Bob_shoots(A_alive, C_alive);
         }
         if (C_alive) {
            Charlie_shoots(A_alive, B_alive);
         }
      }
   
      if (A_alive) {
         A_win2++;
      }
      else if (B_alive) {
         B_win2++;
      }
      else if (C_alive) {
         C_win2++;
      }
   }

   cout << "Aaron won " << A_win2 << "/" << TOTAL_DUELS << " duels or " << (A_win2 / 100.0) << "%" << endl;
   cout << "Bob won " << B_win2 << "/" << TOTAL_DUELS << " duels or " << (B_win2 / 100.0) << "%" << endl;
   cout << "Charlie won " << C_win2 << "/" << TOTAL_DUELS << " duels or " << (C_win2 / 100.0) << "%" << endl;          
      
      
      
   if (strategy2 > strategy1) {
      cout << "\nStrategy 2 is better than strategy 1." << endl;
   }
   else {
      cout << "\nStrategy 1 is better than strategy 2." << endl;
   }

}

  void test_at_least_two_alive(void) {
   cout << "Unit Testing 1: Function – at_least_two_alive()\n";
   cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(true, true, true));
   cout << "\tCase passed ...\n";
   
   cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(false, true, true));
   cout << "\tCase passed ...\n";
   
   cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
   assert(true == at_least_two_alive(true, false, true));
   cout << "\tCase passed ...\n";
   
   cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
   assert(true == at_least_two_alive(true, true, false));
   cout << "\tCase passed ...\n";
   
   cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
   assert(false == at_least_two_alive(false, false, true));
   cout << "\tCase passed ...\n";
   
   cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
   assert(false == at_least_two_alive(false, true, false));
   cout << "\tCase passed ...\n";
   
   cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(true, false, false));
   cout << "\tCase passed ...\n";
   
   cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(false, false, false));
   cout << "\tCase passed ...\n";
}
   
void test_Aaron_shoots1(void) {
   cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";
   bool bob_alive;
   bool charlie_alive;
	
   cout << "\t Case 1: Bob alive, Charlie alive\n";
   cout << "\t\t  Aaron is shooting at Charlie\n";
   bob_alive = true; 
   charlie_alive = true;
   Aaron_shoots1(bob_alive, charlie_alive);

	
   cout << "\t Case 2: Bob dead, Charlie alive\n";
   cout << "\t\t  Aaron is shooting at Charlie\n";
   bob_alive = false; 
   charlie_alive = true;
   Aaron_shoots1(bob_alive, charlie_alive);

	
   cout << "\t Case 3: Bob alive, Charlie dead\n";
   cout << "\t\t  Aaron is shooting at Bob\n";
   bob_alive = true; 
   charlie_alive = false;
   Aaron_shoots1(bob_alive, charlie_alive);

	
} 
   
     void test_Bob_shoots(void) {
   cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";
   bool a_alive;
   bool c_alive;
	
   cout << "\t Case 1: Aaron alive, Charlie alive\n";
   cout << "\t\t  Bob is shooting at Charlie\n";
   a_alive = true;
   c_alive = true;
   Bob_shoots(a_alive, c_alive);

	
   cout << "\t Case 2: Aaron dead, Charlie alive\n";
   cout << "\t\t  Bob is shooting at Charlie\n";
   a_alive = false;
   c_alive = true;
   Bob_shoots(a_alive, c_alive);

	
   cout << "\t Case 3: Aaron alive, Charlie dead\n";
   cout << "\t\t  Bob is shooting at Aaron\n";
   a_alive = true;
   c_alive = false;
   Bob_shoots(a_alive, c_alive);

}
   void test_Charlie_shoots(void) {
   cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";
   bool a_alive;
   bool b_alive;
	
   cout << "\t Case 1: Aaron alive, Bob alive\n";
   cout << "\t\t  Charlie is shooting at Bob\n";
   a_alive = true;
   b_alive = true;
   Charlie_shoots(a_alive, b_alive);

	
   cout << "\t Case 2: Aaron dead, Bob alive\n";
   cout << "\t\t  Charlie is shooting at Bob\n";
   a_alive = false;
   b_alive = true;
   Charlie_shoots(a_alive, b_alive);

	
   cout << "\t Case 3: Aaron alive, Bob dead\n";
   cout << "\t\t  Charlie is shooting at Aaron\n";
   a_alive = true;
   b_alive = false;
   Charlie_shoots(a_alive, b_alive);
}

   void test_Aaron_shoots2(void) {
   cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";
   bool b_alive;
   bool c_alive;
	
   cout << "\t Case 1: Bob alive, Charlie alive\n";
   cout << "\t\t  Aaron intentionally misses his first shot\n";
   b_alive = true;
   c_alive = true;
   Aaron_shoots2(b_alive, c_alive);
   assert(true == b_alive);
   assert(true == c_alive);
   cout << "\t\t  Both Bob and Charlie are alive\n";
	
   cout << "\t Case 2: Bob dead, Charlie alive\n";
   cout << "\t\t  Aaron is shooting at Charlie\n";
   b_alive = false;
   c_alive = true;
   Aaron_shoots2(b_alive, c_alive);
   	
   cout << "\t Case 3: Bob alive, Charlie dead\n";
   cout << "\t\t  Aaron is shooting at Bob\n";
   b_alive = true;
   c_alive = false;
   Aaron_shoots2(b_alive, c_alive);

}