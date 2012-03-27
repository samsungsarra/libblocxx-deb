/* Generated by re2c 0.13.5 on Tue Mar 27 11:15:41 2012 */
#line 1 "StringConversionImpl.re"
/*******************************************************************************
* Copyright (C) 2009, Quest Software, Inc. All rights reserved.
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
 * @author Jon Carey
 * @author Dan Nuffer
 * @author Richard Holden
 */

#include "blocxx/BLOCXX_config.h"
#include "blocxx/StringConversionImpl.hpp"
#include "blocxx/Format.hpp"

#include <cmath> // for HUGE_VAL
#include <cfloat> // for DBL_MANT_DIG
#include <limits>
#include <cstdlib>

namespace BLOCXX_NAMESPACE
{
	using std::numeric_limits;

	namespace // anonymous
	{
		template <typename T, typename FP>
		static inline
		T convertToRealTypeHelper(const String& str, const char* type, FP fp)
		{
			if (!str.empty())
			{
				const char* begin = str.c_str();
				const char* end = str.c_str() + str.length();
				const char* current = begin;
				const char* marker = begin + 1;

			start:
				if (current >= end)
				{
					goto finish;
				}
				
#line 75 "StringConversionImpl.cpp"
		{
			unsigned char yych;
			unsigned int yyaccept = 0;

			yych = (unsigned char)*current;
			switch (yych) {
			case '\t':
			case ' ':	goto yy2;
			case '+':	goto yy4;
			case '-':	goto yy6;
			case 'I':	goto yy10;
			case 'N':	goto yy8;
			case 'i':	goto yy9;
			case 'n':	goto yy7;
			default:	goto yy11;
			}
yy2:
			++current;
			yych = (unsigned char)*current;
			goto yy56;
yy3:
#line 86 "StringConversionImpl.re"
			{ marker = current + 1; goto start; }
#line 99 "StringConversionImpl.cpp"
yy4:
			yyaccept = 0;
			yych = (unsigned char)*(marker = ++current);
			switch (yych) {
			case 'I':	goto yy54;
			case 'N':	goto yy38;
			case 'i':	goto yy53;
			case 'n':	goto yy37;
			default:	goto yy5;
			}
yy5:
#line 90 "StringConversionImpl.re"
			{ goto finish; }
#line 113 "StringConversionImpl.cpp"
yy6:
			yyaccept = 0;
			yych = (unsigned char)*(marker = ++current);
			switch (yych) {
			case 'I':	goto yy36;
			case 'N':	goto yy38;
			case 'i':	goto yy35;
			case 'n':	goto yy37;
			default:	goto yy5;
			}
yy7:
			yyaccept = 0;
			yych = (unsigned char)*(marker = ++current);
			switch (yych) {
			case 'a':	goto yy34;
			default:	goto yy5;
			}
yy8:
			yyaccept = 0;
			yych = (unsigned char)*(marker = ++current);
			switch (yych) {
			case 'A':	goto yy27;
			default:	goto yy5;
			}
yy9:
			yyaccept = 0;
			yych = (unsigned char)*(marker = ++current);
			switch (yych) {
			case 'n':	goto yy21;
			default:	goto yy5;
			}
yy10:
			yyaccept = 0;
			yych = (unsigned char)*(marker = ++current);
			switch (yych) {
			case 'N':	goto yy12;
			default:	goto yy5;
			}
yy11:
			yych = (unsigned char)*++current;
			goto yy5;
yy12:
			yych = (unsigned char)*++current;
			switch (yych) {
			case 'F':	goto yy14;
			default:	goto yy13;
			}
yy13:
			current = marker;
			switch (yyaccept) {
			case 0: 	goto yy5;
			case 1: 	goto yy15;
			case 2: 	goto yy29;
			case 3: 	goto yy41;
			}
yy14:
			yyaccept = 1;
			yych = (unsigned char)*(marker = ++current);
			switch (yych) {
			case 'I':	goto yy16;
			default:	goto yy15;
			}
yy15:
#line 88 "StringConversionImpl.re"
			{ return numeric_limits<T>::infinity(); }
#line 179 "StringConversionImpl.cpp"
yy16:
			yych = (unsigned char)*++current;
			switch (yych) {
			case 'N':	goto yy17;
			default:	goto yy13;
			}
yy17:
			yych = (unsigned char)*++current;
			switch (yych) {
			case 'I':	goto yy18;
			default:	goto yy13;
			}
yy18:
			yych = (unsigned char)*++current;
			switch (yych) {
			case 'T':	goto yy19;
			default:	goto yy13;
			}
yy19:
			yych = (unsigned char)*++current;
			switch (yych) {
			case 'Y':	goto yy20;
			default:	goto yy13;
			}
yy20:
			yych = (unsigned char)*++current;
			goto yy15;
yy21:
			yych = (unsigned char)*++current;
			switch (yych) {
			case 'f':	goto yy22;
			default:	goto yy13;
			}
yy22:
			yyaccept = 1;
			yych = (unsigned char)*(marker = ++current);
			switch (yych) {
			case 'i':	goto yy23;
			default:	goto yy15;
			}
yy23:
			yych = (unsigned char)*++current;
			switch (yych) {
			case 'n':	goto yy24;
			default:	goto yy13;
			}
yy24:
			yych = (unsigned char)*++current;
			switch (yych) {
			case 'i':	goto yy25;
			default:	goto yy13;
			}
yy25:
			yych = (unsigned char)*++current;
			switch (yych) {
			case 't':	goto yy26;
			default:	goto yy13;
			}
yy26:
			yych = (unsigned char)*++current;
			switch (yych) {
			case 'y':	goto yy20;
			default:	goto yy13;
			}
yy27:
			yych = (unsigned char)*++current;
			switch (yych) {
			case 'N':	goto yy28;
			default:	goto yy13;
			}
yy28:
			yyaccept = 2;
			yych = (unsigned char)*(marker = ++current);
			switch (yych) {
			case '(':	goto yy30;
			default:	goto yy29;
			}
yy29:
#line 87 "StringConversionImpl.re"
			{ return numeric_limits<T>::quiet_NaN(); }
#line 260 "StringConversionImpl.cpp"
yy30:
			yych = (unsigned char)*++current;
			switch (yych) {
			case ')':	goto yy13;
			default:	goto yy31;
			}
yy31:
			++current;
			yych = (unsigned char)*current;
			switch (yych) {
			case ')':	goto yy33;
			default:	goto yy31;
			}
yy33:
			yych = (unsigned char)*++current;
			goto yy29;
yy34:
			yych = (unsigned char)*++current;
			switch (yych) {
			case 'n':	goto yy28;
			default:	goto yy13;
			}
yy35:
			yych = (unsigned char)*++current;
			switch (yych) {
			case 'n':	goto yy47;
			default:	goto yy13;
			}
yy36:
			yych = (unsigned char)*++current;
			switch (yych) {
			case 'N':	goto yy39;
			default:	goto yy13;
			}
yy37:
			yych = (unsigned char)*++current;
			switch (yych) {
			case 'a':	goto yy34;
			default:	goto yy13;
			}
yy38:
			yych = (unsigned char)*++current;
			switch (yych) {
			case 'A':	goto yy27;
			default:	goto yy13;
			}
yy39:
			yych = (unsigned char)*++current;
			switch (yych) {
			case 'F':	goto yy40;
			default:	goto yy13;
			}
yy40:
			yyaccept = 3;
			yych = (unsigned char)*(marker = ++current);
			switch (yych) {
			case 'I':	goto yy42;
			default:	goto yy41;
			}
yy41:
#line 89 "StringConversionImpl.re"
			{ return -numeric_limits<T>::infinity(); }
#line 323 "StringConversionImpl.cpp"
yy42:
			yych = (unsigned char)*++current;
			switch (yych) {
			case 'N':	goto yy43;
			default:	goto yy13;
			}
yy43:
			yych = (unsigned char)*++current;
			switch (yych) {
			case 'I':	goto yy44;
			default:	goto yy13;
			}
yy44:
			yych = (unsigned char)*++current;
			switch (yych) {
			case 'T':	goto yy45;
			default:	goto yy13;
			}
yy45:
			yych = (unsigned char)*++current;
			switch (yych) {
			case 'Y':	goto yy46;
			default:	goto yy13;
			}
yy46:
			yych = (unsigned char)*++current;
			goto yy41;
yy47:
			yych = (unsigned char)*++current;
			switch (yych) {
			case 'f':	goto yy48;
			default:	goto yy13;
			}
yy48:
			yyaccept = 3;
			yych = (unsigned char)*(marker = ++current);
			switch (yych) {
			case 'i':	goto yy49;
			default:	goto yy41;
			}
yy49:
			yych = (unsigned char)*++current;
			switch (yych) {
			case 'n':	goto yy50;
			default:	goto yy13;
			}
yy50:
			yych = (unsigned char)*++current;
			switch (yych) {
			case 'i':	goto yy51;
			default:	goto yy13;
			}
yy51:
			yych = (unsigned char)*++current;
			switch (yych) {
			case 't':	goto yy52;
			default:	goto yy13;
			}
yy52:
			yych = (unsigned char)*++current;
			switch (yych) {
			case 'y':	goto yy46;
			default:	goto yy13;
			}
yy53:
			yych = (unsigned char)*++current;
			switch (yych) {
			case 'n':	goto yy21;
			default:	goto yy13;
			}
yy54:
			yych = (unsigned char)*++current;
			switch (yych) {
			case 'N':	goto yy12;
			default:	goto yy13;
			}
yy55:
			++current;
			yych = (unsigned char)*current;
yy56:
			switch (yych) {
			case '\t':
			case ' ':	goto yy55;
			default:	goto yy3;
			}
		}
#line 91 "StringConversionImpl.re"


			finish:
				char* endptr(0);
				errno = 0;		// errno is thread local
				T rv = fp(str.c_str(), &endptr);
				if (*endptr != '\0' || errno == ERANGE)
				{
					BLOCXX_THROW(StringConversionException, Format("Unable to convert \"%1\" into %2", str, type).c_str());
				}
				return rv;
			}
			else
			{
				BLOCXX_THROW(StringConversionException, Format("Unable to convert \"%1\" into %2", str, type).c_str());
			}
			return T(); // to make compiler happy
		}
	}

	template<> Real32 convertToRealType<Real32>(const String& str)
	{
#if defined(BLOCXX_REAL32_IS_FLOAT) && defined(BLOCXX_HAVE_STRTOF)
		return convertToRealTypeHelper<Real32>(str, "Real32", &strtof);
#elif defined(BLOCXX_REAL32_IS_DOUBLE) || (defined(BLOCXX_REAL32_IS_FLOAT) && !defined(BLOCXX_HAVE_STRTOF))
		return convertToRealTypeHelper<Real32>(str, "Real32", &strtod);
#endif
	}

	template<> Real64 convertToRealType<Real64>(const String& str)
	{
#if defined(BLOCXX_REAL64_IS_DOUBLE)
		return convertToRealTypeHelper<Real64>(str, "Real64", &strtod);
#elif defined(BLOCXX_REAL64_IS_LONG_DOUBLE)
		return convertToRealTypeHelper<Real64>(str, "Real64", &strtold);
#endif
	}
}
