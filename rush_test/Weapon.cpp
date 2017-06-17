#include "Weapon.hpp"
#include <ncurses.h>

				Weapon::Weapon( void )
{

}
				Weapon::Weapon( int col, int row, int x, int y, bool dir, int type)  : Entities(col, row, x, y), _dir(dir), _type(type)
{

    double duration;
    this->_start = std::clock();
}
				Weapon::Weapon(Weapon const & ship)
{
	*this = ship;
}
				Weapon::~Weapon()
{
}
Weapon & 	Weapon::operator=(Weapon const & ship)
{
	this->_nb_col = ship._nb_col;
	this->_nb_row = ship._nb_row;
	this->_coord_x = ship._coord_x;
	this->_coord_y = ship._coord_y;
	return *this;
}
int				Weapon::getCoord_x( void ) const
{
	return this->_coord_x;
}
int 			Weapon::getCoord_y( void ) const
{
	return this->_coord_y;
}

int 		 	Weapon::getType( void ) const 
{
	return this->_type;
}

bool			Weapon::setMove( int key )
{
	mvprintw(this->_coord_y, this->_coord_x ,"%s","--");
	if ((this->_coord_x + 2 < this->_nb_col && this->_dir == true) || (this->_coord_x - 2 >= 0 &&  this->_dir == false)) {
    	std::clock_t actual = std::clock();
	    double duration = (actual - this->_start) / (float)1000;
	    if (duration > 25) {
	    	this->_start = actual;
	    	(this->_dir) ? this->_coord_x++ : this->_coord_x--;
	    }	
	} else {
		return false;
	}	
	return true;
}