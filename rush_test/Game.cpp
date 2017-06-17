#include "Game.hpp"
#include <ncurses.h>


			Game::Game( void ) 
{
	this->_start = std::clock();
	for(int i = 0; i < NB_MISSILE - 1; ++i) {
		weaponList[i] = NULL;
		enemiesList[i] = NULL;
	}
}

			Game::Game( Game const & game)
{
	for(int i = 0; i < NB_MISSILE - 1; ++i) {
		weaponList[i] = NULL;
	}
	*this = game;
	return;
}

Game &		Game::operator=(Game const & game)
{
	this->_player = game._player;
	return *this;
}
			Game::~Game( void ){}

void		Game::start( void ) {

	keypad(stdscr, TRUE);	
	int row,col;								 
	initscr();				
	getmaxyx(stdscr,row,col);	
	SpatialShip ship(col, row);
	//Enemy	enemies(col,row, (col - 10), (row/2));
	this->_player = ship;
	nodelay(stdscr, TRUE);
	int ch = 0;                    
	std::clock_t start;
    double duration;
    start = std::clock();
    double last = 0;
	 while(Game::_alive) {
	 	clear(); 
	 	std::clock_t actual = std::clock();
	    duration = (actual - start) / (float)1000;
	    if (duration > 75) { // a supprimer apres le debug
	    	start = actual;
	    	this->addEnemies(col, row);
		}
		mvprintw(3,0," *** This screen has %d Time  *** ",start);
	    mvprintw(2,0,"Left arrow is %d ==== x pressed == %d ========= xx : %d ====",ch, this->_player.getCoord_x(), this->_player.getCoord_y());
	 	ship.setMove(ch);
	 	
	    if (ch == 32) {
	 		int ret = this->addWeapon();
	 		if(ret > -1) {
	 			this->weaponList[ret] = ship.shoot();
	 		}
	 	}
	 	int i = 0;
		while(i < NB_MISSILE - 1) {
			if(this->weaponList[i] != NULL) {
				if(!this->weaponList[i]->setMove(0)) {
					delete this->weaponList[i];
					this->weaponList[i] = NULL;
				} else {
					this->collision(i); 
				}
			}
			if (this->enemiesList[i] != NULL) { //// Voir si une enemie a tire un missile
				if(enemiesList[i]->makeShoot()) {
		 			int ret = this->addWeapon();
		 			if(ret > -1) {
		 				this->weaponList[ret] = enemiesList[i]->shoot();
		 			}
		 		}
		 		if(!this->enemiesList[i]->setMove()) {
		 			delete this->enemiesList[i];
					this->enemiesList[i] = NULL;
		 		}
	 		}
			i++;
		}
	 	mvprintw(row-2,0,"This screen has %d rows and %d columns\n",row,col);
		printw("Try resizing your window(if possible) and then run this program again");	    
		ch = getch();
		this->_player.setMove(ch);
	 }
	 mvprintw(row-2,0,"This screen has %d rows and %d columns\n",row,col);
	 //refresh();
	 //endwin();
}

int Game::addWeapon()
{
	int i = 0;
	while(i < NB_MISSILE - 1) {
		if(this->weaponList[i] == NULL) {
			return i;
		}
		i++;
			
	}
	return -1;
	
}

int Game::addEnemies(int col, int row)
{
	int i = 0;
	if (!this->randEnemies(40)) {
		return -1;
	}
	while (i < NB_ENEMIES - 1) {
		if (this->enemiesList[i] == NULL) {
			enemiesList[i] = new Enemy(col,row, (col - std::rand()%20), (std::rand()%row));
			return i;
		}
		i++;
			
	} 
	return -1;
}

bool			Game::randEnemies(int pourc)
{	
	int i;
	mvprintw(15, 15, "This screen has %d rows and %d columns\n",1,1);
	if (!Game::_randInit) {
		std::srand(time(NULL));
		Game::_randInit = true;
	}
	i = std::rand()%pourc;
	switch(i) {
		case 0: return true;
			break;
		case 1: return false;
			break;
	    default: return false;
			break;
	}
}

bool			Game::collision(int i) 
{
	if (weaponList[i]->getType() == 1) {
		int j = 0;
		while(j < NB_ENEMIES) {
			if (enemiesList[j] != NULL) {
				int k = 0;
				while(k < 10) {
					if ( enemiesList[j]->_design[0][k] == (weaponList[i]->getCoord_x() + 2) && enemiesList[j]->_design[1][k] == weaponList[i]->getCoord_y()) {
						delete this->enemiesList[j];
					    this->enemiesList[j] = NULL;
						delete this->weaponList[i];
						this->weaponList[i] = NULL;
						return false;
					}
					k++;
				}				
			}
			j++;
		}
	} else {
		int k = 0;
		while(k < 10) {
			if ( this->_player._design[0][k] == (weaponList[i]->getCoord_x() + 2) && this->_player._design[1][k] == weaponList[i]->getCoord_y()) {
				Game::_alive = false;
				delete this->weaponList[i];
				this->weaponList[i] = NULL;
				return false;
			}
			k++;
		}
	}
	return false;
}

bool Game::_randInit = false;
bool Game::_alive = true;