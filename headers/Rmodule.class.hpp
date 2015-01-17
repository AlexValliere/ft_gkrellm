/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rmodule.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hades <hades@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 21:42:37 by hades             #+#    #+#             */
/*   Updated: 2015/01/17 22:04:27 by hades            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RMODULE_CLASS_HPP
# define RMODULE_CLASS_HPP

#include <iostream>
#include "IMonitorModule.class.hpp"

class Rmodule : public IMonitorModule
{
public:
			Rmodule( void );
			~Rmodule( void );

// getter
int			getPosition( void ) const;
std::string	getData( void ) const;

private:
int				_position;
std::string 	_data;

			Rmodule( Rmodule const & model );
Rmodule 	& operator=( Rmodule const & model );
};


#endif /* RMODULE_CLASS_HPP */