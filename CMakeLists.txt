cmake_minimum_required(VERSION 3.10)
project(romiserial)

set(romiserial_VERSION_MAJOR 0)
set(romiserial_VERSION_MINOR 1)

set(SOURCES
  IInputStream.h
  IOutputStream.h
  CRC8.h
  CRC8.cpp
  EnvelopeParser.h
  EnvelopeParser.cpp
  MessageParser.h
  MessageParser.cpp
  IRomiSerialClient.h
  RomiSerialClient.h
  RomiSerialClient.cpp
  RomiSerial.h
  RomiSerial.cpp
  RSerial.h
  RSerial.cpp
  Printer.h
  Printer.cpp
  Reader.h
  Reader.cpp
  RomiSerialUtil.h
  RomiSerialUtil.cpp
  rtime.h
  rtime.cpp
  ILog.h
  Log.h
  Console.h
  Console.cpp
  UnoLog.h
  UnoLog.cpp
)

add_library(romiserial SHARED ${SOURCES})
