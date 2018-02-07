/*!***************************************************************************
@file    main.cpp
@author  Reverie Wisp
@par     contact@reveriewisp.com
@date    <date here>

@brief 
Allows for dragging things into a key-reading console.

@copyright See LICENSE.md
*****************************************************************************/
#include <iostream>                     // std::cout
#include <string>                       // std::string
#include <ConsoleInput/console-input.h> // KeyHit, GetChar

// Defines
#define NO_INPUT 0



// Some function to process key presses.
void ProcessKey(char c)
{
  std::cout << "A key was pressed! It was: " << c << '\n';
}

// Some function to process path drag-ins.
void ProcessFilepath(std::string path)
{
  std::cout << "Woah, a path! It was: " << path << '\n';
}

// Application entry point
int main(int argc, char** argv)
{
  int last = NO_INPUT;
  std::string buffer = "";

  while (1)
  {
    int hit = KeyHit();
    if (hit)
      do
      {
        last = GetChar();
        buffer += last;
      } while (hit = KeyHit());
    else
      if (last != NO_INPUT)
      {
        if (buffer.size() > 1)
          ProcessFilepath(buffer);
        else
          ProcessKey(last);

        last = NO_INPUT;
        buffer.clear();
      }
  }
}
      /*
    if (val == NO_INPUT)
    {
      if (buffer.size() > 0)
      {
        ProcessFilepath(buffer);
        buffer.clear();
      }

      last = NO_INPUT;
    }
    else
      while (val)
      {
        if (last != NO_INPUT)
        {
          last = GetChar();
          buffer += last;
        }
        else
        {
          last = GetChar();
          ProcessKey(last);
        }

        val = KeyHit();
      }
  }

  // Normal termination
  return 0;
}
*/