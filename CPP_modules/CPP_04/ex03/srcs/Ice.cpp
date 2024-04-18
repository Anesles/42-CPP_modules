/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brumarti <brumarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:43:06 by brumarti          #+#    #+#             */
/*   Updated: 2024/04/18 16:16:45 by brumarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.h"

Ice::Ice() {
	std::cout << "Ice constructor called" << std::endl;
}

Ice::~Ice() {
	std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(Ice const & src) {
	*this = src;
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(Ice const &other) {
	this->_type = other._type;
	std::cout << "Ice copy assignement called" << std::endl;
	return(*this);
}

AMateria* Ice::clone() const {
	return (new Ice(*this));
}

void Ice::use(ICharacter& target) {
	std::cout << "Shoots an ice bolt at " << target.getName() << std::endl;
}