/**
 * @file opl.h
 *
 * @copyright csci5801 team26, All rights reserved.
 */
#ifndef SRC_OPL_H_
#define SRC_OPL_H_

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
 * @brief The main class for the OPL.
 *
 *  This is a static call, not requiring an instance to invoke the method.
 */
class OPL {
 public:
  /**
   * @brief Constructs a OPL.
   *
   * @param[in] ifstream .
   *
   * @return ifstream.
   */
  OPL(ifstream&);
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
   * @brief Constructs a get_OPL_vote.
   *
   * @return vector<string>.
   */
  vector<string> get_OPL_vote();
  /**
   * @brief Constructs a generate_audit_file.
   *
   * @param[in] string holding a filename
   *
   * @return generate an audit file.
   */
  void generate_audit_file(string);
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
  vector<std::string> OPL_vote;
  vector<std::string> candidate;
};
#endif  // SRC_OPL_H_
