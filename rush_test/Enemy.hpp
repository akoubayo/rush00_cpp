#ifndef ENEMY_H
# define ENEMY_H

#include "Entities.hpp"
#include <iostream>
#include "weapon.hpp"
class Enemy : public Entities
{
public:
					Enemy( void );
					Enemy( int col, int row, int x, int y);
					Enemy(Enemy const & ship);
					~Enemy();
	Enemy & 		operator=(Enemy const & ship);
	int				getCoord_x( void ) const;
	int 			getCoord_y( void ) const;
    bool	 		setMove( void );
    bool			makeShoot( void );
    Weapon *		shoot( void );


protected:
	int				_coord_x;
	int				_coord_y;
	int				_nb_col;
	int				_nb_row;
	std::clock_t 	_start;
	static 	 bool 	_randInit;
	bool			randMove(int pourc);
	bool			_dir;
	bool			_shoot;
	void			updateDesign();
};
#endif