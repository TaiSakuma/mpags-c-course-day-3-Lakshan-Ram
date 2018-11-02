#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <string>
#include <vector>

#include "CipherMode.hpp"
struct ProcessedArgs {
  bool helpRequested;
  bool versionRequested;
  std::string inputFile;
  std::string outputFile;
  std::string cipher_key;
  CipherMode ciphermode;
};

  bool processCommandLine(const std::vector<std::string> args, ProcessedArgs& InArgs);



#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP 
