#ifndef MPAGS_CAESARCIPHER_HPP 
#define MPAGS_CAESARCIPHER_HPP

#include <iostream>
#include <string>

class CaesarCipher {

public:
  explicit CaesarCipher(const size_t& caesarKey);
  explicit CaesarCipher(const std::string& caesarKey);
  size_t caesar_Key;

};


#endif
