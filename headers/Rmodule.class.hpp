/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rmodule.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hades <hades@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 21:42:37 by hades             #+#    #+#             */
/*   Updated: 2015/01/18 03:46:51 by hades            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RMODULE_CLASS_HPP
# define RMODULE_CLASS_HPP

#include <iostream>
#include "IMonitorModule.class.hpp"

class Rmodule : public IMonitorModule
{
public:
			Rmodule( int position );
			~Rmodule( void );

// getter
int			getPosition( void ) const;
std::string	getData( void ) const;
std::string	getName( void ) const;

//other
void		findData( void );
void		drawNcurses( int maxWidth ) const;

private:
int				_position;
std::string 	_data;
std::string		_name;

			Rmodule( void );
			Rmodule( Rmodule const & model );
Rmodule 	& operator=( Rmodule const & model );
};


#endif /* RMODULE_CLASS_HPP */