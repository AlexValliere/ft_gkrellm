/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSmodule.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hades <hades@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 21:42:33 by hades             #+#    #+#             */
/*   Updated: 2015/01/18 03:46:08 by hades            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSMODULE_CLASS_HPP
# define OSMODULE_CLASS_HPP

#include <iostream>
#include "IMonitorModule.class.hpp"

class OSmodule : public IMonitorModule
{
public:
			OSmodule( int position );
			~OSmodule( void );

// getter
int			getPosition( void ) const;
std::string	getData( void ) const;
std::string	getName( void ) const;

//other
void		findData( void );
void		drawNcurses( int maxWidth ) const;

private:
	int			_position;
std::string 	_data;
std::string		_name;

			OSmodule( void );
			OSmodule( OSmodule const & model );
OSmodule 	& operator=( OSmodule const & model );
};


#endif /* OSMODULE_CLASS_HPP */