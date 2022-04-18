
#include <iostream>
#include <vector>

#include "timetable.h"
#include "sorting.h"
#include "stack.h"
#include "timer.h"

int main(int argc, char *argv[])
{

   //#if 1
   timetable heap_times("heapsort");
   timetable quick_times("quicksort from library");
   timetable bubble_times("bubblesort");
   timetable insertion_times("insertion sort");

   // My experience from earlier, similar tasks is that doubling
   // is much more informative than adding a fixed step.

   for (size_t s = 10000; s < 100000; s *= 2)
   {
      std::vector<int> test = randomvector(s);

      {
         auto v = test;
         timer t;
         heap_sort(v);
         heap_times.insert(s, t.time());
      }

      {
         auto v = test;
         timer t;
         quick_sort(v);
         quick_times.insert(s, t.time());
      }

      {
         auto v = test;
         timer t;
         bubble_sort(v);
         bubble_times.insert(s, t.time());
      }

      {
         auto v = test;
         timer t;
         insertion_sort(v);
         insertion_times.insert(s, t.time());
      }
   }

   std::cout << heap_times << "\n";
   std::cout << quick_times << "\n";
   std::cout << bubble_times << "\n";
   std::cout << insertion_times << "\n";
   std::cout << "this is the total time: ";
   std::cout << heap_times.totaltime() + quick_times.totaltime() +
                    bubble_times.totaltime() +
                    insertion_times.totaltime()
             << "\n";
   insertion_times.clear();
   //#endif

   
   std::cout << "measuring performance of stack operations\n";
   timetable stack_times("stack with multiplying/adding ensure_capacity");
   
   for (size_t s = 100000; s < 800000; s *= 2)
   {
      timer t;
      stack st;
      for (size_t i = 0; i != s; ++i)
         st.push(i + 17);
      while (!st.empty())
         st.pop();
      stack_times.insert(s, t.time());
      
      //delete[] st.data;
   }
   //delete[] st.data;
   std::cout << stack_times << "\n";
   stack_times.clear( );
   
   return 0;
}




// Performance table of heapsort (inputsize/runtime in seconds):
//      10000/7.7980e-04     20000/1.3789e-03     40000/2.9319e-03     80000/6.3356e-03

// Performance table of quicksort from library (inputsize/runtime in seconds):
//      10000/3.7740e-04     20000/7.3880e-04     40000/1.5921e-03     80000/3.3508e-03

// Performance table of bubblesort (inputsize/runtime in seconds):
//      10000/1.1800e-01     20000/5.0046e-01     40000/2.0977e+00     80000/8.7398e+00

// Performance table of insertion sort (inputsize/runtime in seconds):
//      10000/2.2930e-02     20000/9.0642e-02     40000/3.6197e-01     80000/1.7780e+00

// this is the total time: 1.3727e+01

//Average total time: 13.82975 s
//test 1: 1.3727e+01 s
//test 2: 1.3492e+01 s
//test 3: 1.4050e+01 s
//test 4: 1.4050e+01 s

//Big O:
// Heap sort: worst case O(nlogn)
// bubble sort: worst case O(n^2)
// Quicksort: worst case O(logn)
// Insertion sort: worst case O(n^2)

// Stack operations 
// Performance table of stack with multiplying ensure_capacity (inputsize/runtime in seconds):
//  100000/3.9001e-02     200000/1.4283e-01     400000/6.0144e-01
// Performance table of stack with multiplying ensure_capacity (inputsize/runtime in seconds):
//      100000/2.2192e-03     200000/4.9242e-03     400000/9.4731e-03

//Doubling capacity is much more effective