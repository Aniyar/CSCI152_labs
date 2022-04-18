
#ifndef SET_
#define SET_

#include <iostream>
#include <string> 

// It is good to have a look at the list-based implementation
// of queue again. The implementation here is very similar.

struct treenode
{
   std::string value; 
   treenode* left;
   treenode* right;

   treenode( const std::string& value, 
             treenode* left = nullptr, treenode* right = nullptr )
      : value( value ),
        left( left ),
        right( right )  
   { }

};


const treenode* find( const treenode* n, const std::string& s );
   // Returns nullptr if not found.

treenode** find( treenode** n, const std::string& s ); 
   // Returns a pointer to nullptnr if not found. 

size_t size( const treenode* n ); 
   // Returns the number of values stored in the tree. 

void deallocate( treenode* n ); 
   // Deallocate the complete tree below n.

treenode* makecopy( const treenode* n );
   // Make a copy of the tree below n.

void print( std::ostream& out, const treenode* n, unsigned int indent );
   // Print the tree as tree.

size_t height( const treenode* n );
   // Returns the height of the tree starting at n.

unsigned int log_base2( size_t s );


class set
{
   treenode* tr;

public: 
   set( ) 
      : tr( nullptr ) 
   { } 

   set( const set& other );

   set& operator = ( const set& other );

   ~set( );

   set( std::initializer_list< std::string > init )
      : tr( nullptr ) 
   {
      for( const auto& s: init ) 
         insert(s);
   } 
  
   bool contains( const std::string& s ) const;

   bool insert( const std::string& s );
      // Returns true if the insertion took place.

   size_t size( ) const; 
   size_t height( ) const; 

   bool empty( ) const; 
      // Must work in constant time!

   void clear( );

   void checksorted( ) const;
      // Check if the tree is sorted, and throw an exception
      // if it is not. Call this function often to check your
      // trees, but make your final performance tests without it.  

   void print( std::ostream& out, unsigned int indent = 0 ) const;
};


inline std::ostream& operator << ( std::ostream& out, const set& s )
{
   s. print( out );
   return out; 
}

#endif

