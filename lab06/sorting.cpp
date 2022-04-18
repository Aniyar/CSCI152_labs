
#include "sorting.h"
#include <algorithm>

std::ostream& 
operator << ( std::ostream& out, const std::vector< int > & vect ) 
{
   out << "{ ";
   for( auto p = vect. begin( ); p != vect. end( ); ++ p )
   {
      if( p != vect. begin( ))
         out << ", ";
      out << *p;
   }
   out << " }";
   return out;
}

std::vector< int > randomvector( size_t k )
{
   std::vector< int > res;
   for( size_t i = 0; i != k; ++ i )
      res. push_back( rand( ));
   return res;
}

void bubble_sort( std::vector< int > & vect )
{
   if( vect. size( ) < 2 ) return;
      // Every shorter vector is sorted.

   bool sorted = false;
   while( !sorted ) 
   {
      sorted = true; 
      for( size_t i = 0; i + 1 != vect. size( ); ++ i )
      {
         if( vect[i] > vect[i+1] )
         {
            std::swap( vect[i], vect[i+1] );
            sorted = false;
         }
      }
   }

}


namespace
{

   void restore_heap( std::vector< int > & vect, size_t s )
   {
      size_t p = 0;
      while( 2 * p + 1 < s )
      {
         if( 2 * p + 2 == s )
         {
            if( vect[p] < vect[ 2 * p + 1 ] )
            std::swap( vect[p], vect[ 2 * p + 1 ] );
            return; 
         }
         else
         {
            if( vect[p] < vect[ 2 * p + 1 ] || vect[p] < vect[ 2 * p + 2 ] )
            {
               if( vect[ 2 * p + 1 ] < vect[ 2 * p + 2 ] )
               {
                  std::swap( vect[p], vect[ 2 * p + 2 ] );
                  p = 2 * p + 2;
               }
               else
               { 
                  std::swap( vect[p], vect[ 2 * p + 1 ] );
                  p = 2 * p + 1;
               }
            }
            else
               return; 
         }
      }
   }

}


void heap_sort( std::vector< int > & vect )
{
   if( vect. size( ) < 2 ) return;
      // Every shorter vector is sorted.

   // In the first pass, we establish the heap condition:

   for( size_t i = 1; i != vect. size( ); ++ i )
   {
      for( size_t p = i; p != 0; p = ( p - 1 ) / 2 )
      {
         if( vect[p] > vect[ ( p-1 ) / 2 ] )
            std::swap( vect[p], vect[ ( p - 1 ) / 2 ] );
      }      
   }

   size_t i = vect. size( );
   while(i)
   {
      -- i;
      std::swap( vect[0], vect[i] );
     
      // And we restore heap condition between 0 and i: 

      restore_heap( vect, i ); 
   }

}


namespace
{
   std::vector< int > :: iterator 
   findmin( std::vector< int > :: iterator p1,
            std::vector< int > :: iterator p2 )
   {
      if( p1 == p2 ) 
         return p2;

      auto min = p1 ++ ;
      while( p1 != p2 )
      {
         if( *p1 < *min )
            min = p1;
         ++ p1;
      }

      return min; 
   }
}

void insertion_sort( std::vector< int > & vect ) 
{
   for( auto p = vect. begin( ); p != vect. end( ); ++ p ) 
   {
      auto m = findmin( p, vect. end( )); 
      std::swap( *p, *m ); 
   }
}


void quick_sort( std::vector< int > & vect )
{
   std::sort(vect.begin(), vect.end());
   //throw std::runtime_error( "you have to write this" ); 
}


