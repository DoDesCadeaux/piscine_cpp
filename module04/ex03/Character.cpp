#include "Character.hpp"

Character::Character(const std::string &name) : _name(name) {
	// std::cout << "Character " << this->_name << " default constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->_inventoryMaterias[i] = NULL;
	}

    for (int i = 0; i < 4; i++) {
        _trash[i] = NULL;
    }
    _trashSize = 0;
}

Character::Character(const Character &other) {
	// std::cout << "Copy constructor called" << std::endl;
	this->_name = other._name;

	for (int i = 0; i < 4; i++) {
		this->_inventoryMaterias[i] = NULL;
	}

	for (int i = 0; i < 4; i++) {
		if (other._inventoryMaterias[i])
			this->_inventoryMaterias[i] = other._inventoryMaterias[i]->clone();
	}
}

Character &Character::operator=(const Character &other) {
	if (this == &other)
		return *this;

	for (int i = 0; i < 4; i++) {
		delete this->_inventoryMaterias[i];
		this->_inventoryMaterias[i] = NULL;
	}

	this->_name = other._name;

	for (int i = 0; i < 4; i++) {
		if (other._inventoryMaterias[i])
			this->_inventoryMaterias[i] = other._inventoryMaterias[i]->clone();
	}
	return *this;
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		delete this->_inventoryMaterias[i];
	}
    emptyTrash();
}

void Character::equip(AMateria *m) {
    for (int i = 0; i < 4; i++) {
        if (this->_inventoryMaterias[i] == NULL) {
            this->_inventoryMaterias[i] = m;
            return;
        }
    }
    std::cout << "Inventory full, cannot equip" << std::endl;
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4 || !this->_inventoryMaterias[idx])
        return;
    if (this->_trashSize >= 4)
        emptyTrash();
    this->_trash[this->_trashSize++] = this->_inventoryMaterias[idx];
    this->_inventoryMaterias[idx] = NULL;
}

void Character::emptyTrash() {
    for (int i = 0; i < this->_trashSize; i++) {
        delete this->_trash[i];
        this->_trash[i] = NULL;
    }
    this->_trashSize = 0;
}

std::string const & Character::getName() const {
    return this->_name;
}

void Character::use(int idx, ICharacter &target) {
    if (idx < 0 || idx > 3)
    {
        std::cout << "Bad slot to use!" << std::endl;
        return;
    }

    AMateria* materiaToUse = this->_inventoryMaterias[idx];

    if (materiaToUse == NULL)
    {
        std::cout << "No materia to use" << std::endl;
        return;
    }
    materiaToUse->use(target);
}