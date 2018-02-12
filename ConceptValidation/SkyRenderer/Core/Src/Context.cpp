/*
 * Copyright (C) 2018 Minmin Gong
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <Sauron/Context.hpp>

#include <mutex>

#include <boost/assert.hpp>

namespace
{
	std::mutex singleton_mutex;
}

namespace Sauron
{
	std::unique_ptr<Context> Context::instance_;

	Context::Context()
	{
	}

	Context& Context::GetInstance()
	{
		if (!instance_)
		{
			std::lock_guard<std::mutex> lock(singleton_mutex);
			if (!instance_)
			{
				instance_ = std::make_unique<Context>();
			}
		}
		return *instance_;
	}
}
