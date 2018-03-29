#include <map>
#include <string>


//! Class for manipulating Deoxyribonucleic acid (DNA) sequences.
class DNA {

  //! Current DNA sequence
  std::string dna;
  //! Original DNA sequence
  std::string original_dna;

public:
  //! Default constructor
  DNA() = default;
  //! Convenience constructor
  //! \param _dna: original DNA sequence
  explicit DNA(std::string _dna) : dna(std::move(_dna)) {original_dna = dna;}
  virtual ~DNA() = default;

  //! Return the current DNA sequence, \a dna.
  const std::string &get_dna() const {
    return dna;
  }

  //! Return the original DNA sequence, \a original_dna.
  const std::string &get_original_dna() const {
    return original_dna;
  }

  //! Set the current DNA sequence, \a dna.
  void setDna(const std::string &dna) {
    DNA::dna = dna;
  }

  //! Return the DNA.dna complement sequence using an if else statement.
  std::string complement_if() {
    for (auto &c : dna) {
      if (c == 'A') c = 'T';
      else if (c == 'T') c = 'A';
      else if (c == 'C') c = 'G';
      else if (c == 'G') c = 'C';
    }
    return dna;
  }

  //! Return the DNA.dna complement sequence using a map table.
  std::string complement_map() {
    const std::map<char, char> dna_table = {{'A','T'},
                                            {'T','A'},
                                            {'C','G'},
                                            {'G','C'}};
    for (auto &c : dna) {
      c = dna_table.at(c);
    }
    return dna;
  }

  //! Return the DNA.dna complement sequence using a switch statement.
  std::string complement_switch() {
    for (auto &c : dna) {
      switch(c) {
        case 'A' : c = 'T';
          break;
        case 'T' : c = 'A';
          break;
        case 'C' : c = 'G';
          break;
        case 'G' : c = 'C';
          break;
        default:break;
      }
    }
    return dna;
  }

  //! Return the DNA.dna complement sequence using an array look up.
  std::string complement_array() {
    static const char array[] = {'T', 0, 'G', 0, 0, 0, 'C', 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 'A'};
    for(auto &c : dna) {
      c = array[c - 'A'];
    }
    return dna;
  }

private:

};
