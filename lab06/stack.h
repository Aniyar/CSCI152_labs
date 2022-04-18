
#ifndef STACK_ 
#define STACK_  1

#include <iostream>
#include <initializer_list>
#include <algorithm>

class stack 
{
   size_t current_size;
   size_t current_capacity; 

   double* data; 
      // INVARIANT: data is an allocated memory block
      // with size current_capacity. We are not sharing it. 
      // current_size <= current_capacity. 

   void ensure_capacity( size_t c );
      // Ensure that stack has capacity of at least c.
  
public: 
   stack( );               
      // Constructs empty stack. 

   stack( const stack& s );

   ~stack( );

   const stack& operator = ( const stack& s );

   stack( std::initializer_list<double> init );
      // So that you can write s = { 1,2,3 }; 
      // In this example, 3 will become top of stack. 
      // You need d. size( ) and for( double d : s ) ....
  
   void push( double d );  

   void pop( );

   void clear( );

   void reset( size_t s ); 

   double peek( ) const;

   size_t size( ) const; 

   bool empty( ) const; 

   void print( std::ostream& out ) const;

   friend int main( int argc, char* argv[] );
}; 


inline std::ostream& operator << ( std::ostream& out, const stack& st )
{
   st. print( out );
   return out;
}

#endif


