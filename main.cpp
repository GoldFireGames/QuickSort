#include <iostream>
#include <cstdlib>
#include <ctime>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

void wypisz(int tab[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<tab[i]<<" ";
    }
    cout<<endl;
}


/////////////////////////////////wybór elementu skrajnego/////////////////////////////////

int partition(int tab[], int poczatek, int koniec)
{
    int pivot = tab[poczatek];

    int licznik = 0;
    for (int i=poczatek+1; i<=koniec; i++)
    {
        if (tab[i] <= pivot)
            licznik++;
    }

    int pivotIndex = poczatek + licznik;// Giving pivot element its correct position
    swap(tab[pivotIndex], tab[poczatek]);

    int i = poczatek, j = koniec;// Sorting left and right parts of the pivot element

    while (i < pivotIndex && j > pivotIndex)
    {
        while (tab[i] <= pivot)
        {
            i++;
        }
        while (tab[j] > pivot)
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(tab[i++], tab[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int tab[], int poczatek, int koniec)
{
    if (poczatek >= koniec)// base case
        return;
    int p = partition(tab, poczatek, koniec);// partitioning the array

    quickSort(tab, poczatek, p - 1);// Sorting the left part

    quickSort(tab, p + 1, koniec);// Sorting the right part
}

/////////////////////////////////wybór pseudolosowy/////////////////////////////////




int partition2(int tab[], int poczatek, int koniec)
{
    int pivot =tab[koniec];

    int i = (poczatek - 1);// Index of smaller element

    for (int j = poczatek; j <= koniec - 1; j++)
    {
        if (tab[j] <= pivot)// If current element is smaller than or equal to pivot
        {
            i++;// increment index of smaller element
            swap(tab[i], tab[j]);
        }
    }
    swap(tab[i + 1], tab[koniec]);
    return (i + 1);

}
int losowyIndeks(int tab[], int poczatek, int koniec)
{
    srand(time(NULL));
    int los = poczatek + rand()%(koniec-poczatek);
    swap(tab[los],tab[koniec]);

    return partition2(tab,poczatek,koniec);
}

void quickSort2(int tab[], int poczatek, int koniec)
{
    if (poczatek >= koniec)// base case
    {
        return;
    }
    else
    {
        int p = losowyIndeks(tab, poczatek, koniec);// partitioning the array
        quickSort2(tab, poczatek, p - 1);// Sorting the left part
        quickSort2(tab, p + 1, koniec);// Sorting the right part
    }
}

/////////////////////////////////wybór mediany z 3, 5 oraz 7 elementów/////////////////////////////////



int median(int tab[],int poczatek, int koniec, int n)     // obliczanie pozycji pivota przez medaine
{
    if(n==3)
    {
        // cout<<"robie dla 3"<<endl;
        if(koniec-poczatek>=3)
        {
            int* tabp=new int(3); //tablica pomocnicza

            tabp[0]=tab[poczatek];
            //cout<<endl<<tabp[0]<<endl;
            tabp[1]=tab[poczatek+(koniec-poczatek)/2];
            //cout<<endl<<tabp[1]<<endl;
            tabp[2]=tab[koniec];
            //cout<<endl<<tabp[2]<<endl;


            if(tabp[0]>tab[1])
            {
                swap(tabp[0],tabp[1]);
            }
            if(tabp[0]>tabp[2])
            {
                swap(tabp[0],tabp[2]);
            }
            if(tabp[1]>tabp[2])
            {
                swap(tabp[1],tabp[2]);
            }

            tab[poczatek]=tabp[0];
            tab[koniec]=tabp[2];
            tab[poczatek+((koniec-poczatek)/2)]=tabp[1];

            swap(tab[poczatek+((koniec-poczatek)/2)],tab[koniec-1]);
            delete[] tabp;
            return koniec-1;
        }
        else
        {
            //cout<<endl<<"bez median"<<endl;
            return koniec;
        }
    }
    else if(n==5)
    {
        //  cout<<"robie dla 5"<<endl;
        if(koniec-poczatek>=5)
        {


            int* tabp=new int(5);

            tabp[0]=tab[poczatek];
            //cout<<endl<<tabp[0]<<endl;
            tabp[1]=tab[poczatek+((koniec-poczatek)/4)];
            tabp[2]=tab[poczatek+(koniec-poczatek)/2];
            //cout<<endl<<tabp[1]<<endl;
            tabp[3]=tab[poczatek+(((koniec-poczatek)/2)+((koniec-poczatek)/4))];
            tabp[4]=tab[koniec];
            //cout<<endl<<tabp[2]<<endl;

            quickSort2(tabp,0,5-1);

            tab[poczatek]=tabp[0];
            tab[koniec]=tabp[4];
            tab[poczatek+((koniec-poczatek)/2)]=tabp[2];
            tab[poczatek+(((koniec-poczatek)/2)+((koniec-poczatek)/4))]=tabp[3];
            tab[poczatek+((koniec-poczatek)/4)]=tabp[1];

            swap(tab[poczatek+((koniec-poczatek)/2)],tab[koniec-1]);
            delete[] tabp;
            return koniec-1;
        }
        else
        {
//            cout<<endl<<"bez median"<<endl;
            return koniec;
        }
    }
    else if(n==7)
    {
        //cout<<"robie dla 7"<<endl;
        if(koniec-poczatek>=7)
        {
            int* tabp=new int(7);

            tabp[0]=tab[poczatek];
            //cout<<endl<<tabp[0]<<endl;
            tabp[1]=tab[poczatek+((koniec-poczatek)/6)];
            tabp[2]=tab[poczatek+((koniec-poczatek)/3)];
            tabp[3]=tab[poczatek+(koniec-poczatek)/2];
            //cout<<endl<<tabp[1]<<endl;
            tabp[4]=tab[poczatek+(((koniec-poczatek)/2)+((koniec-poczatek)/6))];
            tabp[5]=tab[poczatek+(((koniec-poczatek)/2)+((koniec-poczatek)/3))];
            tabp[6]=tab[koniec];

            quickSort2(tabp,0,7-1);

            tab[poczatek]=tabp[0];
            tab[koniec]=tabp[6];
            tab[poczatek+((koniec-poczatek)/2)]=tabp[3];
            tab[poczatek+(((koniec-poczatek)/2)+((koniec-poczatek)/6))]=tabp[4];
            tab[poczatek+((koniec-poczatek)/6)]=tabp[1];
            tab[poczatek+(((koniec-poczatek)/2)+((koniec-poczatek)/3))]=tabp[5];
            tab[poczatek+((koniec-poczatek)/3)]=tabp[2];


            swap(tab[poczatek+((koniec-poczatek)/2)],tab[koniec-1]);
            delete[] tabp;
            return koniec-1;
        }
        else
        {
            return koniec;
        }
    }


}

int partition3(int tab[], int poczatek, int koniec)   // partition ( wykorzytsywane we wszytskich ponizszych funkcjach
{
    int pivot = tab[koniec];
    int i= (poczatek- 1);

    for (int j = poczatek; j <= koniec - 1; j++)
    {

        if (tab[j] < pivot)
        {
            i++;
            swap(tab[i], tab[j]);
        }
    }
    swap(tab[i + 1], tab[koniec]);

    return (i + 1);
}

void quickSort3(int tab[], int poczatek, int koniec,int n)
{


    if (poczatek >= koniec)
        return;

    int m = median(tab, poczatek, koniec,n);

    int p=partition3(tab,poczatek,m);

    quickSort3(tab, poczatek, p - 1,n);


    quickSort3(tab, p + 1, koniec,n);
}

    void wybierz(int *tab, int i, int wynik)
    {
        if(wynik == 1)
        {
        return quickSort(tab,0,i-1);
        }else if(wynik == 2)
        {
        return quickSort2(tab,0,i-1);
        }else if(wynik == 3)
        {
        return quickSort3(tab,0,i-1,3);
        }else if(wynik == 4)
        {
        return quickSort3(tab,0,i-1,5);
        }else if(wynik == 5)
        {
        return quickSort3(tab,0,i-1,7);
        }

    }

int main()
{



    clock_t start, end;
    int wybor;
    cout<<"wybierz na jakiej  tablicy chcesz pracowac: "<<endl;
    cout<<"tablica z elementami przekraczajacymi rozmiar tablicy| wpisz [1]"<<endl;
    cout<<"tablica z elementami od 0 do 99| wpisz [2]"<<endl;
    cout<<"tablica niemalejaca| wpisz [3]"<<endl;

    cin>>wybor;
    cout<<endl;

            cout<<"wybor elementu skrajnego | [1]"<<endl;
            cout<<"wybor pseudolosowy | [2]"<<endl;
            cout<<"wybor z mediany z 3 | [3]"<<endl;
            cout<<"wybor z mediany z 5 | [4]"<<endl;
            cout<<"wybor z mediany z 7 | [5]"<<endl;

        int wynik;
        cout<<"podaj wynik: ";
        cin>>wynik;
        cout<<endl;

    switch(wybor)
    {
    case 1:
    {
        for(int i=10000; i<110000; i=i+10000)
        {
            srand(time(NULL));
            int* tab = new int[i];
            for(int j=0; j<i; j++)
            {
                tab[j]=rand()%(2*i)+i;
            }
             start = clock();

            wybierz(tab,i,wynik);

             end = clock();
            // wypisz(tab,n);
            double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
            cout << "Time taken by program is : " << fixed
                 << time_taken << setprecision(5);
            cout << " sec " << endl;
            delete []tab;
        }
        break;
    }
    case 2:
    {

        for(int i=10000; i<110000; i=i+10000)
        {
            srand(time(NULL));
            int* tab2 = new int[i];
            for(int j=0; j<i; j++)
            {
                tab2[j]=rand()%100;
            }

            start = clock();

            wybierz(tab2,i,wynik);

            end = clock();
            double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
            cout << "Time taken by program is : " << fixed
                 << time_taken << setprecision(5);
            cout << " sec " << endl;
            delete []tab2;

        }
        break;
    }

    case 3:
    {

        for(int i=10000; i<110000; i=i+10000)
        {
            srand(time(NULL));
            int* tab3 = new int[i];
            for(int j=0; j<i; j++)
            {
                tab3[j]=j;
            }

            start = clock();

            wybierz(tab3,i,wynik);

            end = clock();
            double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
            cout << "Time taken by program is : " << fixed
                 << time_taken << setprecision(5);
            cout << " sec " << endl;
            delete []tab3;
        }
        break;
    }

    }







    return 0;
}
