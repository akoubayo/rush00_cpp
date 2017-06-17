#ifndef ENTITIES_H
# define ENTITIES_H

class Weapon;

class Entities
{
public:
						Entities( void );
						Entities( int col, int row, int x, int y);
						Entities(Entities const & ship);
						~Entities();
	Entities & 			operator=(Entities const & ship);
	int					getCoord_x( void ) const;
	int 				getCoord_y( void ) const;
	void				setMove( int key );		
    int 				_design[2][10];

protected:
	int				_coord_x;
	int				_coord_y;
	int				_nb_col;
	int				_nb_row;
	void			updateDesign();

};
#endif