/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rmodule.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 21:42:37 by hades             #+#    #+#             */
/*   Updated: 2015/01/18 16:39:47 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RMODULE_CLASS_HPP
# define RMODULE_CLASS_HPP

# include <gtk/gtk.h>
# include <iostream>
# include "IMonitorModule.class.hpp"

class Rmodule : public IMonitorModule
{
public:
	Rmodule( int position );
	Rmodule( Rmodule const & model );
	~Rmodule( void );

	Rmodule&		operator=( Rmodule const & model );

	std::string		getData( void ) const;
	std::string		getName( void ) const;
	int				getPosition( void ) const;

	std::string		getFreeMem( void ) const;
	std::string		getNbrProcess( void ) const;
	std::string		getTotalMem( void ) const;
	std::string		getUptime( void ) const;

	void			addToGtk(GtkWidget* widget) const;
	void			findData( void );
	void			drawNcurses( int maxWidth ) const;

private:
	int				_position;
	std::string		_data;
	std::string		_name;
	std::string		_freeMem;
	std::string		_nbrProcess;
	std::string		_totalMem;
	std::string		_uptime;

	Rmodule( void );
};


#endif /* RMODULE_CLASS_HPP */