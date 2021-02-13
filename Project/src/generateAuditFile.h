/**
 * @file generateAuditFile.h
 *
 * @copyright csci5801 team26, All rights reserved.
 */
#ifndef SRC_GENERATEAUDITFILE_H_
#define SRC_GENERATEAUDITFILE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <list>
#include <string>
#include <fstream>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class ReadFile;
/**
 * @brief The main class for the GenerateAuditFile.
 *
 *  This is a static call, not requiring an instance to invoke the method.
 */
class GenerateAuditFile {
  public:
  /**
   * @brief Constructs a GenerateAuditFile with standard ifstream.
   *
   * @param[in] standard ifstream .
   *
   * @return standard ifstream.
   */
    GenerateAuditFile(std::ifstream&);
  /**
   * @brief Constructs a get_type_of_election.
   *
   * @return string.
   */
    std::string get_type_of_election();

  protected:
    std::string type_of_election;
};
#endif  // SRC_GENERATEAUDITFILE_H_
