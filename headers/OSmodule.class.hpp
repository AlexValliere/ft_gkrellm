/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OSmodule.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 21:42:33 by hades             #+#    #+#             */
/*   Updated: 2015/01/18 16:33:09 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSMODULE_CLASS_HPP
# define OSMODULE_CLASS_HPP

# include <gtk/gtk.h>
# include <iostream>
# include "IMonitorModule.class.hpp"

class OSmodule : public IMonitorModule
{
public:
	OSmodule( int position );
	OSmodule( OSmodule const & model );
	~OSmodule( void );

	OSmodule&		operator=( OSmodule const & model );

	std::string		getData( void ) const;
	std::string		getName( void ) const;
	int				getPosition( void ) const;

	std::string		getArchitecture( void ) const;
	std::string		getReleaseVersion( void ) const;
	std::string		getSystemName( void ) const;

	void			addToGtk(GtkWidget* widget) const;
	void			findData( void );
	void			drawNcurses( int maxWidth ) const;

private:
	int				_position;
	std::string		_data;
	std::string		_name;
	
	std::string		_architecture;
	std::string		_releaseVersion;
	std::string		_systemName;

	OSmodule( void );
};


#endif /* OSMODULE_CLASS_HPP */