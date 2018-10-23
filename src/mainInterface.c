#include  <gtk/gtk.h>
#include <stdlib.h>
#include "raizes.h"
#include "sinais.h"

int main(int argc, char *argv[]){
	GtkWidget *window;

	gtk_init(&argc, &argv);

	builder = gtk_builder_new();
	gtk_builder_add_from_file(builder, "mainui.glade", NULL);

	window = GTK_WIDGET(gtk_builder_get_object(builder, "mainui"));
	gtk_builder_connect_signals(builder, NULL);

	gtk_widget_show(window);
	gtk_main();

	return 0;
}
