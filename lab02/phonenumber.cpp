
#include "phonenumber.h"

bool PhoneNumber::iswellformed( ) const 
{
    int len = nr.length();
    if (len>20 || len<10){
        return false;
    }
    if (nr[0] != '+'){
        return false;
    }
    for (int i=1; i<len; i++){
        if (!isdigit(nr[i])){
            return false;
        }
    }
    return true;            
}

 
