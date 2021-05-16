#ifndef MIRNA_SEQUENCE_H
#define MIRNA_SEQUENCE_H

#include <istream>
#include <ostream>
#include <cstring>
#include <string>
#include <map>
#include <vector>


/**
 * Sequence Class
 *
 * Takes an Alphabet as type parameter.
 * The Alphabet defines the representable sequence.
 *
 * Every class using Alphabet must therefor define
 * a Characters enum, which will define the characters
 * stored in the sequence
 *
 */

template <typename Alpha> class Sequence
{
public:

    /**
     * for easier use
     */
    using Alphabet = Alpha;
    using Characters = typename Alphabet::Characters;

    /**
     * storage of the data
     */
    using Container = std::vector<Characters>;
    using iterator = typename Container::iterator;
    using const_iterator = typename Container::const_iterator;

    /**
     * default constructor
     */
    Sequence() = default;

    /**
     * Functions
     */

    /// converts a given string to a sequence
    /// @throw InvalidCharacter if a character in sequence is invalid
    static Sequence fromString(const std::string& sequence);

    /// @return string representing a sequence
    std::string toString() const;

    /// iterator pointing to the start of a sequence
    iterator begin();

    /// iterator pointing to the end (+1) of a sequence
    iterator end();

    /// const iterator pointing to the start of a sequence
    const_iterator begin() const;

    /// const iterator pointing to the end (+1) of a sequence
    const_iterator end() const;

    /// @return length of a sequence
    size_t size() const;

    /// clears the sequence of all entries
    void clear();

    /// resizes a sequence
    void resize(size_t i);

    /// Add a single character to the sequence -> size + 1
    void push_back(Characters c);

    /// compare method
    //TODO: think of parameters that fit your task
    bool compare () const;

    /// get comment/name of a sequence
    const std::string& getComment() const;

    /// set comment/name of a sequence
    void setComment(const std::string& comment);

    /**
     * operators
     */

    /// @return the i-th charcter of a sequence
    Characters operator[](size_t i) const;
    Characters& operator[](size_t i);

    /// equality
    bool operator==(const Sequence&) const;
    /// inequality
    bool operator!=(const Sequence&) const;

    /// global output
    template <typename A>
    friend std::ostream& operator<<(std::ostream&, const Sequence<A>&);
    /// global input
    template <typename A>
    friend std::istream& operator>>(std::istream&, Sequence<A>&);

protected:

    /// internal storage of a sequence
    Container storage_;

    /// used to store name of a sequence
    std::string comment_;

};

#endif //MIRNA_SEQUENCE_H
