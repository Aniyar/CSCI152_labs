
// automatically generated code:
// Generator written by Hans de Nivelle and Dina Muktubayeva.

template< typename S >
std::pair< inputtype, size_t > readandclassify( int triv, S& inp )
{
   auto latest = std::make_pair< inputtype, size_t > ( inp_garbage, 0 );
   if( !inp. has(1))
      return latest;
   char c = inp. peek(0);
   size_t i = 0;

Q00:
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   switch( c )
   {
   case 13:
   case 32:
      ++ i; goto Q01;
   case 37:
      ++ i; goto Q02;
   case 42:
      ++ i; goto Q03;
   case 43:
      ++ i; goto Q04;
   case 45:
      ++ i; goto Q05;
   case 47:
      ++ i; goto Q06;
   case 48:
      ++ i; goto Q07;
   case 61:
      ++ i; goto Q09;
   case 94:
      ++ i; goto Q10;
   case 97:
      ++ i; goto Q11;
   case 99:
      ++ i; goto Q12;
   case 101:
      ++ i; goto Q13;
   case 108:
      ++ i; goto Q14;
   case 112:
      ++ i; goto Q15;
   case 115:
      ++ i; goto Q16;
   case 116:
      ++ i; goto Q17;
   case 44:
   case 46:
   case 98:
   case 100:
      return latest;
   }
   if( c >= 11 )
   {
      if( c >= 58 ) return latest;
      if( c >= 49 ) { ++ i; goto Q08; }
      if( true ) return latest;
   }
   else
   {
      if( c >= 9 ) { ++ i; goto Q01; }
      if( true ) return latest;
   }
Q01:
   latest. first = inp_whitespace; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 13 || c == 32 ) { ++ i; goto Q01; }
   if( c >= 11 ) return latest;
   if( c >= 9 ) { ++ i; goto Q01; }
   if( true ) return latest;
Q02:
   latest. first = inp_mod; latest. second = i;
   return latest;
Q03:
   latest. first = inp_times; latest. second = i;
   return latest;
Q04:
   latest. first = inp_plus; latest. second = i;
   return latest;
Q05:
   latest. first = inp_minus; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 48 ) { ++ i; goto Q07; }
   if( c >= 58 ) return latest;
   if( c >= 49 ) { ++ i; goto Q08; }
   if( true ) return latest;
Q06:
   latest. first = inp_div; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 42 ) { ++ i; goto Q18; }
   if( c == 47 ) { ++ i; goto Q19; }
   if( true ) return latest;
Q07:
   latest. first = inp_num; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 46 ) { ++ i; goto Q20; }
   if( c == 69 || c == 101 ) { ++ i; goto Q21; }
   if( true ) return latest;
Q08:
   latest. first = inp_num; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   switch( c )
   {
   case 46:
      ++ i; goto Q20;
   case 69:
   case 101:
      ++ i; goto Q21;
   case 47:
      return latest;
   }
   if( c >= 58 ) return latest;
   if( c >= 48 ) { ++ i; goto Q08; }
   if( true ) return latest;
Q09:
   latest. first = inp_end; latest. second = i;
   return latest;
Q10:
   latest. first = inp_pow; latest. second = i;
   return latest;
Q11:
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 98 ) { ++ i; goto Q22; }
   if( true ) return latest;
Q12:
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 111 ) { ++ i; goto Q23; }
   if( true ) return latest;
Q13:
   latest. first = inp_e; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 120 ) { ++ i; goto Q24; }
   if( true ) return latest;
Q14:
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 111 ) { ++ i; goto Q25; }
   if( true ) return latest;
Q15:
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 105 ) { ++ i; goto Q26; }
   if( true ) return latest;
Q16:
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 105 ) { ++ i; goto Q27; }
   if( c == 113 ) { ++ i; goto Q28; }
   if( true ) return latest;
Q17:
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 97 ) { ++ i; goto Q29; }
   if( true ) return latest;
Q18:
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 42 ) { ++ i; goto Q30; }
   if( true ) { ++ i; goto Q18; }
Q19:
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 10 ) { ++ i; goto Q31; }
   if( true ) { ++ i; goto Q19; }
Q20:
   latest. first = inp_num; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 69 || c == 101 ) { ++ i; goto Q21; }
   if( c >= 58 ) return latest;
   if( c >= 48 ) { ++ i; goto Q20; }
   if( true ) return latest;
Q21:
   latest. first = inp_num; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 43 || c == 45 ) { ++ i; goto Q32; }
   if( c == 44 ) return latest;
   if( c >= 58 ) return latest;
   if( c >= 48 ) { ++ i; goto Q33; }
   if( true ) return latest;
Q22:
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 115 ) { ++ i; goto Q34; }
   if( true ) return latest;
Q23:
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 115 ) { ++ i; goto Q35; }
   if( true ) return latest;
Q24:
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 112 ) { ++ i; goto Q36; }
   if( true ) return latest;
Q25:
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 103 ) { ++ i; goto Q37; }
   if( true ) return latest;
Q26:
   latest. first = inp_pi; latest. second = i;
   return latest;
Q27:
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 110 ) { ++ i; goto Q38; }
   if( true ) return latest;
Q28:
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 114 ) { ++ i; goto Q39; }
   if( true ) return latest;
Q29:
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 110 ) { ++ i; goto Q40; }
   if( true ) return latest;
Q30:
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 42 ) { ++ i; goto Q30; }
   if( c == 47 ) { ++ i; goto Q31; }
   if( true ) { ++ i; goto Q18; }
Q31:
   latest. first = inp_comment; latest. second = i;
   return latest;
Q32:
   latest. first = inp_num; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c >= 58 ) return latest;
   if( c >= 48 ) { ++ i; goto Q33; }
   if( true ) return latest;
Q33:
   latest. first = inp_num; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c >= 58 ) return latest;
   if( c >= 48 ) { ++ i; goto Q41; }
   if( true ) return latest;
Q34:
   latest. first = inp_abs; latest. second = i;
   return latest;
Q35:
   latest. first = inp_cos; latest. second = i;
   return latest;
Q36:
   latest. first = inp_exp; latest. second = i;
   return latest;
Q37:
   latest. first = inp_log; latest. second = i;
   return latest;
Q38:
   latest. first = inp_sin; latest. second = i;
   return latest;
Q39:
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c == 116 ) { ++ i; goto Q42; }
   if( true ) return latest;
Q40:
   latest. first = inp_tan; latest. second = i;
   return latest;
Q41:
   latest. first = inp_num; latest. second = i;
   if( !inp. has(i+1))
      return latest;
   c = inp. peek(i);
   if( c >= 58 ) return latest;
   if( c >= 48 ) { ++ i; goto Q43; }
   if( true ) return latest;
Q42:
   latest. first = inp_sqrt; latest. second = i;
   return latest;
Q43:
   latest. first = inp_num; latest. second = i;
   return latest;
}

