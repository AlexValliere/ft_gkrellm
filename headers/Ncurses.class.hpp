/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurses.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hades <hades@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 17:18:58 by alex              #+#    #+#             */
/*   Updated: 2015/01/18 02:57:52 by hades            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURSE_CLASS_HPP
# define NCURSE_CLASS_HPP

# include <ncurses.h>
# include <iostream>
# include <vector>
# include "IMonitorDisplay.class.hpp"
# include "IMonitorModule.class.hpp"

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