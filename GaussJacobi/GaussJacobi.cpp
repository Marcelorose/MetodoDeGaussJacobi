// GaussJacobi.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include "pch.h"
#include <iostream>
#define COL 4
#define LIN 3
#define E 0.00001

using namespace std;


void mostrarVetor(double vetor[LIN]) {
	for (int i = 0; i < LIN; i++)
	{
		cout << "X" << i + 1 << " = " << vetor[i] << " ";
	}
	cout << endl;
}

void passarValores(double vetorA[LIN], double vetorB[LIN]) {
	for (int i = 0; i < LIN; i++)
	{
		vetorA[i] = vetorB[i];
	}
}

double valorE(double vetorA[LIN], double vetorB[LIN]) {
	double resultado[LIN];
	double maiorA = vetorA[0], maiorResultado;
	for (int i = 0; i < LIN; i++)
	{
		resultado[i] = vetorA[i] - vetorB[i];
	}
	maiorResultado = resultado[0];
	for (int i = 0; i < LIN; i++)
	{
		if (fabs(vetorA[i]) > maiorA)
		{
			maiorA = fabs(vetorA[i]);
		}
		if (fabs(resultado[i]) > maiorResultado)
		{
			maiorResultado = fabs(resultado[i]);
		}
		return maiorResultado / maiorA;
	}

}

int main()
{
	double matriz[LIN][COL] = { 10, 2, 1, 7, 1, 5, 1, -8, 2, 3, 10, 6 };
	double vetorX[LIN];
	double vetorAux[LIN];
	double aux, aux1 = 0;
	double e = 10;

	for (int i = 0; i < LIN; i++)
	{
		vetorX[i] = matriz[i][COL - 1] / matriz[i][i];
	}
	mostrarVetor(vetorX);
	while (e > E)
	{
		for (int i = 0; i < LIN; i++)
		{
			aux = 1 / matriz[i][i];
			aux1 = matriz[i][COL - 1];
			for (int j = 0; j < LIN; j++)
			{
				if (i == j && j == LIN - 1)
				{
					break;
				}
				else if(i == j)
				{
					j++;
				}
				aux1 = aux1 - (matriz[i][j] * vetorX[j]);
			}	
			vetorAux[i] = aux * aux1;
		}
		e = valorE(vetorAux, vetorX);
		passarValores(vetorX, vetorAux);
		mostrarVetor(vetorX);	
	}

}


