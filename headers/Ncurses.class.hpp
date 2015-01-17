/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurses.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 17:18:58 by alex              #+#    #+#             */
/*   Updated: 2015/01/17 17:38:44 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURSE_CLASS_HPP
# define NCURSE_CLASS_HPP

# include <ncurses.h>
# include "IMonitorDisplay.class.hpp"

class Ncurses : public IMonitorDisplay
{
public:
	Ncurses(void);
	Ncurses(Ncurses const & object);
	~Ncurses();

	void			display();

	Ncurses&		operator=(Ncurses const & rhs);

	unsigned int	getRefreshRate() const;
	void			setRefreshRate(unsigned int newRefreshRate);

private:
	unsigned int	_refreshRate;
};

#endif