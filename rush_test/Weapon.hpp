#ifndef WEAPON_H
# define WEAPON_H

#include "Entities.hpp"
#include <iostream>

class Weapon : public Entities
{
public:
					Weapon( void );
					Weapon( int col, int row, int x, int y, bool dir, int type);
					Weapon(Weapon const & ship);
					~Weapon();
	Weapon & 		operator=(Weapon const & ship);
	int				getCoord_x( void ) const;
	int 			getCoord_y( void ) const;
	int 		 	getType( void ) const;
	bool			setMove( int key );

protected:
	std::clock_t 	_start;
	bool			_dir;
	int				_type;
};

#endif