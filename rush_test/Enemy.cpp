#include "Enemy.hpp"
#include <ncurses.h>
				Enemy::Enemy( void ) {}
				Enemy::Enemy( int col, int row, int x, int y)  : _nb_col(col), _nb_row(row),  _coord_x(x), _coord_y(y) {
					double duration;
    				this->_start = std::clock();
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
				Enemy::Enemy(Enemy const & ship)
{
	*this = ship;
}
				Enemy::~Enemy()
{

}
Enemy & 	Enemy::operator=(Enemy const & ship)
{
	this->_nb_col = ship._nb_col;
	this->_nb_row = ship._nb_row;
	this->_coord_x = ship._coord_x;
	this->_coord_y = ship._coord_y;
	return *this;
}
int				Enemy::getCoord_x( void ) const
{
	return this->_coord_x;
}
int 			Enemy::getCoord_y( void ) const
{
	return this->_coord_y;
}

bool			Enemy::setMove( void )
{
	if(this->_coord_x < 0) return false;
	mvprintw(this->_coord_y - 1, this->_coord_x ,"%s"," #");
	mvprintw(this->_coord_y, this->_coord_x ,"%s","#");
	mvprintw(this->_coord_y + 1, this->_coord_x ,"%s"," #");
	std::clock_t actual = std::clock();
    double duration = (actual - this->_start) / (float)1000;
    if (duration > 275) {
        this->_shoot = this->randMove(5);
    	this->_start = actual;
    	if (this->_coord_y + 4 >= this->_nb_row || this->_coord_y - 4 <= 0 || this->randMove(30)) {
    		this->_dir = (this->_dir) ? false : true;
    	}
    	(this->_dir) ? this->_coord_y++ : this->_coord_y--;
    	this->_coord_x--;
		mvprintw(this->_coord_y + 1, this->_coord_x ,"%s"," #");
		this->updateDesign();
	}	
	return true;
}

bool			Enemy::randMove(int pourc)
{
	
	int i;
	if (!Enemy::_randInit) {
		std::srand(time(NULL));
		Enemy::_randInit = true;
	}
	i = std::rand()%pourc;
	mvprintw(this->_nb_col, this->_nb_row/2 ,"=========**** %d *****=============", i);
	switch(i) {
		case 0: return true;
			break;
		case 1: return false;
			break;
	    default: return false;
			break;
	}
}

bool			Enemy::makeShoot( void ) {
	bool ret = this->_shoot;
	this->_shoot = false;
	return ret;
}

void			Enemy::updateDesign() 
{
	this->_design[0][0] = this->_coord_x + 1;
	this->_design[0][1] = this->_coord_x;
	this->_design[0][2] = this->_coord_x + 1;
	this->_design[1][0] = this->_coord_y - 1;
	this->_design[1][1] = this->_coord_y;
	this->_design[1][2] = this->_coord_y + 1;
}

Weapon * 		Enemy::shoot()
{
	Weapon *w = new Weapon(this->_nb_col, this->_nb_row, (this->_coord_x + 2), this->_coord_y, false, 2);
	return w;
}

bool Enemy::_randInit = false;