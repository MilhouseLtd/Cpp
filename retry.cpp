//
//
//
// Build: g++ -std=c++1y
//
// Retry method using lambda function.
//

#include <functional>
#include <iostream>

class myClass {
public:
   myClass() { std::cout << "create myClass\n"; }

   void doit() const {
      std::cout << " doit \n";

      retry([this]() -> bool { return func(); });
   }

   bool func() const {
      static int count = 1;
      std::cout << " func " << count << "\n";

      if (0 == (count++ % 3)) {
         return true;
      } else {
         return false;
      }
   }

    void retry(std::function<bool()> func) const {
      const int retries = 3;
      int i = 1;

      do {
         if (func()) {
            std::cout << "success\n";
            break;
         }

         if (i >= retries) {
            std::cout << "timeout\n";
         }
      } while (i++ < retries);
   }
};


int main(int, char**)
{
   std::cout << "running...\n";

   myClass c;
   c.doit();

   std::cout << "done\n";

   return 0;
}
