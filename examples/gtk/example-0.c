#include <gtk/gtk.h>

int
main (int   argc,
      char *argv[])
{
  GtkWidget *window;

  // initialization function for GTK+; this function will set up GTK+, the type system, the connection to the windowing environment, etc.
  // The gtk_init() takes as arguments the pointers to the command line arguments counter and string array; this allows GTK+ to parse specific command line arguments that control the behavior of GTK+ itself. The parsed arguments will be removed from the array, leaving the unrecognized ones for your application to parse.
  gtk_init (&argc, &argv);

  // The call to gtk_window_new() will create a new GtkWindow and store it inside the window variable. The type of the window is GTK_WINDOW_TOPLEVEL, which means that the GtkWindow will be managed by the windowing system: it will have a frame, a title bar and window controls, depending on the platform.
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window), "Window");

  // In order to terminate the application when the GtkWindow is destroyed, we connect the “destroy” signal to the gtk_main_quit() function. This function will terminate the GTK+ main loop started by calling gtk_main() later
  g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

  // GtkWidgets are hidden by default. By calling gtk_widget_show() on a GtkWidget we are asking GTK+ to set the visibility attribute so that it can be displayed. All this work is done after the main loop has been started.
  gtk_widget_show (window);

  // The last line of interest is the call to gtk_main(). This function will start the GTK+ main loop and will block the control flow of the main() until the gtk_main_quit() function is called.
  gtk_main ();

  return 0;
}