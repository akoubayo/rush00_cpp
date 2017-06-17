#ifndef GAME_H
# define GAME_H

#include "SpatialShip.hpp"
#include "Weapon.hpp"
#include "Enemy.hpp"
#include "iostream"

#define NB_MISSILE 100
#define NB_ENEMIES 100
class Game
{
public:
					Game( void );
					Game( Game const & game);
	Game &			operator=(Game const & game);
	void			start( void );
		 			~Game( void );
private: 
	int				addWeapon();
	int 			addEnemies(int col, int row);
	bool			randEnemies(int pourc);
	Weapon * 		weaponList[NB_MISSILE];
	Enemy * 		enemiesList[NB_ENEMIES];
	SpatialShip		_player; 
	static bool		_randInit;
	std::clock_t 	_start; 
	bool			collision(int i);
	static bool     _alive;      	
};

#endif