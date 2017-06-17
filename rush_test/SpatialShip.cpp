#include "SpatialShip.hpp"
#include <ncurses.h>
   
				SpatialShip::SpatialShip( void )
{

}
				SpatialShip::SpatialShip( int col, int row)  : Entities(col, row, 0, row/2)
{
	int i = 0;
	int j = 0;
	while(i < 2) {
		while(j < 10) {
			this->_design[i][j] = -1;
			j++;
		}
		j = 0;
		i++;
	}
	this->updateDesign();

}
				SpatialShip::SpatialShip(SpatialShip const & ship)
{
	*this = ship;
}
				SpatialShip::~SpatialShip()
{
	mvprintw(this->_coord_x, this->_coord_y + 2,"%s"," DESTRUCT");
}
SpatialShip & 	SpatialShip::operator=(SpatialShip const & ship)
{
	this->_nb_col = ship._nb_col;
	this->_nb_row = ship._nb_row;
	this->_coord_x = ship._coord_x;
	this->_coord_y = ship._coord_y;
	return *this;
}
int				SpatialShip::getCoord_x( void ) const
{
	return this->_coord_x;
}
int 			SpatialShip::getCoord_y( void ) const
{
	return this->_coord_y;
}

Weapon * 		SpatialShip::shoot()
{
	Weapon *w = new Weapon(this->_nb_col, this->_nb_row, (this->_coord_x + 2), this->_coord_y, true, 1);
	return w;
}

void			SpatialShip::setMove( int key )
{
	if (key == 68) {
        this->_coord_x -= 1;
 	} else if ( key == 65 ) {
 		this->_coord_y -= 1;
 	} else if ( key == 66 ) {
 		this->_coord_y += 1;
 	}
    else if ( key == 67) {
    	this->_coord_x += 1;
    }
	if (this->_coord_x >= (this->_nb_col - 1)) {
	 	this->_coord_x = (this->_nb_col - 1);	
	} else if(this->_coord_x <= 0) {
	 	this->_coord_x = 0;
	}
	if (this->_coord_y >= this->_nb_row - 4) {
	 	this->_coord_y = this->_nb_row - 4;	
	} else if (this->_coord_y <= 5 ) {
	 	this->_coord_y = 5;
	}
	this->updateDesign();
	mvprintw(this->_coord_y - 1, this->_coord_x,"%s","X");
	mvprintw(this->_coord_y, this->_coord_x,"%s",    " X");
	mvprintw(this->_coord_y + 1, this->_coord_x,"%s","X");
}

void			SpatialShip::updateDesign()
{
	this->_design[0][0] = this->_coord_x;
	this->_design[0][1] = this->_coord_x + 1;
	this->_design[0][2] = this->_coord_x;
	this->_design[1][0] = this->_coord_y - 1;
	this->_design[1][1] = this->_coord_y;
	this->_design[1][2] = this->_coord_y + 1;
}