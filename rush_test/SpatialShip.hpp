#ifndef SPATIAL_SHIP_H
# define SPATIAL_SHIP_H

#include "Entities.hpp"
#include "Weapon.hpp"
#include "list"

class SpatialShip : public Entities
{
public:
							SpatialShip( void );
							SpatialShip( int col, int row);
							SpatialShip(SpatialShip const & ship);
							~SpatialShip();
	SpatialShip & 			operator=(SpatialShip const & ship);
	int						getCoord_x( void ) const;
	int 					getCoord_y( void ) const;
	void					setMove( int key ); 
	Weapon *		 		shoot();


protected:
	void					updateDesign();
};

#endif