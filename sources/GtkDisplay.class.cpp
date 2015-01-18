/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GtkDisplay.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 00:55:22 by alex              #+#    #+#             */
/*   Updated: 2015/01/18 01:31:54 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtk/gtk.h>
#include "../headers/GtkDisplay.class.hpp"

void	OnDestroy(GtkWidget *pWidget, gpointer pData)
{
	gtk_main_quit();
	(void)pWidget;
	(void)pData;
}

GtkDisplay::GtkDisplay(int argc, char *argv[]) {
	gtk_init (&argc, &argv);

	this->_window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

	gtk_window_set_title (GTK_WINDOW (this->_window), "ft_gkrellm");
	gtk_window_set_default_size(GTK_WINDOW(this->_window), 150, 500);
	gtk_window_set_resizable(GTK_WINDOW(this->_window), false);
	gtk_widget_set_size_request(this->_window, 150, 500);
	gtk_window_set_position(GTK_WINDOW(this->_window), GTK_WIN_POS_CENTER);
	g_signal_connect (this->_window, "destroy", G_CALLBACK (OnDestroy), NULL);

	return ;
}

void		GtkDisplay::display() {
	gtk_widget_show_all(this->_window);
	gtk_main();

	return ;
}

GtkDisplay::~GtkDisplay()	{ return ; }