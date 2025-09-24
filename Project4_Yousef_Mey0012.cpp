/**
* Mohab Yousef
* Project 4
* 10/28/2022
**/
// Libary Imports.
# include <iostream>
   # include <cstring>
   # include <fstream>
   # include <climits>
   # include <string>
   # include <assert.h>
   # include <cstdlib>
   using namespace std;
   //Structure for creating a linked list that holds a trivia question,answer and point amount.
   struct triva_node {
       string question;
       string answer;
       int point;
       triva_node *next;
   };
   //creates a pointer to triva_node.
   typedef triva_node* ptr_node;
   
   //Prototypes
    void init_question_list(ptr_node& q_list);
    void add_question(ptr_node& q_list);
    int ask_question(ptr_node q_list, int num_ask);
    void Unit_Test();
    void clear();
   
   //creates two versions.
   //#define UNIT_TESTING
   #define triva_quiz
   
   int num_of_questions;
   
   int main() {
       ptr_node node_list = new triva_node;
      #ifdef triva_quiz
       init_question_list(node_list);
       cout << "*** Welcome to Li's trivia quiz game ***\n";
       string input = "Yes";
          while (input == "Yes" || input == "yes" || input == "YES") {
              add_question(node_list);
              cout << "Continue? (Yes/No): ";  
              cin >> input;   
              clear();     
          }
          cout << "\n";
          
          
          
          
         //This is start of Trivia quiz game.
         ask_question(node_list, num_of_questions);
         cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***";
         return 0;
    }
    void clear() {
          cin.clear();
          cin.ignore(INT_MAX, '\n');
    }
    
    
   #endif
   //Method for testing
   #ifdef UNIT_TESTING
   Unit_Test();
   return 0;
   }
   #endif
   
   //initializes the quiz to have these three questions inputted into the linked list.
   void init_question_list(ptr_node& q_list) {
      string bob;
      ptr_node cur_ptr = new triva_node;
      cur_ptr->question = "How long was the shortest war on record? (Hint: how many minutes)";
      cur_ptr->answer = "38";
      cur_ptr->point = 100;
       
      cur_ptr->next = new triva_node;
      q_list = cur_ptr;
      cur_ptr = q_list->next;
      cur_ptr->question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)?";
      cur_ptr->answer = "Bank of Italy";
      cur_ptr->point = 50;
      cur_ptr->next = new triva_node;
      cur_ptr = cur_ptr->next;
      cur_ptr->question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)?";
      cur_ptr->answer = "Wii Sports";
      cur_ptr->point = 20;
      cur_ptr->next = NULL;
      num_of_questions = 3;
    }
   //gives user the option to add a question to the linked list.
   //question is added to the front of the linked list.
   void add_question(ptr_node& q_list) {
       string answer;
       //gets data from user.
       
       ptr_node new_ptr = new triva_node;
       
       cout << "Enter a new question: ";
       getline(cin, new_ptr->question);
       
       cout << "Enter an answer: ";
       getline(cin, new_ptr->answer);
       
       cout << "Enter award points: ";
          cin >> new_ptr->point;
          new_ptr->next = q_list;
          q_list = new_ptr;
          num_of_questions++;
    }
    
     int ask_question(ptr_node q_list, int num_ask) {
      string user_answer;
      string correct_answer;
      int point_total = 0;
      ptr_node cur_ptr;
      cur_ptr = q_list;
      if (q_list == NULL)
         return 0;
      if(num_ask < 1) {
         cout << "Warning - the number of trivia to be asked must equal to or be larger than 1.";
       }
      else if(num_of_questions < num_ask) {
         cout << "Warning - There is only " << num_of_questions << " trivia in the list.";
         }
      else {
         for(int x = 0; x < num_ask; x++) {
            cout << "Question: " << cur_ptr->question << endl;
            cout << "Answer: ";
            getline(cin, user_answer);
            if (user_answer.compare(cur_ptr->answer) == 0) { // correct_answer
               cout << "Your answer is correct! You receive " << cur_ptr->point << " points.\n";
               point_total += cur_ptr->point;
               cout << "Your total points: " << point_total << endl;
            }
            else {
              cout << "Your answer is wrong. The correct answer is " <<
               cur_ptr-> answer  << endl;
                          cout << "Your total points " << point_total << endl;
            }
         cur_ptr = cur_ptr->next;
         }
      }
   return 0; 
   }
   //Test cases
   void Unit_Test() {
       ptr_node node_list = new triva_node;
       init_question_list(node_list);
       int answer;
       cout << "Unit Test Case 1: Ask no question. The program should give a warning message." << endl;
       ask_question(node_list, 0);
       cout << "\nCase 1 Passed\n\n";
       
       cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester enters an incorrect answer." << endl;
       answer = ask_question(node_list, 1);
       assert(answer == 1);
       cout << "Case 2.1 passed\n";
       
       cout << "\nUnit Test Case 2.2: Ask 1 question in the linked list. The tester enters a correct answer."<< endl;
       answer = ask_question(node_list, 1);
       assert(answer == 1);
       cout << "Case 2.2 passed\n";
       
       cout << "\nUnit Test Case 3: Ask 1 question in the linked list. The tester enters a correct answer."<< endl;
       answer = ask_question(node_list, 3);
       assert(answer == 1);
       cout << "Case 3 passed\n";
       
       cout << "\nUnit Test Case 4: Ask 1 question in the linked list. The tester enters a correct answer."<< endl;
       answer = ask_question(node_list, 4);
       assert(answer == 0);
       cout << "Case 4 passed\n";
       
       cout << "\n\n*** End of the Debugging Version ***\n";
   }
       