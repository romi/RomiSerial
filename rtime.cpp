/*
  romi-rover

  Copyright (C) 2019-2020 Sony Computer Science Laboratories
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

#include <time.h>
#include <math.h>
#include <stdexcept>
#include "rtime.h"

namespace romiserial {

        double rtime()
        {
                struct timespec spec;
                double result;
                
                clock_gettime(CLOCK_REALTIME, &spec);
                result = (double) spec.tv_sec + (double) spec.tv_nsec / 1.0e9;
                
                return result;
        }

        void rsleep(double seconds)
        {
                struct timespec spec;
                struct timespec remain;
                
                spec.tv_sec = (time_t) floor(seconds);
                double nsec = seconds - (double) spec.tv_sec;
                spec.tv_nsec = (time_t) floor(nsec * 1.0e9);
                int r = clock_nanosleep(CLOCK_REALTIME, 0, &spec, &remain);
                
                if (r != 0) {
                        if (r == EINTR) {
                                throw std::runtime_error("rcom_sleep: Interrupted");
                        } else {
                                throw std::runtime_error("rcom_sleep: Failed");
                        }
                }                
        }
}

#endif
