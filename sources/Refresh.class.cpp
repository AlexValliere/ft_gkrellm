/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Refresh.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 17:46:59 by alex              #+#    #+#             */
/*   Updated: 2015/01/18 18:07:01 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Refresh.class.hpp"

CPUmodule	Refresh::cpu_module = 0;
DTmodule	Refresh::datetime_module = 0;
HSmodule	Refresh::host_and_user_names_module = 0;
OSmodule	Refresh::os_module = 0;
Rmodule		Refresh::ram_module = 0;