/**
 * @file countVote.h
 *
 * @copyright csci5801 team26, All rights reserved.
 */
#ifndef SRC_COUNTVOTE_H_
#define SRC_COUNTVOTE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <list>
#include <string>
#include <map>

#include "cpl.h"

using namespace std;
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class CPL;
/**
 * @brief The main class for the CountVote.
 *
 *  This is a static call, not requiring an instance to invoke the method.
 */
class CountVote {
 public:
  /**
   * @brief Constructs a CountVote.
   *
   * @param[in] CPL*.
   *
   * @return pointer to CPL.
   */
  CountVote(CPL*);
  /**
   * @brief Constructs a get_vote_count.
   *
   * @return map<string,int>.
   */
  map<char,int> get_vote_count();
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
  CPL * CPL_count;
  std::map<char,int> vote_count;
  std::string type_of_election;
    vector<string> vote;
    vector<char> part;
};
#endif  // SRC_COUNTVOTE_H_
