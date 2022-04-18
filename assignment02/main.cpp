
#include "queue.h"

int main(int argc, char *argv[])
{
   //#if 0
   std ::cout << "init+push test \n";
   queue q1;
   q1.print(std::cout);
   q1.push("as");
   q1.push("asas");
   q1.push("asasas");
   // std::cout << q.front << " " << q.front->next;
   q1.print(std::cout);

   std ::cout << "reset test \n";
   size_t k = 2;
   q1.reset(k);
   q1.print(std::cout);

   std ::cout << "copy test \n";
   queue q_copy(q1);
   q_copy.print(std::cout);

   queue q5;
   queue q_copy2(q5);
   q_copy2.print(std::cout);

   std ::cout << "init list test \n";
   queue q3 = {"we", "are", "waiting", "in", "the", "queue"};
   q3.print(std::cout);

   std::cout << "clear test\n";
   q3.clear();
   q3.print(std::cout);
   //#endif

   //#if 0
   queue q = {"we", "are", "waiting", "in", "the", "queue"};

   std::cout << q << "\n";

   while (q.size() > 3)
   {
      auto s = q.peek();
      std::cout << s << "\n";
      q.pop();
   }

   queue andtheygo =
       {"et", "eunt", "homines", "mirari", "alta", "montium",
        "et", "ingentes", "fluctus", "maris", "et", "latissimos", "lapsus",
        "fluminum", "et", "Oceani", "ambitum", "et", "gyros", "siderum",
        "et", "relinquunt", "se", "ipsos", "nec", "mirantur"};

   // andtheygo.print(std::cout);
   q = andtheygo;

   while (q.size())
   {
      std::cout << q.peek() << "\n";
      q.pop();
   }


   //#endif
   return 0;
}
