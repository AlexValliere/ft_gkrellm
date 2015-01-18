/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GtkDisplay.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 00:55:31 by alex              #+#    #+#             */
/*   Updated: 2015/01/18 01:31:55 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GTKDISPLAY_CLASS_HPP
# define GTKDISPLAY_CLASS_HPP

# include <gtk/gtk.h>
# include "IMonitorDisplay.class.hpp"

class GtkDisplay : public IMonitorDisplay
{
public:
	GtkDisplay(int argc, char *argv[]);
	GtkDisplay(GtkDisplay const & object);
	~GtkDisplay();

	GtkDisplay&	operator=(GtkDisplay const & rhs);

	void		display();

private:
	GtkWidget*	_window;

	GtkDisplay(void);
};

#endif