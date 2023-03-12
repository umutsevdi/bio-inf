#pragma once
/******************************************************************************

 * File: main.cpp
 *
 * Author: Umut Sevdi
 * Created: 03/12/23
 * Description:
 *     Bioinformatics Example 1 - Transcribe the following DNA to RNA, then
 use the genetic code to translate it to a sequence of amino acids.

*****************************************************************************/
#include <string>
/**
 * Returns a copy of the string in which all tabs, spaces or newline characters
 * are removed.
 */
inline std::string erase_space(const std::string &str);
/**
 * Transcribes the DNA sequence, in place. Returns the input.
 */
inline std::string &transcribe_dna(std::string &str);
/**
 * Replaces all Thymine(T) with Uracil(U), in place.
 * Returns the input.
 */
inline std::string &thymine2uracil(std::string &str);
