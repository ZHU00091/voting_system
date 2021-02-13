/**
 * @file readFile.h
 *
 * @copyright csci5801 team26, All rights reserved.
 */
#include <iostream>
#include <list>
#include <string>
#include <fstream>

#include "generateAuditFile.h"

GenerateAuditFile::GenerateAuditFile(std::ifstream& in) {
    std::getline(in,type_of_election);
    type_of_election = type_of_election.substr(0,3);
}

std::string GenerateAuditFile::get_type_of_election() {
    return type_of_election;
}
