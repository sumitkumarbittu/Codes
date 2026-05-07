%{
#include "y.tab.h"
%}

%%

a       { return A; }
b       { return B; }
\n      { return NL; }
[ \t]   { /* ignore spaces */ }
.       { return INVALID; }

%%

int yywrap()
{
    return 1;
}