/**
 * @file countVoteOPL.h
 *
 * @copyright csci5801 team26, All rights reserved.
 */
#ifndef SRC_COUNTVOTEOPL_H_
#define SRC_COUNTVOTEOPL_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <list>
#include <string>
#include <map>

#include "opl.h"

using namespace std;
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class OPL;
/**
 * @brief The main class for the CountVoteOPL.
 *
 *  This is a static call, not requiring an instance to invoke the method.
 */
class CountVoteOPL {
 public:
  /**
   * @brief Constructs a CountVoteOPL.
   *
   * @param[in] OPL*.
   *
   * @return pointer to OPL.
   */
  CountVoteOPL(OPL*);
  /**
   * @brief Constructs a get_vote_count.
   *
   * @return map<string,int>.
   */
  map<string,int> get_vote_count();
  /**
   * @brief Constructs a get_type_of_election.
   *
   * @return string.
   */
  string get_type_of_election();
  /**
   * @brief Constructs a get_parties.
   *
   * @return string.
   */
  string get_parties();

 private:
  OPL * OPL_count;
  std::map<string,int> vote_count;
  std::string type_of_election;
  vector<string> vote;
  vector<string> can;
};
#endif  // SRC_COUNTVOTE_H_
