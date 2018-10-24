#ifndef SINAIS_H_LXLVIGQ9
#define SINAIS_H_LXLVIGQ9

extern GtkBuilder* builder;

G_MODULE_EXPORT void met_todos(GtkWidget *widget, gpointer user_data);
G_MODULE_EXPORT void met_newt(GtkWidget *widget, gpointer user_data);
G_MODULE_EXPORT void met_newtMod(GtkWidget *widget, gpointer user_data);
G_MODULE_EXPORT void met_secan(GtkWidget *widget, gpointer user_data);

G_MODULE_EXPORT void op_log(GtkWidget *widget, gpointer user_data);

#endif /* end of include guard: sinais_h_lxlvigq9 */
