/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HSmodule.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hades <hades@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 21:42:23 by hades             #+#    #+#             */
/*   Updated: 2015/01/17 22:04:01 by hades            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HSMODULE_CLASS_HPP
# define HSMODULE_CLASS_HPP

#include <iostream>
#include "IMonitorModule.class.hpp"

class HSmodule : public IMonitorModule
{
public:
			HSmodule( void );
			~HSmodule( void );

// getter
int			getPosition( void ) const;
std::string	getData( void ) const;	

private:

int			_position;
std::string _data;

			HSmodule( HSmodule const & model );
HSmodule 	& operator=( HSmodule const & model );
};


#endif /* HSMODULE_CLASS_HPP */