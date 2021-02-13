/**
 * @file cpl.h
 *
 * @copyright csci5801 team26, All rights reserved.
 */
#ifndef SRC_CPL_H_
#define SRC_CPL_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include "generateAuditFile.h"
using namespace std;
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the CPL.
 *
 *  This is a static call, not requiring an instance to invoke the method.
 */
class CPL {
 public:
  /**
   * @brief Constructs a CPL.
   *
   * @param[in] ifstream .
   *
   * @return ifstream.
   */
  CPL(ifstream&);
  /**
   * @brief Constructs a get_type_of_election.
   *
   * @return string.
   */
  string get_type_of_election();
  /**
   * @brief Constructs a get_number_of_seat.
   *
   * @return int.
   */
  int get_number_of_seat();
  /**
   * @brief Constructs a get_number_of_ballot.
   *
   * @return int.
   */
  int get_number_of_ballot();
  /**
   * @brief Constructs a get_number_of_candidate.
   *
   * @return int.
   */
  int get_number_of_candidate();
  /**
   * @brief Constructs a get_number_of_parties.
   *
   * @return int.
   */
  int get_number_of_parties();
  /**
   * @brief Constructs a get_ballot_ordering.
   *
   * @return string.
   */
  vector<char> get_ballot_ordering();
  /**
   * @brief Constructs a get_CPL_vote.
   *
   * @return vector<string>.
   */
  vector<string> get_CPL_vote();
  /**
   * @brief Constructs a generate_audit_file.
   *
   * @param[in] string holding filename
   *
   * @return generate an audit file.
   */
  void generate_audit_file(string filename);
  /**
   * @brief Constructs a get_candidate.
   *
   * @return vector<string>.
   */
  vector<string> get_candidate();

 private:
  int number_of_seat;
  int number_of_ballot;
  int number_of_candidate;
  int number_of_parties;
  std::string ballot_ordering;
  vector<string> CPL_vote;
  vector<string> candidate;
};
#endif  // SRC_CPL_H_
