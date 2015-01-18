#include <gtk/gtk.h>
#include <iostream>

/*
 *
 *		LES TEXTES ALIAS LABEL
 *
 */

void OnDestroy(GtkWidget *pWidget, gpointer pData)
{
	gtk_main_quit();
}

int main(int argc, char *argv[])
{
	gtk_init (&argc, &argv);

	GtkWidget *window;
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title (GTK_WINDOW (window), "Example 3");
	gtk_window_set_default_size(GTK_WINDOW(window), 260, 500);
	gtk_window_set_resizable(GTK_WINDOW(window), false);
	gtk_widget_set_size_request(window, 260, 500);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	g_signal_connect (window, "destroy", G_CALLBACK (OnDestroy), NULL);

	/* La balise span accepte les attributs suivants:
		font_family :
			Exemple : <span font_family=\"Courier New\">Courier New</span>

		face :
			Exemple : <span face=\"Times New Roman\">Times New Roman</span>

		size :
			Exemple : <span size=\"12\">Taille 12</span>
		style : normal, oblique, italic.
			Exemple : <span style=\"oblique\">Oblique</span>

		desc : Permet de combiner les paramètres précédents en un seul.
			Exemple : <span font_desc=\"Courier New italic 12\">Courier New italic 12</span>

		weight : Permet de définir l'épaisseur des lettres. Les valeurs peuvent être ultralight, light, normal, bold, utrabold, heavy ou encore une valeur numérique. (Vous remarquerez qu'il n'y a que peu ou pas de différence).
			Exemple : <span weight=\"bold\">Bold</span>

		variant : Pour définir si l'on veut du texte normal (normal) ou en petite majuscule (smallcaps).
			Exemple : <span variant=\"smallcaps\">Smallcaps</span>
			Afin de pourvoir l'utiliser, il faut avoir la police : nom smallcaps

		stretch : Permet d'étirer le texte. La valeur de ce paramètre peut être : ultracondensed, extracondensed, condensed, semicondensed, normal, semiexpanded, expanded, extraexpanded, ultraexpanded.
			Exemple : <span stretch=\"ultracondensed\">Smallcaps</span>
			Afin de pourvoir l'utiliser, il faut avoir la police : nom condensed (ou autre).

		foreground : Pour définir la couleur du texte. Il faut donner la valeur hexadécimale de la palette RVB.
			Exemple : <span foreground=\"#FF0000\">Couleur Texte</span>

		background : Pour définir la couleur du fond. Il faut donner la valeur hexadécimale de la palette RVB.
			Exemple : <span background=\"#FF0000\">Couleur Texte</span>

		underline : single, double, low ou none. Pour souligner le texte.
			Exemple : <span underline=\"double\">Double</span>

		rise : Pour déplacer le texte verticalement.

		strikethrough : Pour barrer le texte.
			Exemple : <span strikethrough=\"true\">Striketrough = "true"</span>

		lang : Pour indiquer la langue du texte.
	*/

	// Aligner le texte:
	// void gtk_label_set_justify(GtkLabel *label, GtkJustification jtype);
	/* GTK_JUSTIFY_LEFT pour aligner le texte à gauche (par défaut) ;
		GTK_JUSTIFY_RIGHT pour aligner le texte à droite ;
		GTK_JUSTIFY_CENTER pour centrer le texte ;
		GTK_JUSTIFY_FILL pour justifier le texte. */

	// Pour obtenir l'alignement du texte:
	// GtkJustification gtk_label_get_justify(GtkLabel *label);

	// Changer le texte d'un GtkLabel:
	// void gtk_label_set_text(GtkLabel* label, const char* str)
	// void gtk_label_set_label(GtkLabel* label, const gchar* str)

	// Permet de recevoir l'adresse de la chaîne de caractère affichée par le label.
	// G_CONST_RETURN gchar* gtk_label_get_text(GtkLabel* label)
	// G_CONST_RETURN gchar* gtk_label_get_label(GtkLabel* label)

	// Permet de savoir si un label utilise les balises de formatages Pango.
	// gboolean gtk_label_get_use_markup(GtkLabel *label);

	std::string	txt = "<span foreground=\"#FF4500\"><b>New</b> test label<sup><b>42</b></sup></span>";
	GtkWidget	*pLabel = gtk_label_new(txt.c_str());

	// Permet d'activer les balises  Pango: b, big (font++), i, s, sub, sup, small(font--), tt (type teletype: genre courrier new en font), u
	gtk_label_set_use_markup(GTK_LABEL(pLabel), true);

	gtk_container_add(GTK_CONTAINER(window), pLabel);

	gtk_widget_show_all(window);

	gtk_main ();

	return 0;
}