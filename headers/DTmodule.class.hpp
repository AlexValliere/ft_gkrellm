/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DTmodule.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 21:42:17 by hades             #+#    #+#             */
/*   Updated: 2015/01/18 15:55:25 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DTMODULE_CLASS_HPP
# define DTMODULE_CLASS_HPP

# include <gtk/gtk.h>
# include <iostream>
# include "IMonitorModule.class.hpp"
# include "usual_functions.hpp"

class DTmodule : public IMonitorModule
{
public:
	DTmodule( int position );
	DTmodule( DTmodule const & model );
	~DTmodule( void );

	DTmodule&		operator=( DTmodule const & model );

	std::string		getData( void ) const;	
	std::string		getName( void ) const;
	int				getPosition( void ) const;

	std::string		getDate( void ) const;
	std::string		getTime( void ) const;

	void			addToGtk(GtkWidget* widget) const;
	void			drawNcurses( int maxWidth ) const;
	void			findData( void );

private:
	int				_position;
	std::string		_data;
	std::string		_name;
	std::string		_date;
	std::string		_time;

	DTmodule( void );
};


#endif /* DTMODULE_CLASS_HPP */