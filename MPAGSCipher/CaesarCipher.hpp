#ifndef MPAGS_CAESARCIPHER_HPP 
#define MPAGS_CAESARCIPHER_HPP

#include <iostream>
#include <string>
#include <vector>


#include "CipherMode.hpp"
class CaesarCipher {

public:
  explicit CaesarCipher(const size_t& caesarKey);
  explicit CaesarCipher(const std::string& caesarKey);
  std::string applyCipher(const std::string& input_letters, const CipherMode& ciphermode);
  
  std::string output_letters_;

private:
  const std::vector<char> alphabet_ = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  size_t key_;

};


#endif
