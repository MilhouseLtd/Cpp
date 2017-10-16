//
//
//
// Build: g++ -std=c++1y
//

#include <iostream>
#include <experimental/optional>


int main(int, char**)
{
   std::cout << "running...\n";

   std::experimental::optional<double> d;

   std::cout << "Value of d: " << d.value_or(0.00) << "\n";
   d = 1.11;
   std::cout << "Value of d: " << d.value_or(0.00) << "\n";

   std::cout << "done\n";

   return 0;
}
