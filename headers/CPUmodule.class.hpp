/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUmodule.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 21:42:07 by hades             #+#    #+#             */
/*   Updated: 2015/01/18 16:19:18 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPUMODULE_CLASS_HPP
# define CPUMODULE_CLASS_HPP

# include <gtk/gtk.h>
# include <iostream>
# include <map>
# include <vector>
# include "IMonitorModule.class.hpp"

class CPUmodule : public IMonitorModule
{
public:
	CPUmodule( int position );
	CPUmodule( CPUmodule const & model );
	~CPUmodule( void );

	CPUmodule 	& operator=( CPUmodule const & model );

	std::string		getData( void ) const;	
	std::string		getName( void ) const;
	int				getPosition( void ) const;

	std::string		getCores( void ) const;
	std::string		getModelName( void ) const;
	std::string		getVendorID( void ) const;
	std::string		getCPUCoresSpeed( void ) const;

	void			addToGtk(GtkWidget* widget) const;
	void			drawNcurses( int maxWidth ) const;
	void			findData( void );

private:
	int				_position;
	std::string		_data;
	std::string		_name;
	std::string		_cores;
	std::string		_modelName;
	std::string		_vendorID;
	std::string		_CPUCoresSpeed;

	CPUmodule( void );
};


#endif /* CPUMODULE_CLASS_HPP */