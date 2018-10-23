#include <gtk/gtk.h>
#include <stdlib.h>
#include "raizes.h"
#include "sinais.h"

GtkBuilder* builder;
//FUNÇÃO DOS BOTÕES MÉTODOS
void met_todos(GtkWidget *widget, gpointer user_data){

	const gchar *input_n_text, *input_a_text, *input_epsilon_text;

	//Reconhecendo as caixas de texto
	GtkWidget *input_n, *input_a, *input_epsilon, *text_exec;
	input_n = GTK_WIDGET(gtk_builder_get_object(builder, "input_n"));
	input_a = GTK_WIDGET(gtk_builder_get_object(builder, "input_a"));
	input_epsilon = GTK_WIDGET(gtk_builder_get_object(builder, "input_epsilon"));
	text_exec = GTK_WIDGET(gtk_builder_get_object(builder, "text_exec"));
	
	GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_exec));
	GtkTextIter start, end, iter;
	char *leitor;
	FILE *arq;

	//Get das entradas
	input_n_text = gtk_entry_get_text(GTK_ENTRY(input_n));
	input_a_text = gtk_entry_get_text(GTK_ENTRY(input_a));
	input_epsilon_text = gtk_entry_get_text(GTK_ENTRY(input_epsilon));

	char input_a_text_copy[strlen(input_a_text)];
	strcpy(input_a_text_copy,input_a_text);

	int n = atoi(input_n_text);

	double a[n];
	double epsilon = atof(input_epsilon_text);
	char *token = strtok(input_a_text_copy,", ");

	for(int i = 0; i < n && token; i++){
		param_a = a[i] = atof(token);

		inic_arq_saida(NEWTON);
		raiz_newton(f, derivf, CHUTE, epsilon, LIMITE_ITER);
		token = strtok(NULL, ", ");
	}
	arq = fopen("data/newton.txt", "r");
	fseek (arq , 0 , SEEK_END);
	int tamanho = ftell (arq);
	rewind (arq);
	leitor = (char*) malloc (sizeof(char)*tamanho);
	fread (leitor,1,tamanho,arq);

	fscanf(arq, "%s", leitor);
	gtk_text_buffer_get_iter_at_offset(buffer, &iter, 0);
	
	gtk_text_buffer_insert(buffer, &iter, leitor, -1);
}

void met_newt(GtkWidget *widget, gpointer user_data){

	const gchar *input_n_text, *input_a_text, *input_epsilon_text;

	//Reconhecendo as caixas de texto
	GtkWidget *input_n, *input_a, *input_epsilon;
	input_n = GTK_WIDGET(gtk_builder_get_object(builder, "input_n"));
	input_a = GTK_WIDGET(gtk_builder_get_object(builder, "input_a"));
	input_epsilon = GTK_WIDGET(gtk_builder_get_object(builder, "input_epsilon"));

	//Get das entradas
	input_n_text = gtk_entry_get_text(GTK_ENTRY(input_n));
	input_a_text = gtk_entry_get_text(GTK_ENTRY(input_a));
	input_epsilon_text = gtk_entry_get_text(GTK_ENTRY(input_epsilon));

	char input_a_text_copy[strlen(input_a_text)];
	strcpy(input_a_text_copy,input_a_text);

	int n = atoi(input_n_text);

	double a[n];
	double epsilon = atof(input_epsilon_text);
	char *token = strtok(input_a_text_copy,", ");

	for(int i = 0; i < n && token; i++){
		param_a = a[i] = atof(token);

		inic_arq_saida(NEWTON);
		raiz_newton(f, derivf, CHUTE, epsilon, LIMITE_ITER);
		token = strtok(NULL, ", ");
	}
}

void met_newtMod(GtkWidget *widget, gpointer user_data){

	const gchar *input_n_text, *input_a_text, *input_epsilon_text;

	//Reconhecendo as caixas de texto
	GtkWidget *input_n, *input_a, *input_epsilon;
	input_n = GTK_WIDGET(gtk_builder_get_object(builder, "input_n"));
	input_a = GTK_WIDGET(gtk_builder_get_object(builder, "input_a"));
	input_epsilon = GTK_WIDGET(gtk_builder_get_object(builder, "input_epsilon"));

	//Get das entradas
	input_n_text = gtk_entry_get_text(GTK_ENTRY(input_n));
	input_a_text = gtk_entry_get_text(GTK_ENTRY(input_a));
	input_epsilon_text = gtk_entry_get_text(GTK_ENTRY(input_epsilon));

	char input_a_text_copy[strlen(input_a_text)];
	strcpy(input_a_text_copy,input_a_text);

	int n = atoi(input_n_text);

	double a[n];
	double epsilon = atof(input_epsilon_text);
	char *token = strtok(input_a_text_copy,", ");

	for(int i = 0; i < n && token; i++){
		param_a = a[i] = atof(token);

		inic_arq_saida(NEWTON);
		raiz_newton_mod(f, derivf, CHUTE, epsilon, LIMITE_ITER);
		token = strtok(NULL, ", ");
	}
}

void met_secan(GtkWidget *widget, gpointer user_data){
	
	const gchar *input_n_text, *input_a_text, *input_epsilon_text;

	//Reconhecendo as caixas de texto
	GtkWidget *input_n, *input_a, *input_epsilon;
	input_n = GTK_WIDGET(gtk_builder_get_object(builder, "input_n"));
	input_a = GTK_WIDGET(gtk_builder_get_object(builder, "input_a"));
	input_epsilon = GTK_WIDGET(gtk_builder_get_object(builder, "input_epsilon"));

	//Get das entradas
	input_n_text = gtk_entry_get_text(GTK_ENTRY(input_n));
	input_a_text = gtk_entry_get_text(GTK_ENTRY(input_a));
	input_epsilon_text = gtk_entry_get_text(GTK_ENTRY(input_epsilon));

	char input_a_text_copy[strlen(input_a_text)];
	strcpy(input_a_text_copy,input_a_text);

	int n = atoi(input_n_text);

	double a[n];
	double epsilon = atof(input_epsilon_text);
	char *token = strtok(input_a_text_copy,", ");

	for(int i = 0; i < n && token; i++){
		param_a = a[i] = atof(token);

		inic_arq_saida(NEWTON);
		raiz_secante(f, CHUTE, CHUTE+1, epsilon, LIMITE_ITER);
		token = strtok(NULL, ", ");
	}
}

//FUNÇÃO DOS BOTÕES OPÇÕES
void op_log(GtkWidget *widget, gpointer user_data){
	//Criar aquivo de LOG
}
