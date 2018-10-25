#ifndef BIOINFOI_FASTA_H
#define BIOINFOI_FASTA_H

#include "Sequence.h"
#include "ParsingException.h"

#include <istream>
#include <ostream>
#include <cassert>

/**
 * A simple helper class used to signal
 * that we want to write a DNA sequence in 2Bit format.
 */
template<typename Alpha>
class SequenceFastaWriter
{
  public:
	SequenceFastaWriter(const Sequence<Alpha>& seq);

	/// Global input operator
	template<typename A>
	friend std::ostream& operator<<(std::ostream& strm,
	                                const SequenceFastaWriter<A>&);

  private:
	/// Stores a reference to the sequence to write.
	const Sequence<Alpha>& seq_;
};

/**
 * A simple helper class used to signal
 * that we want to read a DNA sequence in 2Bit format.
 */
template<typename Alpha>
class SequenceFastaReader
{
  public:
	SequenceFastaReader(Sequence<Alpha>& seq);

	/// Global input operator (Needs an rvalue reference to work with from2Bit...)
	template<typename A>
	friend std::istream& operator>>(std::istream& strm, SequenceFastaReader<A>&&);

  private:
	/// Stores a reference to the sequence to read.
	Sequence<Alpha>& seq_;
};

template<typename Alpha>
SequenceFastaWriter<Alpha> toFasta(const Sequence<Alpha>& seq) {
	assert("Not Implemented" && false);
}

template<typename Alpha>
SequenceFastaReader<Alpha> fromFasta(Sequence<Alpha>& seq) {
	assert("Not Implemented" && false);
}

