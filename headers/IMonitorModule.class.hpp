/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.class.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:56:10 by alex              #+#    #+#             */
/*   Updated: 2015/01/17 16:58:01 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_CLASS_HPP
# define IMONITORMODULE_CLASS_HPP

class IMonitorModule
{
public:
	IMonitorModule(void);
	IMonitorModule(IMonitorModule const & object);
	~IMonitorModule();

	IMonitorModule&	operator=(IMonitorModule const & rhs);
};

#endif