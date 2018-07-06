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

#ifndef OS_WINDOWS_SEMAPHORE_HPP
#define OS_WINDOWS_SEMAPHORE_HPP

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <inttypes.h>
#include <windows.h>
#include "../tags.hpp"
#include "../waitable.hpp"

namespace os {
	namespace windows {
		class semaphore : public os::waitable {
			HANDLE handle;

			public:
			semaphore(int32_t initial_count = 0, int32_t maximum_count = INT32_MAX);
			semaphore(os::create_only_t, std::string name, int32_t initial_count = 0,
					  int32_t maximum_count = INT32_MAX);
			semaphore(os::create_or_open_t, std::string name, int32_t initial_count = 0,
					  int32_t maximum_count = INT32_MAX);
			semaphore(os::open_only_t, std::string name);
			~semaphore();

			os::error signal(uint32_t count = 1);

			// os::waitable
			protected:
			virtual void *get_waitable() override;
		};
	} // namespace windows
} // namespace os

#endif // OS_WINDOWS_SEMAPHORE_HPP
