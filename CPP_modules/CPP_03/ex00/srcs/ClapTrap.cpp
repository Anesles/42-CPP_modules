/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:51:15 by brumarti          #+#    #+#             */
/*   Updated: 2024/01/16 16:12:56 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

ClapTrap::ClapTrap() : _name("Zezinho"), _hitp(10), _enep(10), _atad(0){
	std::cout << "ClapTrap " << this->_name << " created !\n";
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitp(10), _enep(10), _atad(0){
	std::cout << "ClapTrap " << this->_name << " created !\n";
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap " << this->_name << " destroyed.\n";
}

ClapTrap::ClapTrap(const ClapTrap &src){
	*this = src;
	std::cout << "Copy constructor called for ClapTrap " << this->_name << ".\n";
}

ClapTrap &ClapTrap::operator=(ClapTrap const & other) {
	this->_name = other._name;
	this->_atad = other._atad;
	this->_enep = other._enep;
	this->_hitp = other._hitp;
	std::cout << "Copy assignment operator called for ClapTrap " << this->_name << ".\n";
	return (*this);
}

void ClapTrap::attack(const std::string& target){
	if (this->_hitp > 0 && this->_enep > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attcks " << target << ", causing " << this->_atad << " points of damage!\n";
		this->_enep--;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name;
		if (this->_hitp <= 0)
			std::cout << " has no hipoints left";
		if (this->_hitp <= 0 && this->_enep <= 0)
			std::cout << " and";
		if(this->_enep <= 0)
			std::cout << " has no energy points left";
		std::cout << ".\n";
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitp > 0)
	{
		if ((this->_hitp - amount) <= 0)
			std::cout << "ClapTrap " << this->_name << " took " << amount << " damage and died...\n";
		else
			std::cout << "ClapTrap " << this->_name << " took " << amount << " dammage.\n";
		this->_hitp -= amount;
	}
	else
		std::cout << this->_name << " is already dead !\n";
}

void ClapTrap::beRepaired(unsigned amount) {
	std::cout << "ClapTrap " << this->_name << " got " << amount << "energy points !\n";
	this->_enep += amount;
}