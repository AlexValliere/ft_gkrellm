/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.class.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:56:10 by alex              #+#    #+#             */
/*   Updated: 2015/01/18 15:52:12 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_CLASS_HPP
# define IMONITORMODULE_CLASS_HPP

# include <gtk/gtk.h>

class IMonitorModule
{
public:
	virtual void 	findData() = 0;
	virtual void	addToGtk( GtkWidget* widget ) const = 0;
	virtual ~IMonitorModule();
};

#endif