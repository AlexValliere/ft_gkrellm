#include <gtk/gtk.h>

/*
 *
 *		LES FENETRES ALIAS WINDOW
 *
 */

void OnDestroy(GtkWidget *pWidget, gpointer pData)
{
	/* Arret de la boucle evenementielle */
	gtk_main_quit();
}

int main(int argc, char *argv[])
{
	/* Declaration du widget */
	GtkWidget *window;

	gtk_init (&argc, &argv);

	/* Création de la fenêtre */
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title (GTK_WINDOW (window), "Example 2");

	// Connaître le nom de la fenêtre
	// G_CONST_RETURN gchar* gtk_window_get_title(GtkWindow *window);

	// La fonction pour définir la taille par défaut de la fenêtre est :
	gtk_window_set_default_size(GTK_WINDOW(window), 260, 500);

	// Permet de définir si l'utilisateur peut changer la taille de la fenêtre
	gtk_window_set_resizable(GTK_WINDOW(window), false);

	// If no child widgets, use this to fix size (http://stackoverflow.com/questions/4772804/how-to-set-a-fixed-windows-size-in-gtk-and-c) :
	gtk_widget_set_size_request(window, 260, 500);

	// Pour savoir si la fenêtre est resizeable
	// gboolean gtk_window_get_resizable(GtkWindow *window);

	// La fonction pour obtenir la taille de la fenêtre :
	// void gtk_window_get_default_size(GtkWindow *window, gint *width, gint *height);

	/* Sortir de la boucle infini gtk_main à l'aide du callback gtk_main_quit lors d'un clic sur la croix, alias le signal "destroy" */
	g_signal_connect (window, "destroy", G_CALLBACK (OnDestroy), NULL);

	// Permet de définir la position de la fenêtre avant son affichage.
	// Le premier paramètre étant de type GtkWindow*, il faudra convertir la fenêtre (de type GtkWidget*) avec la macro GTK_WINDOW
	/* GTK_WIN_POS_NONE : la fenêtre aura une position aléatoire lors de son affichage ;
		GTK_WIN_POS_CENTER : la fenêtre sera centrée à l'écran ;
		GTK_WIN_POS_MOUSE : le coin supérieur droit de la fenêtre correspondra à la position de la souris au moment de l'affichage ;
		GTK_WIN_POS_CENTER_ALWAYS : la fenêtre sera centrée et ne pourra être déplacée ;
		GTK_WIN_POS_CENTER_ON_PARENT : la fenêtre sera centrée par rapport à la fenêtre parente (notion abordée dans le prochain chapitre). */
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

	// Fonction utilisable à tout moment du programme et permet de donner la position exacte de la fenêtre
	// Le premier paramètre est toujours la fenêtre dont on veut modifier la position.
	// Les deux autres paramètres sont la nouvelle position de la fenêtre. Le paramètre x est la position suivante l'axe X (axe horizontal) et le paramètre y, la position suivant l'axe Y (axe vertical). Le type gint est le type int du C
	// void gtk_window_move(GtkWindow *window, gint x, gint y);

	// À l'inverse, pour connaître la position de la fenêtre, il faut utiliser cette fonction
	// Les paramètres correspondent aux mêmes valeurs que pour la fonction gtk_window_move.
	// void gtk_window_get_position(GtkWindow *window, gint *root_x, gint *root_y);

	/* Affichage de la fenêtre */
	gtk_widget_show (window);

	/* Demarrage de la boucle evenementielle */
	gtk_main ();

	return 0;
}