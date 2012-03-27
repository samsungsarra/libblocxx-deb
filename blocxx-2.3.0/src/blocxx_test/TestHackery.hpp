/*******************************************************************************
* Copyright (C) 2010, Quest Software, Inc. All rights reserved.
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
 * @author Kevin Harris
 */

#if       !defined(BLOCXX_TEST_HACKERY_HPP_INCLUDE_GUARD_)
#define            BLOCXX_TEST_HACKERY_HPP_INCLUDE_GUARD_

#include "blocxx/BLOCXX_config.h"
#include "blocxx/ArrayFwd.hpp"
#include <iosfwd>

namespace BLOCXX_NAMESPACE
{
	// Define a stream insertion operator for an array.  This is intended for
	// test code only and should not be used in production code.
	template <typename T>
	std::ostream& operator<<(std::ostream& o, const Array<T>& arr)
	{
		o << "{";
		typename Array<T>::const_iterator iter = arr.begin();
		if( iter != arr.end() )
		{
			o << *iter;
			for( ++iter; iter != arr.end(); ++iter )
			{
				o << ", " << *iter;
			}
		}
		o << "}";
		return o;
	}
}

#endif /* !defined(BLOCXX_TEST_HACKERY_HPP_INCLUDE_GUARD_) */
