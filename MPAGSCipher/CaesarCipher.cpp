#include <iostream>
#include <string>

#include "CaesarCipher.hpp"


CaesarCipher::CaesarCipher(const size_t& caesarKey, const CipherMode& ciphermode, const std::string& input_letters): input_letters_{input_letters}, key_{caesarKey}, ciphermode_{ciphermode}
{} // constructor for key in size_t  
CaesarCipher::CaesarCipher(const std::string& caesarKey, const CipherMode& ciphermode, const std::string& input_letters): input_letters_{input_letters}, ciphermode_{ciphermode}
//constructor for key in string format
{
    // Before doing the conversion we should check that the string contains a
    // valid positive integer.
    // Here we do that by looping through each character and checking that it
    // is a digit. What is rather hard to check is whether the number is too
    // large to be represented by an unsigned long, so we've omitted that for
    // the time being.
    // (Since the conversion function std::stoul will throw an exception if the
    // string does not represent a valid unsigned long, we could check for and
    // handled that instead but we only cover exceptions very briefly on the
    // final day of this course - they are a very complex area of C++ that
    // could take an entire course on their own!)  
  bool error{false};
  for ( const auto& elem : caesarKey ) {
      if ( ! std::isdigit(elem) ) {
	std::cerr << "[error] cipher key must be an unsigned long integer for Caesar cipher,\n"
	          << "        the supplied key (" << caesarKey << ") could not be successfully converted\nDefault Key 0 is used" << std::endl;
	error = true;
	break;
      }
  }
  if (!error)
    {key_ = std::stoul(caesarKey);}
  else
    {key_ = 0;}
}


std::string CaesarCipher::applyCipher()
{


  // Create the alphabet container
  const size_t alphabetSize = alphabet_.size();

  // Make sure that the key is in the range 0 - 25
  const size_t truncatedKey { key_ % alphabetSize };

  // Loop over the input text
  char processedChar {'x'};
  for ( const auto& origChar : input_letters_ ) {

    // For each character in the input text, find the corresponding position in
    // the alphabet by using an indexed loop over the alphabet container
    for ( size_t i{0}; i < alphabetSize; ++i ) {

      if ( origChar == alphabet_[i] ) {

	// Apply the appropriate shift (depending on whether we're ciphermodeing
	// or decrypting) and determine the new character
	// Can then break out of the loop over the alphabet
	if ( ciphermode_ == CipherMode::Encrypt ) {
	  processedChar = alphabet_[ (i + truncatedKey) % alphabetSize ];
	} else {
	  processedChar = alphabet_[ (i + alphabetSize - truncatedKey) % alphabetSize ];
	}
	break;
      }
    }

    // Add the new character to the output text
    output_letters_ += processedChar;
  }

  return output_letters_;
}
