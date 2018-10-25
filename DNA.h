#ifndef BIOINFOI_DNA_H
#define BIOINFOI_DNA_H

namespace Alphabet
{

/**
 * Class implementing the conversion and validation
 * of string charactes to sequence characters
 */
class DNA
{
  public:
	/// The characters available for DNA
	enum class Characters {
		a, // Adenine intron
		A, // Adenine exon
		t, // Thymine intron
		T, // Thymine exon
		g, // Guanine intron
		G, // Guanine exon
		c, // Cytosine intron
		C, // Cytosine exon
		N  // Unknown. Valid characters are 'N' and 'n'.
	};

	/**
	 * Converts a char to a Character. The conversion is case sensitive.
	 * Throws an InvalidCharacter exception if the passed char is invalid.
	 */
	static Characters toCharacter(char c);

	/**
	 * Converts a Character to an upper-case char.
	 */
	static char toChar(Characters c);
};
}

#endif // BIOINFOI_DNA_H
