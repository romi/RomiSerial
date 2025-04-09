/*
  romi-rover

  Copyright (C) 2019 Sony Computer Science Laboratories
  Author(s) Peter Hanappe

  romi-rover is collection of applications for the Romi Rover.

  romi-rover is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see
  <http://www.gnu.org/licenses/>.

 */

#if !defined(ARDUINO)

#include <stdio.h>
#include "Console.h"

namespace romiserial {

        Console::Console()
        {
        }
        
        void Console::print(const char *type, const char *format, va_list ap)
        {
                printf("RomiSerial: %s: ", type);
                vprintf(format, ap);
        }
        
        void Console::error(const char *format, ...)
        {
                va_list ap;
                va_start(ap, format);
                print("Error", format, ap);
                va_end(ap);
        }
        
        void Console::warn(const char *format, ...)
        {
                va_list ap;
                va_start(ap, format);
                print("Warning", format, ap);
                va_end(ap);
        }
        
        void Console::debug(const char *format, ...)
        {
                va_list ap;
                va_start(ap, format);
                print("Debug", format, ap);
                va_end(ap);
        }
}

#endif
