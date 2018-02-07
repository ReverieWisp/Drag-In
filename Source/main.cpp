/*!***************************************************************************
@file    main.cpp
@author  Reverie Wisp
@par     contact@reveriewisp.com
@date    <date here>

@brief 
Allows for dragging things into a key-reading console.

@copyright See LICENSE.md
*****************************************************************************/
#include <iostream>                // std::cout
#include <RUtils/RTimekeeper.hpp>  // Rutils::RException
#include <ConsoleInput/console-input.h>

// Some function to process key presses.
void ProcessKey(char c)
{
  std::cout << "A key was pressed! It was: " << c << '\n';
}


// Application entry point
int main(int argc, char** argv)
{


  while (1)
  {
    while (int val = KeyHit())
    {
      ProcessKey(GetChar());
    }
  }

  // Normal termination
  return 0;
}
