#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
protected:
	std::string	_type;

public:
	WrongAnimal();
	WrongAnimal(const std::string & type);
	WrongAnimal(const WrongAnimal & other);

	WrongAnimal &operator=(const WrongAnimal & other);

	virtual ~WrongAnimal();

	std::string		getType() const;
	virtual void	makeSound() const;
};

#endif