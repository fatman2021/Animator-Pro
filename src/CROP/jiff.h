#ifndef JIFF_H
#define JIFF_H

#include "jimk.h"

/* EA handy make a long from 4 chars macros redone to work with Aztec*/
#define MAKE_ID(a, b, c, d)\
	( ((long)(a)<<24) + ((long)(b)<<16) + ((long)(c)<<8) + (long)(d) )

/* these are the IFF types I deal with */
#define FORM MAKE_ID('F', 'O', 'R', 'M')
#define ILBM MAKE_ID('I', 'L', 'B', 'M')
#define BMHD MAKE_ID('B', 'M', 'H', 'D')
#define CMAP MAKE_ID('C', 'M', 'A', 'P')
#define BODY MAKE_ID('B', 'O', 'D', 'Y')
#define RIFF MAKE_ID('R', 'I', 'F', 'F')
#define VRUN MAKE_ID('V', 'R', 'U', 'N')

union bytes4
	{
	char b4_name[4];
	LONG b4_type;
	};
STATIC_ASSERT(jiff, sizeof(union bytes4) == 4);

struct iff_chunk
	{
	union bytes4 iff_type;
	LONG iff_length;
	};
STATIC_ASSERT(jiff, sizeof(struct iff_chunk) == 8);

struct form_chunk
	{
	union bytes4 fc_type; /* == FORM */
	LONG fc_length;
	union bytes4 fc_subtype;
	};
STATIC_ASSERT(jiff, sizeof(struct form_chunk) == 12);

struct BitMapHeader
	{
	UWORD w, h;
	UWORD x, y;
	UBYTE nPlanes;
	UBYTE masking;
	UBYTE compression;
	UBYTE pad1;
	UWORD transparentColor;
	UBYTE xAspect, yAspect;
	WORD pageWidth, pageHeight;
	};
STATIC_ASSERT(jiff, sizeof(struct BitMapHeader) == 20);

#endif
