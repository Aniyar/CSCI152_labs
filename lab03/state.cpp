
#include "state.h"
#include <string>

state::state( std::initializer_list< unsigned int > init )
{
   size_t i = 0;
   for (int val : init){
      sticks.push_back(val);
      ++i;
   }
}   

state::state( unsigned int i1, unsigned int i2 ){
   size_t i = i1;
   while(i <= i2){
      sticks.push_back(i);
      ++i;
   }
}

unsigned int state::sum( ) const{
   int sum = 0;
   for (int i=0; i<sticks.size(); i++){
      sum += sticks[i];
   }
   return sum;
}

optional_move state::randommove( ) const {
   if (sum() == 0){
      return optional_move();
   }
   int row = rand()%(sticks.size());
   while (sticks[row] == 0){
      row = rand()%(sticks.size());
   }
   int remaining;
   bool legal = false;
   while (!legal){  
      if (sticks[row] > 1){
         remaining = sticks[row] - 1 - rand()%(sticks[row]);
         legal = true;
      }
      else if (sticks[row] == 1){
         remaining = 0;
         legal = true;
      }
   }
   move m(row, remaining);
   return optional_move(m);
}

void state::make( move m ){
   if (sticks[m.row] < m.remaining){
      std::abort;
   }
   sticks[m.row] = m.remaining;
}

void state::print( std::ostream& out ) const {
   for(int i = 0; i<sticks.size(); i++){
      out << i+1 << "\t:";
      for(int j=0; j<sticks[i]; j++){
         out << " " << 1;
      }
      out << "\n";
   }
}


optional_move state::usermove( std::ostream& out, std::istream& in ) const
{

   if( sum( ))
   {
      while( true )
      {
         std::string inp;
         try
         {
            out << "row? "; out. flush( );
            in >> inp; 

            unsigned int row = std::stoul( inp ); inp. clear( );

            if( row > 0 && row <= sticks. size( )) 
            {
               unsigned int row1 = row - 1;  // This is a type conversion! 
               if( sticks[ row1 ] )
               {
                  out << "how many remaining? "; out. flush( );
                  in >> inp; 
                  unsigned int remain = std::stoul( inp ); inp. clear( ); 

                  if( remain < sticks[ row1 ] )
                     return move( row1, remain );
                  else
                  {
                     out << "having " << remain 
                         << " remaining is not possible, "
                         << "you have to remove at least one stick\n";
                  }
               }
               else 
               {
                  out << "row " << row << " is already empty\n";
               }
            }
            else
            {
               out << "row " << row << " is not a valid row, ";
               out << "rows are between 1 and " << sticks. size( ) << "\n";
            }
            
         }
         catch( std::invalid_argument& inv )
         {
            out << inp << " is not a number\n";
         }
         catch( std::out_of_range& r )
         {
            out << inp << " is too big\n";
         }
      }
   }
   else
      return optional_move( ); 
}


