/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HSmodule.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 21:42:23 by hades             #+#    #+#             */
/*   Updated: 2015/01/18 15:20:06 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HSMODULE_CLASS_HPP
# define HSMODULE_CLASS_HPP

# include <gtk/gtk.h>
# include <iostream>
# include "IMonitorModule.class.hpp"

class HSmodule : public IMonitorModule
{
public:
	HSmodule( int position );
	HSmodule( HSmodule const & model );
	~HSmodule( void );

	HSmodule&		operator=( HSmodule const & model );

	std::string		getData( void ) const;	
	std::string		getHostname( void ) const;
	std::string		getName( void ) const;
	int				getPosition( void ) const;
	std::string		getUsername( void ) const;

	void			addToGtk(GtkWidget* widget) const;
	void			findData( void );
	void			drawNcurses( int maxWidth ) const;

private:
	int				_position;
	std::string		_data;
	std::string		_name;
	std::string		_hostname;
	std::string		_username;

	HSmodule( void );
};


#endif /* HSMODULE_CLASS_HPP */