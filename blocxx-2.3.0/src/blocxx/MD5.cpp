/*******************************************************************************
* Copyright (C) 2005, Quest Software, Inc. All rights reserved.
* Copyright (C) 2006, Novell, Inc. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
*     * Redistributions of source code must retain the above copyright notice,
*       this list of conditions and the following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright
*       notice, this list of conditions and the following disclaimer in the
*       documentation and/or other materials provided with the distribution.
*     * Neither the name of
*       Quest Software, Inc.,
*       nor Novell, Inc.,
*       nor the names of its contributors or employees may be used to
*       endorse or promote products derived from this software without
*       specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/


/**
 * @author Bart Whiteley
 * @author Dan Nuffer
 */

#include "blocxx/BLOCXX_config.h"
#include "blocxx/MD5.hpp"
#include "blocxx/String.hpp"
#include "blocxx/ExceptionIds.hpp"

#include <string.h> // for memset

#ifdef BLOCXX_WIN32
#pragma warning (push)
#pragma warning (disable: 4355)
#endif

namespace BLOCXX_NAMESPACE
{

const int MD5HASHHEXLEN = 32;

BLOCXX_DEFINE_EXCEPTION_WITH_ID(MD5);
//////////////////////////////////////////////////////////////////////////////
MD5OStreamBase::MD5OStreamBase(MD5* md5): _buf(md5) {}
//////////////////////////////////////////////////////////////////////////////
MD5StreamBuffer::MD5StreamBuffer(MD5* md5): _md5(md5) {}
//////////////////////////////////////////////////////////////////////////////
MD5StreamBuffer::~MD5StreamBuffer() {}
//////////////////////////////////////////////////////////////////////////////
int
MD5StreamBuffer::overflow(int c)
{
	unsigned char lc = c;
	MD5::MD5Update(&(_md5->m_ctx), &lc, 1);
	return c;
}
//////////////////////////////////////////////////////////////////////////////
std::streamsize
MD5StreamBuffer::xsputn(const char* s, std::streamsize num)
{
	MD5::MD5Update(&(_md5->m_ctx),
							reinterpret_cast<const unsigned char*>(s), num);
	return num;
}
//////////////////////////////////////////////////////////////////////////////
MD5::MD5()
: MD5OStreamBase(this), std::ostream(&_buf), m_ctx(), m_finished(false)
{
	MD5Init(&m_ctx);
}
//////////////////////////////////////////////////////////////////////////////
MD5::~MD5()
{
}
//////////////////////////////////////////////////////////////////////////////
void
MD5::init(const String& input)
{
	m_finished = false;
	MD5Init(&m_ctx);
	update(input);
}
//////////////////////////////////////////////////////////////////////////////
MD5::MD5(const String& input)
: MD5OStreamBase(this), std::ostream(&_buf), m_ctx(), m_finished(false)
{
	MD5Init(&m_ctx);
	update(input);
}
//////////////////////////////////////////////////////////////////////////////
void
MD5::update(const String& input)
{
	if (m_finished)
	{
		BLOCXX_THROW(MD5Exception, "Cannot update after a call to toString()");
	}
	MD5Update(&m_ctx, reinterpret_cast<const unsigned char*>(input.c_str()),
				 input.length());
}
//////////////////////////////////////////////////////////////////////////////
String
MD5::toString()
{
	return convertBinToHex(getDigest());
}
//////////////////////////////////////////////////////////////////////////////
unsigned char*
MD5::getDigest()
{
	if (!m_finished)
	{
		MD5Final(m_digest, &m_ctx);
		m_finished = true;
	}
	return m_digest;
}
//////////////////////////////////////////////////////////////////////////////
String
MD5::convertBinToHex( const unsigned char* sBin)
{
	unsigned short i;
	unsigned char j;
	char Hex[ MD5HASHHEXLEN + 1 ];
	for ( i = 0; i < MD5HASHLEN; i++ )
	{
		j = (sBin[i] >> 4) & 0xf;
		if ( j <= 9 )
		{
			Hex[i*2] = (j + '0');
		}
		else
		{
			Hex[i*2]	= (j + 'a' - 10);
		}
		j = sBin[i] & 0xf;
		if ( j <= 9 )
		{
			Hex[i*2+1] = (j + '0');
		}
		else
		{
			Hex[i*2+1] = (j + 'a' - 10);
		}
	};
	Hex[MD5HASHHEXLEN] = '\0';
	return String(Hex);
};
//A.3 md5c.c
/* MD5C.C - RSA Data Security, Inc., MD5 message-digest algorithm
 */
/* Copyright (C) 1991-2, RSA Data Security, Inc. Created 1991. All
rights reserved.
License to copy and use this software is granted provided that it
is identified as the "RSA Data Security, Inc. MD5 Message-Digest
Algorithm" in all material mentioning or referencing this software
or this function.
License is also granted to make and use derivative works provided
that such works are identified as "derived from the RSA Data
Security, Inc. MD5 Message-Digest Algorithm" in all material
mentioning or referencing the derived work.
RSA Data Security, Inc. makes no representations concerning either
the merchantability of this software or the suitability of this
software for any particular purpose. It is provided "as is"
without express or implied warranty of any kind.
These notices must be retained in any copies of any part of this
documentation and/or software.
 */
/* POINTER defines a generic pointer type */
typedef unsigned char *POINTER;
/* Constants for MD5Transform routine.
 */
#define S11 7
#define S12 12
#define S13 17
#define S14 22
#define S21 5
#define S22 9
#define S23 14
#define S24 20
#define S31 4
#define S32 11
#define S33 16
#define S34 23
#define S41 6
#define S42 10
#define S43 15
#define S44 21
static void MD5Transform(UInt32*, const unsigned char*);
static void Encode(unsigned char *, UInt32 *, UInt32);
static void Decode(UInt32 *, const unsigned char *, UInt32);
//static void MD5_memcpy(POINTER, POINTER, UInt32);
//static void MD5_memset(POINTER, Int32, UInt32);
static unsigned char PADDING[64] = {
	0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};
/* F, G, H and I are basic MD5 functions.
 */
#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))
/* ROTATE_LEFT rotates x left n bits.
 */
#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32-(n))))
/* FF, GG, HH, and II transformations for rounds 1, 2, 3, and 4.
Rotation is separate from addition to prevent recomputation.
 */
#define FF(a, b, c, d, x, s, ac) { \
 (a) += F ((b), (c), (d)) + (x) + static_cast<UInt32>(ac); \
 (a) = ROTATE_LEFT ((a), (s)); \
 (a) += (b); \
  }
#define GG(a, b, c, d, x, s, ac) { \
 (a) += G ((b), (c), (d)) + (x) + static_cast<UInt32>(ac); \
 (a) = ROTATE_LEFT ((a), (s)); \
 (a) += (b); \
  }
#define HH(a, b, c, d, x, s, ac) { \
 (a) += H ((b), (c), (d)) + (x) + static_cast<UInt32>(ac); \
 (a) = ROTATE_LEFT ((a), (s)); \
 (a) += (b); \
  }
#define II(a, b, c, d, x, s, ac) { \
 (a) += I ((b), (c), (d)) + (x) + static_cast<UInt32>(ac); \
 (a) = ROTATE_LEFT ((a), (s)); \
 (a) += (b); \
  }
/* MD5 initialization. Begins an MD5 operation, writing a new context.
 */ // STATIC
void
	MD5::MD5Init(MD5_CTX* context)
{
	context->count[0] = context->count[1] = 0;
	/* Load magic initialization constants.
 */
	context->state[0] = 0x67452301;
	context->state[1] = 0xefcdab89;
	context->state[2] = 0x98badcfe;
	context->state[3] = 0x10325476;
}
/* MD5 block update operation. Continues an MD5 message-digest
  operation, processing another message block, and updating the
  context.
 */ // STATIC
void
	MD5::MD5Update(MD5_CTX* context, const unsigned char* input,
	UInt32 inputLen)
{
	UInt32 i, index, partLen;
	/* Compute number of bytes mod 64 */
	index = ((context->count[0] >> 3) & 0x3F);
	/* Update number of bits */
	if ((context->count[0] += (inputLen << 3)) < (inputLen << 3))
	{
		context->count[1]++;
	}
	context->count[1] += (inputLen >> 29);
	partLen = 64 - index;
	/* Transform as many times as possible.
 */
	if (inputLen >= partLen)
	{
		memcpy(static_cast<POINTER>(&context->buffer[index]),
			static_cast<const unsigned char*>(input), partLen);
		MD5Transform (context->state, context->buffer);
		for (i = partLen; i + 63 < inputLen; i += 64)
			MD5Transform (context->state, &input[i]);
		index = 0;
	}
	else
		i = 0;
	/* Buffer remaining input */
	memcpy
		(static_cast<POINTER>(&context->buffer[index]),
			static_cast<const unsigned char*>(&input[i]),
		inputLen-i);
}
/* MD5 finalization. Ends an MD5 message-digest operation, writing the
  the message digest and zeroizing the context.
 */ // STATIC
void
	MD5::MD5Final (unsigned char* digest, MD5_CTX* context)
{
	unsigned char bits[8];
	UInt32 index, padLen;
	/* Save number of bits */
	Encode (bits, context->count, 8);
	/* Pad out to 56 mod 64.
 */
	index = ((context->count[0] >> 3) & 0x3f);
	padLen = (index < 56) ? (56 - index) : (120 - index);
	MD5Update (context, PADDING, padLen);
	/* Append length (before padding) */
	MD5Update (context, bits, 8);
	/* Store state in digest */
	Encode (digest, context->state, 16);
	/* Zeroize sensitive information.
 */
	memset (reinterpret_cast<POINTER>(context), 0, sizeof (*context));
}
/* MD5 basic transformation. Transforms state based on block.
 */
static void MD5Transform (UInt32* state, const unsigned char* block)
{
	UInt32 a = state[0], b = state[1], c = state[2], d = state[3], x[16];
	Decode (x, block, 64);
	/* Round 1 */
	FF (a, b, c, d, x[ 0], S11, 0xd76aa478); /* 1 */
	FF (d, a, b, c, x[ 1], S12, 0xe8c7b756); /* 2 */
	FF (c, d, a, b, x[ 2], S13, 0x242070db); /* 3 */
	FF (b, c, d, a, x[ 3], S14, 0xc1bdceee); /* 4 */
	FF (a, b, c, d, x[ 4], S11, 0xf57c0faf); /* 5 */
	FF (d, a, b, c, x[ 5], S12, 0x4787c62a); /* 6 */
	FF (c, d, a, b, x[ 6], S13, 0xa8304613); /* 7 */
	FF (b, c, d, a, x[ 7], S14, 0xfd469501); /* 8 */
	FF (a, b, c, d, x[ 8], S11, 0x698098d8); /* 9 */
	FF (d, a, b, c, x[ 9], S12, 0x8b44f7af); /* 10 */
	FF (c, d, a, b, x[10], S13, 0xffff5bb1); /* 11 */
	FF (b, c, d, a, x[11], S14, 0x895cd7be); /* 12 */
	FF (a, b, c, d, x[12], S11, 0x6b901122); /* 13 */
	FF (d, a, b, c, x[13], S12, 0xfd987193); /* 14 */
	FF (c, d, a, b, x[14], S13, 0xa679438e); /* 15 */
	FF (b, c, d, a, x[15], S14, 0x49b40821); /* 16 */
	/* Round 2 */
	GG (a, b, c, d, x[ 1], S21, 0xf61e2562); /* 17 */
	GG (d, a, b, c, x[ 6], S22, 0xc040b340); /* 18 */
	GG (c, d, a, b, x[11], S23, 0x265e5a51); /* 19 */
	GG (b, c, d, a, x[ 0], S24, 0xe9b6c7aa); /* 20 */
	GG (a, b, c, d, x[ 5], S21, 0xd62f105d); /* 21 */
	GG (d, a, b, c, x[10], S22,  0x2441453); /* 22 */
	GG (c, d, a, b, x[15], S23, 0xd8a1e681); /* 23 */
	GG (b, c, d, a, x[ 4], S24, 0xe7d3fbc8); /* 24 */
	GG (a, b, c, d, x[ 9], S21, 0x21e1cde6); /* 25 */
	GG (d, a, b, c, x[14], S22, 0xc33707d6); /* 26 */
	GG (c, d, a, b, x[ 3], S23, 0xf4d50d87); /* 27 */
	GG (b, c, d, a, x[ 8], S24, 0x455a14ed); /* 28 */
	GG (a, b, c, d, x[13], S21, 0xa9e3e905); /* 29 */
	GG (d, a, b, c, x[ 2], S22, 0xfcefa3f8); /* 30 */
	GG (c, d, a, b, x[ 7], S23, 0x676f02d9); /* 31 */
	GG (b, c, d, a, x[12], S24, 0x8d2a4c8a); /* 32 */
	/* Round 3 */
	HH (a, b, c, d, x[ 5], S31, 0xfffa3942); /* 33 */
	HH (d, a, b, c, x[ 8], S32, 0x8771f681); /* 34 */
	HH (c, d, a, b, x[11], S33, 0x6d9d6122); /* 35 */
	HH (b, c, d, a, x[14], S34, 0xfde5380c); /* 36 */
	HH (a, b, c, d, x[ 1], S31, 0xa4beea44); /* 37 */
	HH (d, a, b, c, x[ 4], S32, 0x4bdecfa9); /* 38 */
	HH (c, d, a, b, x[ 7], S33, 0xf6bb4b60); /* 39 */
	HH (b, c, d, a, x[10], S34, 0xbebfbc70); /* 40 */
	HH (a, b, c, d, x[13], S31, 0x289b7ec6); /* 41 */
	HH (d, a, b, c, x[ 0], S32, 0xeaa127fa); /* 42 */
	HH (c, d, a, b, x[ 3], S33, 0xd4ef3085); /* 43 */
	HH (b, c, d, a, x[ 6], S34,  0x4881d05); /* 44 */
	HH (a, b, c, d, x[ 9], S31, 0xd9d4d039); /* 45 */
	HH (d, a, b, c, x[12], S32, 0xe6db99e5); /* 46 */
	HH (c, d, a, b, x[15], S33, 0x1fa27cf8); /* 47 */
	HH (b, c, d, a, x[ 2], S34, 0xc4ac5665); /* 48 */
	/* Round 4 */
	II (a, b, c, d, x[ 0], S41, 0xf4292244); /* 49 */
	II (d, a, b, c, x[ 7], S42, 0x432aff97); /* 50 */
	II (c, d, a, b, x[14], S43, 0xab9423a7); /* 51 */
	II (b, c, d, a, x[ 5], S44, 0xfc93a039); /* 52 */
	II (a, b, c, d, x[12], S41, 0x655b59c3); /* 53 */
	II (d, a, b, c, x[ 3], S42, 0x8f0ccc92); /* 54 */
	II (c, d, a, b, x[10], S43, 0xffeff47d); /* 55 */
	II (b, c, d, a, x[ 1], S44, 0x85845dd1); /* 56 */
	II (a, b, c, d, x[ 8], S41, 0x6fa87e4f); /* 57 */
	II (d, a, b, c, x[15], S42, 0xfe2ce6e0); /* 58 */
	II (c, d, a, b, x[ 6], S43, 0xa3014314); /* 59 */
	II (b, c, d, a, x[13], S44, 0x4e0811a1); /* 60 */
	II (a, b, c, d, x[ 4], S41, 0xf7537e82); /* 61 */
	II (d, a, b, c, x[11], S42, 0xbd3af235); /* 62 */
	II (c, d, a, b, x[ 2], S43, 0x2ad7d2bb); /* 63 */
	II (b, c, d, a, x[ 9], S44, 0xeb86d391); /* 64 */
	state[0] += a;
	state[1] += b;
	state[2] += c;
	state[3] += d;
	/* Zeroize sensitive information. */
	memset (reinterpret_cast<POINTER>(x), 0, sizeof (x));
}
/* Encodes input (UInt32) into output (unsigned char). Assumes len is
  a multiple of 4.
 */
static void Encode (unsigned char* output, UInt32* input, UInt32 len)
{
	UInt32 i, j;
	for (i = 0, j = 0; j < len; i++, j += 4)
	{
		output[j] = (input[i] & 0xff);
		output[j+1] = ((input[i] >> 8) & 0xff);
		output[j+2] = ((input[i] >> 16) & 0xff);
		output[j+3] = ((input[i] >> 24) & 0xff);
	}
}
/* Decodes input (unsigned char) into output (UInt32). Assumes len is
  a multiple of 4.
 */
static void Decode (UInt32* output, const unsigned char* input, UInt32 len)
{
	UInt32 i, j;
	for (i = 0, j = 0; j < len; i++, j += 4)
		output[i] = (static_cast<UInt32>(input[j])) | ((static_cast<UInt32>(input[j+1])) << 8) |
			((static_cast<UInt32>(input[j+2])) << 16) | ((static_cast<UInt32>(input[j+3])) << 24);
}
/* Note: Replace "for loop" with standard memcpy if possible.
 */
//static void MD5_memcpy (POINTER output, POINTER input, UInt32 len)
//{
	//UInt32 i;
	//for (i = 0; i < len; i++)
	//	output[i] = input[i];
//}
/* Note: Replace "for loop" with standard memset if possible. */
//static void MD5_memset (POINTER output, Int32 value, UInt32 len)
//{
	//UInt32 i;
	//for (i = 0; i < len; i++)
	//	((char *)output)[i] = (char)value;
//}

} // end namespace BLOCXX_NAMESPACE


#ifdef BLOCXX_WIN32
#pragma warning (pop)
#endif

