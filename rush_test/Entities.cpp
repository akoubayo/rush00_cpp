#include "Entities.hpp"

				Entities::Entities( void )
{

}
				Entities::Entities( int col, int row, int x, int y)  : _nb_col(col), _nb_row(row),  _coord_x(x), _coord_y(y)
{
	this->_coord_y = (this->_coord_y < 10) ? 10  : this->_coord_y;
	this->_coord_y = (this->_coord_y > ( row -10 )) ? ( row -10 ) : this->_coord_y;
}
				Entities::Entities(Entities const & ship)
{
	*this = ship;
}
				Entities::~Entities()
{

}
Entities & 	Entities::operator=(Entities const & ship)
{
	this->_nb_col = ship._nb_col;
	this->_nb_row = ship._nb_row;
	this->_coord_x = ship._coord_x;
	this->_coord_y = ship._coord_y;
	return *this;
}
int				Entities::getCoord_x( void ) const
{
	return this->_coord_x;
}
int 			Entities::getCoord_y( void ) const
{
	return this->_coord_y;
}


void			Entities::setMove( int key )
{
	
}
