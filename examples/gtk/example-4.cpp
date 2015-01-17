#include <gtk/gtk.h>
#include <iostream>

#define EXEMPLE_1 0
#define EXEMPLE_2 1

/*
 *
 *		LES BOUTONS ALIAS LABEL
 *
 */

void AddBtn(GtkWidget *pWindow, gint iExemple);

void OnDestroy(GtkWidget *pWidget, gpointer pData)
{
	gtk_main_quit();
}

int	main(int argc, char *argv[])
{
	gtk_init (&argc, &argv);

	GtkWidget *window;
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title (GTK_WINDOW (window), "Example 4");
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	g_signal_connect (window, "destroy", G_CALLBACK (OnDestroy), NULL);

	/* Connexion du signal "destroy" de la fenetre */
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    /* Insertion du bouton */
    // AddBtn(window, EXEMPLE_1); // Quitter en cliquant sur le bouton
    AddBtn(window, EXEMPLE_2); // Quitter en cliquant sur le bouton ou en appuyant sur les touches claviers alt + q

	// GtkWidget *pQuitBtn;
	/*  GTK+ permet l'utilisation de quatre fonctions différentes pour initialiser un button
		GtkWidget* gtk_button_new(void);
		GtkWidget* gtk_button_new_with_label(const gchar *label);
		GtkWidget* gtk_button_new_with_mnemonic(const gchar *label);
		GtkWidget* gtk_button_new_from_stock(const gchar *stock_id);

		La première fonction permet de créer un bouton vide. Cela permet de personnaliser complètement le bouton car GtkButton dérive de GtkContainer. On peut donc inclure n'importe quel type de widget dans le bouton (label, image…).

		La deuxième fonction s'occupe en plus d'insérer un label à l'intérieur du bouton. Le paramètre label correspond au texte à afficher. Comme pour le widget GtkLabel, si un caractère accentué est utilisé, il faudra appeler la fonction g_locale_to_utf8 pour avoir un affichage correct du texte.

		La troisième fonction ajoute à cela une nouvelle fonctionnalité. Elle permet, en plus d'afficher un label, de faire réagir le bouton à l'aide d'un raccourci clavier. La touche servant de raccourci est spécifiée dans le paramètre label. Il suffit de mettre « _ » devant la lettre souhaitée pour que la combinaison Atl+Touche active le bouton. Par exemple pour l'application de ce chapitre, le texte à afficher sera « Quitter » et si nous voulons que la combinaison de touches Atl+Q permette de quitter l'application, le paramètre label devra être « _Quitter ».

		La quatrième fonction permet de créer un bouton avec un label, un raccourci clavier et une image. Cependant, pour faire cela, GTK+ utilise les GtkStockItem qui est une structure contenant les informations sur le label et l'image à afficher. GTK+ comporte déjà beaucoup de GtkStockItem prédéfinis (en tout cas les plus courants). Le paramètre stock_id est donc l'identifiant du GtkStockItem à utiliser. Pour notre exemple, l'identifiant est GTK_STOCK_QUIT.
	*/

	/* Nous allons surveiller le signal « clicked » qui est émis lorsque l'utilisateur clique sur le bouton. Lorsque ce signal est reçu nous allons appeler gtk_main_quit pour fermer l'application et détruire tous les widgets.
	Connexion du signal "destroy" de la fenetre :
	g_signal_connect(G_OBJECT(pQuitBtn), "clicked", G_CALLBACK(gtk_main_quit), NULL); */

	gtk_widget_show_all(window);

	gtk_main ();

	return 0;
}

/*
  void AddBtn(GtkWidget *pWindow, gint iExemple)
  
  Fonction en charge d'inserer le bouton dans la fenetre
 
  Parametre :
  - pWindow : fenetre parente
  - iExemple : mode de creation 
  EXEMPLE_1 pour un bouton label
  EXEMPLE_2 pour un bouton EXEMPLE_1 + raccourci
*/
void AddBtn(GtkWidget *pWindow, gint iExemple)
{
	GtkWidget *pQuitBtn;
	switch(iExemple)
	{
	default:
	case EXEMPLE_1:
		/* Bouton avec un label */
		pQuitBtn = gtk_button_new_with_label("Quitter");
		gtk_window_set_title(GTK_WINDOW(pWindow), "Les boutons - Exemple 1");
		break;
	case EXEMPLE_2:
		/* Bouton avec un label et un raccourci */
		pQuitBtn = gtk_button_new_with_mnemonic("_Quitter");
		gtk_window_set_title(GTK_WINDOW(pWindow), "Les boutons - Exemple 2");
		break;
	}
	/* Connexion du signal "clicked" du bouton */
	g_signal_connect(G_OBJECT(pQuitBtn), "clicked", G_CALLBACK(gtk_main_quit), NULL);
	/* Insertion du bouton dans la fenetre */
	gtk_container_add(GTK_CONTAINER(pWindow), pQuitBtn);
}