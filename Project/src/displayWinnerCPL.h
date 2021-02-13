/**
 * @file displayWinnerCPL.h
 *
 * @copyright csci5801 team26, All rights reserved.
 */
#ifndef SRC_DISPLAYWINNERCPL_H_
#define SRC_DISPLAYWINNERCPL_H_

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
 * @brief The main class for the DisplayWinnerCPL.
 *
 *  This is a static call, not requiring an instance to invoke the method.
 */
class DisplayWinnerCPL {
 public:
  /**
   * @brief Constructs a DisplayWinnerCPL.
   *
   * @param[in] map including char and int .
   *
   * @return map<char,int>.
   */
  DisplayWinnerCPL(map<char,int>,vector<string>);
  /**
   * @brief Constructs a display.
   *
   * @return display.
   */
  int display();
  /**
   * @brief Constructs a tie_handler.
   *
   * @return int.
   */
  int tie_handler();

 private:
    map<char,int> result;
    vector<string> cpl_candidate;
};
#endif  // SRC_DISPLAYWINNERCPL_H_
