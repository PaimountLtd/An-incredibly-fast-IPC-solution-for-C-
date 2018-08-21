/* Copyright(C) 2018 Michael Fabian Dirks <info@xaymar.com>
**
** This program is free software; you can redistribute it and/or
** modify it under the terms of the GNU General Public License
** as published by the Free Software Foundation; either version 2
** of the License, or (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#ifndef OS_SEMAPHORE_HPP
#define OS_SEMAPHORE_HPP

#include <inttypes.h>
#include "tags.hpp"
#include "waitable.hpp"

namespace os {
	class semaphore : public os::waitable {
		public:		
		virtual ~semaphore()                         = 0;
		virtual os::error signal(uint32_t count = 1) = 0;

		public:
		static std::shared_ptr<os::semaphore> construct(uint32_t value = 0);
		static std::shared_ptr<os::semaphore> construct(os::create_only_t, std::string name, uint32_t value = 0);
		static std::shared_ptr<os::semaphore> construct(os::create_or_open_t, std::string name, uint32_t value = 0);
		static std::shared_ptr<os::semaphore> construct(os::open_only_t, std::string name);
	};
} // namespace os

#endif // OS_SEMAPHORE_HPP
