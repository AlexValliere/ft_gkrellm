/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Refresh.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 17:46:59 by alex              #+#    #+#             */
/*   Updated: 2015/01/18 18:38:03 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Refresh.class.hpp"

CPUmodule	Refresh::cpu_module = 0;
DTmodule	Refresh::datetime_module = 0;
Rmodule		Refresh::ram_module = 0;

GtkWidget*	Refresh::pWindow = 0;
GtkWidget*	Refresh::pVBox = 0;
GtkWidget*	Refresh::pDatetimeLabel = 0;
GtkWidget*	Refresh::pMemLabel = 0;