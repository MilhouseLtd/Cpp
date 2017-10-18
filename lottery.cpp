//
//
//
// https://community.plus.net/t5/General-Chat/Lottery-Number-Generator/td-p/1463235
//
// g++ -Wall -O2 -std=c++14 -DNDEBUG lottery.cpp
//
//

#include <iostream>
#include <iomanip>
#include <list>
#include <random>
#include <algorithm>


int main(int argc, char * argv[])
{
   std::random_device rd;
   std::mt19937 engine{ rd() };
   std::vector< unsigned > machine;
   std::list< unsigned > results;

   // See if a number's been passed on the CLI
   int times = argc == 2 ? std::stoi(argv[1]) : 1;

   // Randomise the values in the vector
   for (int n(0); n < times; n++) {
      std::srand ( unsigned ( std::time(0) ) );

      // Fill vector with values in range
      for (int i= 1; i < 59; ++i) machine.push_back(i);

      // Randomise the content of the vector
      std::random_shuffle (machine.begin(), machine.end(), [](unsigned i) { return std::rand() % i;} );

      // Start the output
      std::cout << "Line # " << std::setw(2) << (n + 1) << " : ";

      // Draw the numbers needed
      for (int i(0); i < 6; i++) {
         // Get a randomly generated int within the range of the vector size
         std::uniform_int_distribution< int > dist(0, machine.size() -1 );
         int pos = dist(engine);

         // Push the selected value into the list
         results.push_back(machine[pos]);

         // Remove the value from the vector
         machine.erase(machine.begin() + pos);
      }

      machine.clear();

      // Sort the selection in ascending order
      results.sort();

      // Write the results to the console
      for (std::list< unsigned >::const_iterator ci = results.begin(); ci != results.end(); ++ci) {
         std::cout << std::setw(2) << (*ci) << " ";
      }

      std::cout << std::endl << std::flush;

      results.clear();

      // Remove the comment from the line below if you want a delay between lines
      //std::this_thread::sleep_for(std::chrono::milliseconds(50));
   }

   //std::cout << "Press Enter or Return to Exit";
   //std::cin.get();
   return 0;
}
