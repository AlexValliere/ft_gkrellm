/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurses.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 17:18:58 by alex              #+#    #+#             */
/*   Updated: 2015/01/17 17:24:00 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURSE_CLASS_HPP
# define NCURSE_CLASS_HPP

# include "IMonitorDisplay.class.hpp"

class Ncurses : public IMonitorDisplay
{
public:
	Ncurses(void);
	Ncurses(Ncurses const & object);
	~Ncurses();

	void		display();

	Ncurses&	operator=(Ncurses const & rhs);
};

#endif