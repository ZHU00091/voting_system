/**
 * @file displayWinner.h
 *
 * @copyright csci5801 team26, All rights reserved.
 */
#ifndef SRC_DISPLAYWINNER_H_
#define SRC_DISPLAYWINNER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <map>

using namespace std;
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the DisplayWinner.
 *
 *  This is a static call, not requiring an instance to invoke the method.
 */
class DisplayWinner {
 public:
  /**
   * @brief Constructs a DisplayWinner.
   *
   * @param[in] map including string and int .
   *
   * @return map<string,int>.
   */
  DisplayWinner(map<string,int>);
  /**
   * @brief Constructs a display.
   *
   * @return display.
   */
  string display();
  /**
   * @brief Constructs a tie_handler.
   *
   * @return int.
   */
  int tie_handler();

 private:
    map<string,int> result;
};
#endif  // SRC_DISPLAYWINNER_H_
