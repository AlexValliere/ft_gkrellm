/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Refresh.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 17:47:08 by alex              #+#    #+#             */
/*   Updated: 2015/01/18 18:38:30 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REFRESH_CLASS_HPP
# define REFRESH_CLASS_HPP

# include <gtk/gtk.h>
# include "CPUmodule.class.hpp"
# include "DTmodule.class.hpp"
# include "Rmodule.class.hpp"


class Refresh
{
public:
	static CPUmodule	cpu_module;
	static DTmodule		datetime_module;
	static Rmodule		ram_module;

	static GtkWidget*	pWindow;
	static GtkWidget*	pVBox;
	static GtkWidget*	pDatetimeLabel;
	static GtkWidget*	pMemLabel;

private:
	Refresh(void);
	Refresh(Refresh const & object);
	~Refresh();

	Refresh&	operator=(Refresh const & rhs);
};

#endif