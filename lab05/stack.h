
// This is a simple stack implementation.

#ifndef STACK_ 
#define STACK_

#include <iostream>
#include <initializer_list>
#include <list>

class stack 
{
   std::list< double > lst;
 
public: 
   stack( ) = default; 

   stack( std::initializer_list<double> init )
      { for( auto d : init ) push(d); }  
  
   void push( double d ) { lst. push_back(d); } 
   void pop( ) { lst. pop_back( ); } 
   void clear( ) { lst. clear( ); } 
   void reset( size_t s ) { lst. resize(s); } 
   double peek( ) const { return lst. back( ); } 
   size_t size( ) const { return lst. size( ); } 
   bool empty( ) const { return !size( ); } 

   void print( std::ostream& out ) const
   {
      out << "stack: "; 
      for( auto p = lst. begin( ); p != lst. end( ); ++ p )
      {
         if( p != lst. begin( ))
            out << ", ";  
         out << *p;    
      }
   } 
}; 

inline std::ostream& operator << ( std::ostream& out, const stack& st )
{
   st. print( out );
   return out;
}

#endif


