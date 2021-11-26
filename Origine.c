#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

typedef int t_info;
typedef struct s_nodo {
	t_info label;
	struct s_node* sx;
	struct s_node* dx;
} t_nodo;
typedef t_nodo* t_albero;

t_albero costruisci(t_info info, t_albero sx, t_albero dx) {
	t_nodo* aux = (t_nodo*)malloc(sizeof(t_nodo));
	aux->label = info;
	aux->sx = sx;
	aux->dx = dx;
	return aux;
}

void costruisci(t_info info, t_albero sx, t_albero dx, t_albero* nuovo_albero) {
	t_nodo* aux = (t_nodo*)malloc(sizeof(t_nodo));
	aux->label = info;
	aux->sx = sx;
	aux->dx = dx;

	*nuovo_albero = aux;
}

void visita_preordine(t_albero albero) {
	if (albero == NULL)
		return;
	stampo_contenuto(albero->label);
	visita_preordine(albero->sx);
	visita_preordine(albero->dx);
}
void visita_simmetrico(t_albero albero) {
	if (albero == NULL)
		return;
	visita_preordine(albero->sx);
	stampo_contenuto(albero->label);
	visita_preordine(albero->dx);
}
void visita_postordine(t_albero albero) {
	if (albero == NULL)
		return;
	visita_preordine(albero->sx);
	visita_preordine(albero->dx);
	stampo_contenuto(albero->label);
}
