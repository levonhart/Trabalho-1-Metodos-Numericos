#include  <gtk/gtk.h>
#include <math.h>
#include <stdlib.h>
#include "raizes.h"

#define COEFICIENTE 1.0
#define PREC_PADRAO 0.0001
#define CHUTE 0.5
#define LIMITE_ITER 50

GtkBuilder *builder;

#include "aux_func.c"
#include "sinais.c"

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