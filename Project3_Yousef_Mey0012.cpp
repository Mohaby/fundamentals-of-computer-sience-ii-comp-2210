/**
* Mohab Yousef
* 14/10/22
* Project 3
*
 */
#include <fstream>
   #include <iostream>
   #include <vector>
   using namespace std;
   
   /* declare your user-defined functions */
   
   bool check_file(string);
   
   /* describe each function */
   
   vector<int> read_file(string);
   
   void write_file(string, vector<int>);
   
   vector<int> merge(vector<int>, vector<int>);

   void to_string(string, vector<int>);
/*
* Merge the numbers
*
* Return: Program completed successfully. (int)
*/
   int main() {
   /* declare your variables */
      string input1;
      string input2;
      string output;
      vector<int> numbers1;
      vector<int> numbers2;
      vector<int> numbers3;
      cout << "*** Welcome to Mohab's sorting program ***\n";
   /* Get name of file one. */
       do {
         
   /* user friendly interfaces */
         cout << "Enter the first input file name: ";
         cin >> input1;
         cout << " ";
         } 
       while (cin.fail() || !check_file(input1));
   /* Get and display numbers from file one. */
        
        numbers1 = read_file(input1);
        to_string(input1, numbers1);
        
        
   /* Get name of file two. */
       do {
         
   /* user friendly interfaces */
         cout << "Enter the second input file name: ";
         cin >> input2;
         cout << " ";
         } 
       while (cin.fail() || !check_file(input2));
   /* Get and display numbers from file one. */
        
        numbers2 = read_file(input2);
        to_string(input2, numbers2);
        
        
        
      /* Combine vectors and display the sorted result. */
          numbers3 = merge(numbers1, numbers2);
          cout << "The sorted list of " << numbers3.size() << " "
                 << "numbers is: ";
          for (int i = 0; i < numbers3.size() - 1; i++) {
                cout << numbers3.at(i) << " ";
          }
          cout << numbers3.at(numbers3.size() - 1) << "\n";
      /* Get name of output file. */
          do {

         cout << "Enter the output file name: ";
                cin >> output;
                cout << "";
          } while (cin.fail());
      /* Write combined vector to output file. */
          write_file(output, numbers3);
          cout << "*** Please check the new file - " << output << " ***\n";
          cout << "*** Goodbye. ***\n";
          return 1; 
          }
          
          
          
      bool check_file(string file) {
    /* Input file stream. (ifstream) */
          ifstream stream;
          
      /* Check whether file exists. */
          stream.open(file.c_str());
          if (stream.fail()) {
                cerr << "Input file not found.\n\n";
                return false;
          }
          stream.close();
          
          return true;
      }
    
       vector<int> read_file(string file) {
         /* Input file stream. (ifstream) */
         ifstream stream;
         /* Vector containing numbers from file. (vector<int>) */
         vector<int> v;
         /* Integer read from file. (int) */
         int i;
         /* Add each number in the file to a vector. */
         stream.open(file.c_str());
         while (stream.good()) {
            stream >> i;
                v.push_back(i);
            }
         v.pop_back();
         stream.close();
         return v;
         }
         
         
         void write_file(string file, vector<int> v) {
          /* Output file stream. (ofstream) */
          ofstream stream;
          
          /*Interator number */
          
          unsigned short i;
          
          stream.open(file.c_str());
          for (i = 0; i < v.size() - 1; i++) {
                stream << v.at(i) << "\n";
          }
          
          stream << v.at(v.size() - 1);
          stream.close();
          }
          
          vector<int> merge(vector<int> v1, vector<int> v2) {
          vector<int> v3;
          unsigned short i;
          unsigned short s;
          
          /* Compare both vectors. */
          while (v1.size() > 0 && v2.size() > 0) {
                if (v1.at(0) < v2.at(0)) {
                      v3.push_back(v1.at(0));
                      v1.erase(v1.begin());
                } else {
                      v3.push_back(v2.at(0));
                      v2.erase(v2.begin());
                }
           }
           /* Add any remaining numbers from vector one. */
          if (v1.size() > 0) {
                s = v1.size();
                for (i = 0; i < s; i++) {
                      v3.push_back(v1.at(0));
                      v1.erase(v1.begin());
                      }
            }  
          /* Add any remaining numbers from vector two. */
          if (v2.size() > 0) {
                s = v2.size();
                for (i = 0; i < s; i++) {
                      v3.push_back(v2.at(0));
                      v2.erase(v2.begin());
                     }
               }
               return v3; 
           }
          void to_string(string file, vector<int> v) {
            /* Vector interator number. (unsigned short) */
            unsigned short i;
          
            /* Display the numbers contained in a vector. */
            cout << "The list of " << v.size() << " numbers "
                  << "in file " << file << " is:\n";
            for (i = 0; i < v.size(); i++) {
                  cout << v.at(i) << "\n";
                
                  }
                  cout << "\n";
           }