#include "name.h"


void Name::normalize( )
{
    n[0] = toupper(n[0]);
    for (int i=1; i<n.length(); i++){
        n[i] = tolower(n[i]);
    }
}

