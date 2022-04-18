
#include "stack.h"

size_t pow(int e, int p){
   size_t res = 1;
   for (int i=0; i<p; i++){
      res *= e;
   }
   return res;
}

void stack::ensure_capacity(size_t c)
{
   if (c <= current_capacity)
   {
      return;
   }
   int p = 1;
   while (p < c)
   {
      p *= 2;
   }
   current_capacity = p;
   // std::cout << current_capacity << "\n";
   double *new_arr;
   new_arr = new double[current_capacity];
   std::copy(data, data + current_size, new_arr);
   data = new_arr;
   return;
}
   // Keep current_capacity always in powers of two.

stack::stack( ) :
   current_size(0),
   current_capacity(4),
   data(new double[4])
   {
   }
   // Constructs empty stack. 

stack::stack( const stack& s ) :
   current_size(s.current_size),
   current_capacity(s.current_capacity),
   data(new double[s.current_capacity])   
{
   ensure_capacity(s.current_size);
   std::copy(s.data, s.data+s.current_size, data);
}
   // use std::copy

stack::stack( std::initializer_list< double > init ) :
   current_size(0),
   current_capacity(init.size()),
   data(new double[init.size()])
{
   for (double elem : init){
      push(elem);
   }
} 

const stack& stack::operator = ( const stack& s )   
{
   current_size = s.current_size;
   ensure_capacity(s.current_size);
   std::copy(s.data, s.data+current_size, data);
   return *this;
}
   // use ensure_capacity and std::copy. 

stack::~stack( ){
   current_size = 0;
   current_capacity = 0;
   delete [] data;
}

void stack::push( double d )
{
   ensure_capacity(current_size+1);
   data[current_size++] = d;
}
  

   // 1. either use push( ), or 
   // 2. ensure_capacity.
  
void stack::pop( ){
   if (!empty()){
      current_size -= 1;
      return;
   }
   throw std::runtime_error( "pop: stack is empty" );
}

void stack::clear( ){
   current_size = 0;
}

void stack::reset( size_t s ){
   current_size = s;
}

double stack::peek( ) const{
   if (!empty()){
      return data[current_size-1];
   }
   throw std::runtime_error( "pop: stack is empty" );
}

size_t stack::size( ) const{
   return current_size;
}

bool stack::empty( ) const{
   if (current_size > 0){
      return false;
   }
   return true;
}

void stack::print( std::ostream& out ) const{
   for (int i = 0; i < current_size; i++){
      out << data[i];
      if (i+1 != current_size){
         out << ", ";
      }
   }
   out << "\n";
} 


