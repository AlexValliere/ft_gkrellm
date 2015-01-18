/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HSmodule.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hades <hades@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 21:42:23 by hades             #+#    #+#             */
/*   Updated: 2015/01/18 03:43:41 by hades            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HSMODULE_CLASS_HPP
# define HSMODULE_CLASS_HPP

#include <iostream>
#include "IMonitorModule.class.hpp"

class HSmodule : public IMonitorModule
{
public:
			HSmodule( int position );
			~HSmodule( void );

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

			HSmodule( void );
			HSmodule( HSmodule const & model );
HSmodule 	& operator=( HSmodule const & model );
};


#endif /* HSMODULE_CLASS_HPP */