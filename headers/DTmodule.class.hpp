/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DTmodule.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hades <hades@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 21:42:17 by hades             #+#    #+#             */
/*   Updated: 2015/01/17 22:04:09 by hades            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DTMODULE_CLASS_HPP
# define DTMODULE_CLASS_HPP

#include <iostream>
#include "IMonitorModule.class.hpp"

class DTmodule : public IMonitorModule
{
public:
			DTmodule( void );
			~DTmodule( void );

// getter
int			getPosition( void ) const;
std::string	getData( void ) const;	

private:
int				_position;
std::string 	_data;

			DTmodule( DTmodule const & model );
DTmodule 	& operator=( DTmodule const & model );
};


#endif /* DTMODULE_CLASS_HPP */