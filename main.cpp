//
//  main.cpp
//  Lab_8
//
#include <iostream>
#include <locale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int Vyb;
    int Mass [10000];
    
    
    for (int i=0; i<10000; i++)
    {
        Mass[i]=0;
    }
    
    
    cout << "Выберите подзадачу из варианта. (1-3)" << endl;
    cin >> Vyb;
        
    if (Vyb==1)
    {
        int Vvod; int i=0; int Izmen=0; int n, first=-1;
        
        while (cin >> Vvod)
        {
            Mass[i]=Vvod;
            i++; n = Vvod;
            
            while(n>0)
                {
                    first=n%10;
                    n=n/10;
                }
            
            if (first == 1) Izmen = 1;
        }
        
        if (Izmen==1)
        {
            for (int j=0; j<i; j++)
            {
                for (int g=0; g<i-1; g++)
                {
                    if (Mass[g]>Mass[g+1])
                    {
                        int temp = Mass[g];
                        Mass[g] = Mass[g+1];
                        Mass[g+1] = temp;
                    }
                }
            }
        }
        
        cout << endl << endl;
        
        for (int j=0; j<i; j++)
        {
            cout << Mass[j] << " ";
        }
    }
    
    if (Vyb==2)
    {
        int Vvod; int i=0; int n, n1, first=-1, first1=-1;
        int Sum=0, Sum1=0;
        
        int *Masss;
        
        while (cin >> Vvod)
        {
            Mass[i]=Vvod;
            i++;
        }
        
        Masss = new int [i];
        
        for (int t=0; t<i; i++)
        {
            Masss[i]=Mass[i];
        }
        
        for (int j=0; j<i; j++)
        {
            for (int g=0; g<i-1; g++)
            {
                n = Masss[g];
                n1 = Masss[g+1];
                
                while(n>0)
                    {
                        first=n%10;
                        n=n/10;
                    }
                while(n1>0)
                    {
                        first1=n1%10;
                        n1=n1/10;
                    }
                
                if (first>first1)
                {
                    int temp = Masss[g];
                    Masss[g] = Masss[g+1];
                    Masss[g+1] = temp;
                }
                if (first==first1)
                {
                    n = Masss[g];
                    n1 = Masss[g+1];
                    while(n>0)
                        {
                            Sum=Sum+n%10;
                            n=n/10;
                        }
                    while(n1>0)
                        {
                            Sum1=Sum1+n1%10;
                            n1=n1/10;
                        }
                    
                    if (Sum>Sum1)
                    {
                        int temp = Masss[g];
                        Masss[g] = Masss[g+1];
                        Masss[g+1] = temp;
                    }
                    if (Sum==Sum1)
                    {
                        if (Masss[g]>Masss[g+1])
                        {
                            int temp = Masss[g];
                            Masss[g] = Masss[g+1];
                            Masss[g+1] = temp;
                        }
                    }
                }
            }
        }
        
        cout << endl << endl;
        
        for (int j=0; j<i; j++)
        {
            cout << Masss[j] << " ";
        }
        delete [] Masss;
    }
    
    if (Vyb==3)
    {
        int Vvod, i, j; int Sum=0; int Naim=10000000, Col=0;
        int *Arr;
        
        cout << "Введите размеры масива." << endl;
        cin >> i >> j;
        
        Arr = new int [i*j];
        
        for (int i1=0; i1<i; i1++)
        {
            for (int j1=0; j1<j; j1++)
            {
                cin >> Vvod;
                Arr[((i+1)*i1)+j1] = Vvod;
            }
        }
        
        for (int i1=0; i1<i; i1++)
        {
            for (int j1=0; j1<j; j1++)
            {
                Sum = Sum + Arr[((i+1)*i1)+j1];
            }
            if (Sum<Naim)
            {
                Naim=Sum;
                Col=i1;
            }
            
            Sum=0;
        }
        
        for (int i1=0; i1<j; i1++)
        {
            Arr[((i+1)*Col)+i1]=0;
        }
        
        for (int i1=0; i1<i; i1++)
        {
            for (int j1=0; j1<j; j1++)
            {
                cout << Arr[((i+1)*i1)+j1] << " ";
            }
            cout << endl;
        }
        
        delete [] Arr;
    }
    
    
    return 0;
}
