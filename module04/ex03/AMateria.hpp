#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {
protected:
	std::string _materiaType;

public:
	AMateria(const std::string & type);
	AMateria(const AMateria & other);

	AMateria & operator=(const AMateria & other);

	virtual ~AMateria();

	std::string const & getType() const;

	virtual AMateria * clone() const = 0;
	virtual void use(ICharacter & target);
};

#endif
