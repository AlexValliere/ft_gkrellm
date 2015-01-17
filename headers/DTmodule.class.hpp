/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DTmodule.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hades <hades@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 21:42:17 by hades             #+#    #+#             */
/*   Updated: 2015/01/18 00:11:25 by hades            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DTMODULE_CLASS_HPP
# define DTMODULE_CLASS_HPP

#include <iostream>
#include "../headers/usual_functions.hpp"
#include "IMonitorModule.class.hpp"

class DTmodule : public IMonitorModule
{
public:
			DTmodule( int position );
			~DTmodule( void );

// getter
int			getPosition( void ) const;
std::string	getData( void ) const;	
std::string	getName( void ) const;

private:
int				_position;
std::string 	_data;
std::string		_name;

			DTmodule( void );
			DTmodule( DTmodule const & model );
DTmodule 	& operator=( DTmodule const & model );
};


#endif /* DTMODULE_CLASS_HPP */