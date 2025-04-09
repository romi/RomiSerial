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

#ifndef __ROMISERIAL_RSERIAL_H
#define __ROMISERIAL_RSERIAL_H

#include <string>
#include <memory>
#include "IInputStream.h"
#include "IOutputStream.h"
#include "ILog.h"

namespace romiserial {
        
        static const bool kDontReset = false;
        static const bool kReset = true;

        class RSerial : public IInputStream, public IOutputStream
        {
        protected:
                std::string device_;
                int fd_;
                double timeout_;
                uint32_t baudrate_;
                bool reset_;
                std::shared_ptr<ILog> log_;
                int timeout_ms_;
        
                void open_device();
                void configure_termios();
                void set_termios(struct termios *tty);
                void get_termios(struct termios *tty);
                bool can_write();
                bool poll_write();

        public:
                RSerial(const std::string& device, uint32_t baudrate,
                        bool reset, std::shared_ptr<ILog> log);
                virtual ~RSerial();

                void set_timeout(double seconds) override;
        
                bool available() override;        
                bool read(char& c) override;
                bool write(char c) override;
        };
}

#endif // __ROMISERIAL_RSERIAL_H
