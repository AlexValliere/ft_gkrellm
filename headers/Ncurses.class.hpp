/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurses.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 17:18:58 by alex              #+#    #+#             */
/*   Updated: 2015/01/17 17:21:35 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURSE_CLASS_HPP
# define NCURSE_CLASS_HPP

# include "IMonitorDisplay.class.hpp"

class Ncurses : public IMonitorDisplay
{
public:
	Ncurses();
	~Ncurses();
};

#endif