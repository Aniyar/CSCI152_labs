
// A few function that are given to the student:

#ifndef SORTING_
#define SORTING_

#include <iostream>
#include <vector>

std::ostream& 
operator << ( std::ostream& out, const std::vector< int > & vect ) ;

std::vector< int > randomvector( size_t k );
   // A random vector of size k.

void bubble_sort( std::vector< int > & vect );
void heap_sort( std::vector< int > & vect );
void insertion_sort( std::vector< int > & vect ); 
void quick_sort( std::vector< int > & vect );

#endif


