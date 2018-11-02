#ifndef MPAGS_CAESARCIPHER_HPP 
#define MPAGS_CAESARCIPHER_HPP

#include <iostream>
#include <string>
#include <vector>


#include "CipherMode.hpp"
class CaesarCipher {

public:
  explicit CaesarCipher(const size_t& caesarKey, const CipherMode& ciphermode, const std::string& input_letters);
  explicit CaesarCipher(const std::string& caesarKey, const CipherMode& ciphermode, const std::string& input_letters);
  std::string applyCipher();
  
  std::string input_letters_;
  std::string output_letters_;

private:
  const std::vector<char> alphabet_ = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  size_t key_;
  CipherMode ciphermode_;

};


#endif
