#include <exception>
#include <iostream>
#include "assignment2.h"


using namespace std;

class ExceptieAssignment2 : public std::exception {};

int numarElementeMaiMari(int* valori, int nrValori, int valoarePrag)
{
	int nrValoriMaiMariSauEgale;  
	nrValoriMaiMariSauEgale = 0;  //COMENTARIU 1: Aici as fi initializat variabila nrValoriMaiMariSauEgale direct la declarare, nu ulterior. Nu avea rost sa ma intind pe 2 linii de cod.
	for (int i = 0; i < nrValori; i++)
		if (valori[i] >= valoarePrag)
			nrValoriMaiMariSauEgale++;
	return nrValoriMaiMariSauEgale;
}

int* filtrareElementeMaiMari(int* valori, int nrValori, int valoarePrag)
{
	int *vectorNou;
	vectorNou = new int[nrValori];
	int j = 0;
	for (int i = 0; i < nrValori; i++)
	{
		if (valori[i] >= valoarePrag)
		{
			vectorNou[j] = valori[i]; 
			j++; 
		}
	}
	if(j)
	return vectorNou;
	else return NULL;
}

void filtrareElementeMaiMari2(int* valori, int nrValori, int valoarePrag, int** valoriMaiMari)
{
	int j = 0;
	for (int i = 0; i < nrValori; i++)
	{
		if (valori[i] >= valoarePrag)
		{
			*(valoriMaiMari+j) =&valori[i];
			j++;
		}
	}
}

int getElement(int* valori, int nrValori, int index)
{
	
		if (index < 0 || index >= nrValori)
			throw new ExceptieAssignment2();
		else 
		{ 
			int x=valori[index]
			return x; //COMENTARIU 2: Aici nu era nevoie sa mi declar o noua variabila pentru a returna un element din vector. As fi putut sa returnez direct valori[index]. 
		}
	
}

int* slice(int* valori, int nrValori, int indexStart, int indexFinal, int& dimensiuneSubvector)
{
	if (indexStart<0 || indexFinal<0 || indexStart>=nrValori )
		throw new ExceptieAssignment2();
	if (indexFinal >= nrValori || indexStart > indexFinal)
		throw new ExceptieAssignment2();  //COMENTARIU 3: Puteam scrie toate conditiile intr-un singur if, avand in vedere ca ambele arunca aceeasi exceptie
	else if (indexStart == indexFinal)
	{
		dimensiuneSubvector = 1;
		int* subvector;
		subvector= new int[dimensiuneSubvector];
		subvector[0] = valori[indexStart];
		return subvector;
	}
	else
	{
		dimensiuneSubvector = indexFinal;
		dimensiuneSubvector = dimensiuneSubvector-indexStart;
		dimensiuneSubvector = dimensiuneSubvector + 1; //COMENTARIU 4: Aici puteam sa scriu pe un singur rand cele trei operatii asupra variabilei dimensiuneSubvector, mai exact: dimensiuneSubvector=indexFinal-indexStart+1;
		int *subvector;
		subvector = new int[dimensiuneSubvector];
		int j = 0;
		for (int i = indexStart; i <= indexFinal; i++)
		{
			subvector[j] = valori[i];
			j++;
		}
		return subvector;
	}
}
int main()
{
	int vector[] = { 23,67,89,102,560,1000 }, dimensiune = 6, valoarePrag[] = { 100,2000 };
	int variabilaRezultat; // COMENTARIU 5: Puteam initializa aceste int-uri pe o singura linie pentru a fi codul mai organizat
	int* vectorNou;//la fel si aici 
	int* vectorNou2;
	int* subvector; 
	for (int i = 0; i < 2; i++)
	{
		vectorNou2 = { NULL };
		variabilaRezultat = numarElementeMaiMari(vector, dimensiune, valoarePrag[i]);
		cout << "In vectorul dat exista "<<variabilaRezultat <<" elemente mai mari sau egale cu "<<valoarePrag[i]<< endl;
		vectorNou = filtrareElementeMaiMari(vector, dimensiune, valoarePrag[i]); //Filtrare elemente mai mari sau egale
		if (vectorNou == NULL)
			cout << "Nu exista valori in vector mai mari sau egale cu " << valoarePrag[i] << endl;
		else
		{
			cout << "Elementele din vectorul dat mai mari sau egale cu " << valoarePrag[i] << " sunt: ";
			for (int i = 0; i < variabilaRezultat; i++)
			{
				cout << vectorNou[i] << " ";
			}
			cout << endl;
		}

		filtrareElementeMaiMari2(vector, dimensiune, valoarePrag[i], &vectorNou2); //Filtrare elemente mai mari sau egale (2)
		if (vectorNou2 == NULL)
		{
			cout << "Nu avem elemente in noul vector in urma aplicarii functiei filtarerElementeMaiMari2" << endl;
		}
		else
		{
			cout << "Vectorul rezultat in urma aplicarii functiei filtarerElementeMaiMari2 este: ";
			for (int i = 0; i < variabilaRezultat; i++)
			{
				cout << vectorNou2[i] << " ";
			}
			cout << endl;
		}
	}
	int index[] = {0,1,5,6,-1,1000}, elementExtras;
	for (int i = 0; i < 6; i++)
	{
		try
		{
			elementExtras = getElement(vector, dimensiune, index[i]);
			cout << "Elementul din vector avand indexul "<<index[i]<<" este: "<<elementExtras << endl;
		}
		catch (ExceptieAssignment2* ex)
		{
			cout << "Indexul nu este valid!!" << endl;
		}
	}
	
	int indexStart[] = { 2,2,-2,2,2,2}, indexFinal[] = {4,2,4,-4,40,1}, dimensiuneSubvector = 0;
	for (int i = 0; i < 6; i++)
	{
		subvector = { NULL };
		try
		{
			subvector = slice(vector, dimensiune, indexStart[i], indexFinal[i], dimensiuneSubvector);
			cout<<"Subvectorul rezultat avand ca limite intervalul ["<<indexStart[i]<<","<<indexFinal[i]<<"] este: ";
			for (int i = 0; i < dimensiuneSubvector; i++)
				cout << subvector[i] << " ";
			cout << endl;
		}
		catch (ExceptieAssignment2* ex)
		{
			cout << "Indecsii nu sunt valizi!!"<<endl;
		}

	}
	
	return 0;
}