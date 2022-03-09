
#include "input.h"

const char* cstring( inputtype inp )
{
   switch( inp )
   {
   case inp_plus:          return "plus";  
   case inp_minus:         return "minus"; 
   case inp_times:         return "times"; 
   case inp_div:           return "div"; 
   case inp_mod:           return "mod"; 
   case inp_pow:           return "pow";

   case inp_sin:           return "sin"; 
   case inp_cos:           return "cos";
   case inp_tan:           return "tan";    
   case inp_exp:           return "exp"; 
   case inp_log:           return "log";

   case inp_sqrt:          return "sqrt"; 
   case inp_abs:           return "abs"; 

   case inp_e:             return "e";
   case inp_pi:            return "pi";

   case inp_num:           return "num"; 
   case inp_ident:         return "ident"; 

   case inp_garbage:       return "garbage"; 
   case inp_comment:       return "comment"; 
   case inp_whitespace:    return "whitespace"; 
   case inp_end:           return "end"; 
   }

   return "???"; 
}

#include "dfa.h"

namespace
{
#if 0
   lexing::classifier< char, inputtype >
   buildclassifier( )
   {
      using namespace lexing;
      classifier< char, inputtype > cls( inp_garbage );

      // Numbers:

      auto number = just('0') | ( range('1','9') * range('0','9'). star() );

      auto exp = ( just( 'e' ) | just( 'E' )) *
                    ( just( '-' ) | just( '+' )). optional( ) *
                 ( range( '0', '9' ). optional( ) *
                   range( '0', '9' ). optional( ) *
                   range( '0', '9' ). optional( ));

      auto doubleconst = just( '-' ). optional( ) * number *
                      ( just( '.' ) *
                      ( range( '0', '9' ). star() )). optional( ) *
                        exp. optional( );

      cls.insert( doubleconst, inp_num );

      auto idfirst = range('a','z') | range('A','Z') | just( '_' );
      auto idnext = range('a','z') | range('A','Z') |
                    just('_') | range('0','9');

      auto simple_identifier = idfirst * idnext. star( );

      auto whitechar = just( ' ' ) | just( '\t' ) | just( '\n' ) | just( '\r' );
      cls. insert( whitechar. plus( ), inp_whitespace );

      cls. insert( word( "//" ) *
                ( every<char>( ). without( '\n' )). star( ) *
                  just( '\n' ), inp_comment );

      cls. insert( word( "/*" ) *
         ( every<char>( ). without( '*' ) |
            ( just('*'). plus( ) *
               every<char> ( ). without( '/' ). without( '*' )). star( )
            ). star( ) *
            just( '*' ). plus( ) * just( '/' ), inp_comment );


      cls.insert( just( '+' ), inp_plus );
      cls.insert( just( '-' ), inp_minus );
      cls.insert( just( '*' ), inp_times );
      cls.insert( just( '/' ), inp_div );
      cls.insert( just( '%' ), inp_mod );
      cls.insert( just( '^' ), inp_pow );

      cls.insert( word( "sin" ), inp_sin );
      cls.insert( word( "cos" ), inp_cos );
      cls.insert( word( "tan" ), inp_tan );
      cls.insert( word( "exp" ), inp_exp );
      cls.insert( word( "log" ), inp_log );

      cls.insert( word( "sqrt" ), inp_sqrt );
      cls.insert( word( "abs" ), inp_abs );
      cls.insert( word( "e" ), inp_e );
      cls.insert( word( "pi" ), inp_pi );

      cls. insert( word( "=" ), inp_end ); 

      cls = minimize( make_deterministic( cls ));

      {
         std::ofstream file( "dfa.h" );
         lexing::printcode< char, inputtype > (
         "char", "inputtype", "",
         cls, file,
         []( std::ostream& out, char c ) { out << (int)c; },
         []( std::ostream& out, const inputtype t ) { out << "inp_" << t; } );
      }

      return cls; 
   }
#endif
}

std::pair< inputtype, size_t > 
read( filereader& inp )
{
   // static auto cls = buildclassifier( );
   static auto cls = 100;

   if( !inp. has(1)) 
      return { inp_end, 0 };

   auto p = readandclassify( cls, inp );

   if( p. second > 0 )
      return p; 
   else
      return { inp_garbage, 1 }; 
}


