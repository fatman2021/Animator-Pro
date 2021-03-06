#include <ctype.h>
#include "stdtypes.h"

int txtcmp(register char *as, register char *bs)

/* like strcmp but case insensitive */
{
register UBYTE a, b;

	for(;;)
	{
		a = *as++;
		b = *bs++;
		if(a == 0)
			break;

		if (islower(a))
			a = _toupper(a);
		if (islower(b))
			b = _toupper(b);
		if (a != b)
			break;
	}
	return(a-b);
}
