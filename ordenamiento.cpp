/*
Rogelio Eduardo Benavides De La Rosa
Fecha de £ltima modificaci¢n: 22/02/2022
Programa de b£squeda y ordenamiento de Enteros, Doubles, Caracteres y Strings
Doy mi palabra de que he realizado esta actividad con integridad acad‚mica
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// M‚todo de ordenamiento por selecci¢n
// Complejidad de tiempo = O(n^2)   Complejidad de Espacio = O(1)
template <class T>
vector<T> selectionSort(vector<T> lista)
{
    // Variable auxiliar para el intercambio de posiciones
    T aux;
    // Contadores de Comparaciones e Intercambios
    int contadorC = 0;
    int contadorI = 0;
    // For que se repite una vez por la cantidad de elementos
    for (int i = 0; i < lista.size(); i++)
    {
        int menor = i;
        for (int j = 0 + i; j < lista.size(); j++)
        {
            if (lista[j] < lista[menor])
            {
                menor = j;
            }
            contadorC++;
        }
        // Se intercambia el menor valor al primer elemento del arreglo
        aux = lista[menor];
        lista[menor] = lista[i];
        lista[i] = aux;
        contadorI++;
    }
    // Se imprimen las cantidades de comparaciones e intercambios
    cout << "La cantidad de comparaciones realizadas fue: " << contadorC << endl;
    cout << "La cantidad de intercambios realizados fue: " << contadorI << endl;
    return lista;
}

// M‚todo de ordenamiento por inserci¢n
// Complejidad de tiempo = O(n^2)   Complejidad de Espacio = O(1)
template <class T>
vector<T> insertionSort(vector<T> lista)
{
    // Variable auxiliar para el intercambio de posiciones
    T aux;
    // Contadores de Comparaciones e Intercambios
    int contadorC = 0;
    int contadorI = 0;
    // For que se repite una vez por la cantidad de elementos
    for (int i = 1; i < lista.size(); i++)
    {
        // For que checa cada elemento con el de al lado
        for (int j = i; j > 0; j--)
        {
            // Si el elemento en j es menor a el elemento a su izquierda lo cambia
            if (lista[j - 1] > lista[j])
            {
                aux = lista[j - 1];
                lista[j - 1] = lista[j];
                lista[j] = aux;
                contadorI++;
            }
            contadorC++;
        }
    }
    // Se imprimen las cantidades de comparaciones e intercambios
    cout << "La cantidad de comparaciones realizadas fue: " << contadorC << endl;
    cout << "La cantidad de intercambios realizados fue: " << contadorI << endl;
    return lista;
}

// M‚todo de ordenamiento de burbuja
// Complejidad de tiempo = O(n^2)   Complejidad de Espacio = O(1)
template <class T>
vector<T> bubbleSort(vector<T> lista)
{
    // Variable auxiliar para el intercambio de posiciones
    T aux;
    // Contadores de Comparaciones e Intercambios
    int contadorC = 0;
    int contadorI = 0;
    // For que se repite una vez por cada elementos
    for (int j = lista.size() - 1; j >= 0; j--)
    {
        // For que checa cada elemento con el de la derecha y lo cambia si es menor
        for (int i = 0; i < lista.size() - 1; i++)
        {
            if (lista[i + 1] < lista[i])
            {
                aux = lista[i];
                lista[i] = lista[i + 1];
                lista[i + 1] = aux;
                contadorI++;
            }
            contadorC++;
        }
    }
    // Se imprimen las cantidades de comparaciones e intercambios
    cout << "La cantidad de comparaciones realizadas fue: " << contadorC << endl;
    cout << "La cantidad de intercambios realizados fue: " << contadorI << endl;
    return lista;
}

// Contador de comparaciones del Quick Sort
int contadorCQ = 0;

// M‚todo de partici¢n para el quickSort
template <class T>
int particion(vector<T> &lista, int inicio, int fin)
{
    // Öndices
    int i, j;
    // Variable auxiliar para el intercambio de posiciones
    T aux;
    // Punto de pivote en donde se separan las listas
    T pivote = lista[inicio];
    j = inicio;
    // For que recorre todos los elementos de la lista
    for (i = inicio + 1; i <= fin; i++)
    {
        // Si el elemento en el punto i es menor que el elemento del pivote se cambia de lugar el elemento en el punto i por el elemento en el punto j
        if (lista[i] < pivote)
        {
            j++;
            aux = lista[i];
            lista[i] = lista[j];
            lista[j] = aux;
        }
        contadorCQ++;
    }
    // Al final del m‚todo se intercambian el elemento en el inicio por el elemento en la posici¢n j
    aux = lista[inicio];
    lista[inicio] = lista[j];
    lista[j] = aux;
    return j;
}

// M‚todo de ordenamiento Quick Sort
// Complejidad de tiempo = O(n^2)   Complejidad de Espacio = O(log(n))
template <class T>
void quickSort(vector<T> &lista, int inicio, int fin)
{
    if (inicio < fin)
    {
        // Se encuentra el punto de pivote
        int pivote = particion(lista, inicio, fin);
        // Se llama de manera recursiva al metodo desde el inicio hasta la mitad y luego desde la mitad hasta el final
        quickSort(lista, inicio, pivote - 1);
        quickSort(lista, pivote + 1, fin);
    }
}

// Contador de comparaciones del m‚todo mergeSort
int contadorCM = 0;

// M‚todo para juntar las listas
template <class T>
void merge(vector<T> listaIzq, vector<T> listaDer, vector<T> &lista, int tamIzq, int tamDer)
{
    // Contadores para comparar el tama¤o de la lista
    int i = 0, j = 0, k = 0;
    // Mientras que el tama¤o de la lista de la izquierda y el tama¤o de la lista de la derecha sean mayores a 1 se agregan los elementos a la lista
    // Se agrega el elemento m s peque¤o de la lista y se incrementa en uno el contador correspondiente
    while (i < tamIzq && j < tamDer)
    {
        if (listaIzq[i] < listaDer[j])
        {
            lista[k] = listaIzq[i];
            i++;
        }
        else
        {
            lista[k] = listaDer[j];
            j++;
        }
        k++;
        contadorCM++;
    }
    // Si faltaron elementos en cualquiera de las dos listas se agregan a la lista y se incrementa el contador correspondiente
    if (i > tamIzq - 1)
    {
        for (int indice = j; indice < tamDer; indice++)
        {
            lista[k] = listaDer[indice];
            k++;
        }
    }
    else
        for (int indice = i; indice < tamIzq; indice++)
        {
            lista[k] = listaIzq[indice];
            k++;
        }
}

// M‚todo de ordenamiento Merge Sort
// Complejidad de tiempo = O(n*log(n))   Complejidad de Espacio = O(n)
template <class T>
void mergeSort(vector<T> &lista, int n)
{
    if (n > 1)
    {
        // Se registran los tama¤os de las listas de izquierda y derecha
        int tamIzq = n / 2;
        int tamDer = n - tamIzq;
        // Se crean las listas de izquierda y derecha y se llenan, la primera mitad se ingresa en la lista Izquierda y la otra mitad en la lista derecha
        vector<T> listaIzq, listaDer;
        for (int i = 0; i < tamIzq; i++)
        {
            listaIzq.push_back(lista[i]);
        }
        for (int i = tamIzq; i < n; i++)
        {
            listaDer.push_back(lista[i]);
        }
        // Se llama recursivamente el mergeSort para separar las listas hasta que el tama¤o de las dos sea igual a uno
        mergeSort(listaIzq, tamIzq);
        mergeSort(listaDer, tamDer);
        // Se juntan las listas y se ordenan
        merge(listaIzq, listaDer, lista, listaIzq.size(), listaDer.size());
    }
}

// M‚todo de b£squeda secuencial
// Complejidad de tiempo = O(n)
template <class T>
int busquedaSecuencial(vector<T> lista, T dato)
{
    // For que recorre todos los elementos de la lista
    for (int i = 0; i < lista.size(); i++)
    {
        // Si el elemento es igual al dato buscado retorna la posici¢n de la lista en donde se encuentra
        if (lista[i] == dato)
            return i;
    }
    return -1;
}

// M‚todo de b£squeda binaria
// Complejidad de tiempo = O(log(n))
template <class T>
int busquedaBinaria(vector<T> lista, T dato)
{
    // Öndices de derecha e izquierda
    int izq = 0;
    int der = lista.size() - 1;
    // Se compara dato buscado con el dato a la mitad del arreglo y si no es igual, checa si es mayor o menor y dependiendo de esto se busca del lado izquierdo o del derecho
    while (izq <= der)
    {
        int mitad = (izq + der) / 2;
        if (lista[mitad] == dato)
        {
            return mitad;
        }
        else
        {
            if (dato < lista[mitad])
            {
                der = mitad - 1;
            }
            else
                izq = mitad + 1;
        }
    }
    return -1;
}

// M‚todo que muestra el men£ de b£squeda
template <class T>
void menuBusqueda(vector<T> lista)
{
    // Dato a buscar por b£squeda secuencial o binaria
    T dato;
    // Opci¢n del m‚todo de ordenamiento que se eligir 
    int opcion = 0;
    double tiempo;
    // Men£ de Ordenamiento
    do
    {
        cout << "\nMen£ de B£squeda\n";
        cout << "1) B£squeda Selecci¢n\n";
        cout << "2) B£squeda Binaria\n";
        cout << "3) Salir\n";
        cin >> opcion;
        // Se resetea la lista
        cout << endl;
        switch (opcion)
        {
        case 1:
        {
            // Se pide el dato a buscar
            cout << "Ingresa el dato que deseas buscar: ";
            cin >> dato;
            // Se empieza a tomar el tiempo de ejecuci¢n
            auto start = chrono::high_resolution_clock::now();
            // Se busca la posici¢n del elemento
            int posicion = busquedaSecuencial(lista, dato);
            // Se termina de tomar el tiempo de ejecuci¢n
            auto end = chrono::high_resolution_clock::now();
            tiempo = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
            tiempo *= 1e-9;
            cout << fixed;
            cout.precision(6);
            cout << "Tiempo de ejecuci¢n: " << tiempo << " segundos " << endl;
            // Se valida si el tipo de dato es double
            string tipoDato = typeid(lista[0]).name();
            // Se muestra si se encontr¢ o no el elemento
            if (dato == lista[posicion])
            {
                if (tipoDato == "d")
                {
                    cout << fixed;
                    cout.precision(2);
                }
                cout << "El dato " << dato << " se encuentra en la posici¢n " << posicion + 1 << " de la lista";
            }
            else
            {
                if (tipoDato == "d")
                {
                    cout << fixed;
                    cout.precision(2);
                }
                cout << "El dato " << dato << " no se encuentra en la lista";
            }
            break;
        }
        case 2:
        {
            // Se pide el dato a buscar
            cout << "Ingresa el dato que deseas buscar: ";
            cin >> dato;
            // Se ordena la lista
            sort(lista.begin(), lista.end());
            // Se empieza a tomar el tiempo de ejecuci¢n
            auto start = chrono::high_resolution_clock::now();
            // Se busca la posici¢n del elemento
            int posicion = busquedaBinaria(lista, dato);
            // Se termina de tomar el tiempo de ejecuci¢n
            auto end = chrono::high_resolution_clock::now();
            tiempo = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
            tiempo *= 1e-9;
            cout << fixed;
            cout.precision(6);
            cout << "Tiempo de ejecuci¢n: " << tiempo << " segundos " << endl;
            // Se valida si el tipo de dato es double
            string tipoDato = typeid(lista[0]).name();
            // Se muestra si se encontr¢ o no el elemento
            if (dato == lista[posicion])
            {
                if (tipoDato == "d")
                {
                    cout << fixed;
                    cout.precision(2);
                }
                cout << "El dato " << dato << " se encuentra en la posici¢n " << posicion + 1 << " de la lista";
            }
            else
            {
                if (tipoDato == "d")
                {
                    cout << fixed;
                    cout.precision(2);
                }
                cout << "El dato " << dato << " no se encuentra en la lista";
            }
            break;
        }
        default:
        {
            if (opcion < 1 || opcion > 3)
                cout << "Por favor elegir: 1, 2, o 3";
        }
        }
        cout << endl;
    } while (opcion != 3);
}

// M‚todo que muestra el men£ de ordenamiento y b£squeda
template <class T>
void menuOrdenamiento(vector<T> lista)
{
    // Opci¢n del m‚todo de ordenamiento que se eligir 
    int opcion = 0;
    // Lista que se modifica en los algoritmos recursivos y que se restablece al valor de la lista original cada vez que itera el ciclo
    vector<T> listaInicial;
    // Variable en donde se almacena el tiempo que se tardan los algoritmos
    double tiempo;
    // Men£ de Ordenamiento
    do
    {
        cout << "\nMen£ de Ordenamiento\n";
        cout << "1) Ordena el arreglo con el m‚todo de selecci¢n\n";
        cout << "2) Ordena el arreglo con el m‚todo de inserci¢n\n";
        cout << "3) Ordena el arreglo con el m‚todo de burbuja\n";
        cout << "4) Ordena el arreglo con el m‚todo de quicksort\n";
        cout << "5) Ordena el arreglo con el m‚todo de mergesort\n";
        cout << "6) Salir\n";
        cin >> opcion;
        // Se resetea la lista
        listaInicial = lista;
        cout << endl;
        switch (opcion)
        {
        // Se realiza el ordenamiento por selecci¢n
        case 1:
        {
            // Se empieza a tomar el tiempo de ejecuci¢n
            auto start = chrono::high_resolution_clock::now();
            // Se ordena la lista
            listaInicial = selectionSort(listaInicial);
            // Se termina de tomar el tiempo de ejecuci¢n
            auto end = chrono::high_resolution_clock::now();
            tiempo = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
            tiempo *= 1e-9;
            cout << fixed;
            cout.precision(6);
            cout << "Tiempo de ejecuci¢n: " << tiempo << " segundos " << endl;
            cout << "Lista Ordenada: " << endl;
            // Se imprime la lista ordenada
            string tipoDato = typeid(listaInicial[0]).name();
            if (tipoDato == "d")
            {
                cout << fixed;
                cout.precision(2);
            }
            for (int i = 0; i < listaInicial.size(); i++)
            {
                if (i != listaInicial.size() - 1)
                    cout << listaInicial[i] << ", ";
                else
                    cout << listaInicial[i];
            }
            cout << endl;
            menuBusqueda(listaInicial);
            break;
        }
        // Se realiza el ordenamiento por inserci¢n
        case 2:
        {
            // Se empieza a tomar el tiempo de ejecuci¢n
            auto start = chrono::high_resolution_clock::now();
            // Se ordena la lista
            listaInicial = insertionSort(listaInicial);
            // Se termina de tomar el tiempo de ejecuci¢n
            auto end = chrono::high_resolution_clock::now();
            tiempo = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
            tiempo *= 1e-9;
            cout << fixed;
            cout.precision(6);
            cout << "Tiempo de ejecuci¢n: " << tiempo << " segundos " << endl;
            cout << "Lista Ordenada: " << endl;
            string tipoDato = typeid(listaInicial[0]).name();
            // Se imprime la lista ordenada
            if (tipoDato == "d")
            {
                cout << fixed;
                cout.precision(2);
            }
            for (int i = 0; i < listaInicial.size(); i++)
            {
                if (i != listaInicial.size() - 1)
                    cout << listaInicial[i] << ", ";
                else
                    cout << listaInicial[i];
            }
            cout << endl;
            menuBusqueda(listaInicial);
            break;
        }
        case 3:
        {
            // Se empieza a tomar el tiempo de ejecuci¢n
            auto start = chrono::high_resolution_clock::now();
            // Se ordena la lista
            listaInicial = bubbleSort(listaInicial);
            // Se termina de tomar el tiempo de ejecuci¢n
            auto end = chrono::high_resolution_clock::now();
            tiempo = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
            tiempo *= 1e-9;
            cout << fixed;
            cout.precision(6);
            cout << "Tiempo de ejecuci¢n: " << tiempo << " segundos " << endl;
            cout << "Lista Ordenada: " << endl;
            string tipoDato = typeid(listaInicial[0]).name();
            // Se imprime la lista ordenada
            if (tipoDato == "d")
            {
                cout << fixed;
                cout.precision(2);
            }
            for (int i = 0; i < listaInicial.size(); i++)
            {
                if (i != listaInicial.size() - 1)
                    cout << listaInicial[i] << ", ";
                else
                    cout << listaInicial[i];
            }
            cout << endl;
            menuBusqueda(listaInicial);
            break;
        }
        case 4:
        {
            // Se empieza a tomar el tiempo de ejecuci¢n
            auto start = chrono::high_resolution_clock::now();
            // Se ordena la lista
            quickSort(listaInicial, 0, listaInicial.size() - 1);
            // Se termina de tomar el tiempo de ejecuci¢n
            auto end = chrono::high_resolution_clock::now();
            tiempo = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
            tiempo *= 1e-9;
            cout << "La cantidad de comparaciones realizadas fue: " << contadorCQ << endl;
            cout << fixed;
            cout.precision(6);
            cout << "Tiempo de ejecuci¢n: " << tiempo << " segundos " << endl;
            cout << "Lista Ordenada: " << endl;
            string tipoDato = typeid(listaInicial[0]).name();
            // Se imprime la lista ordenada
            if (tipoDato == "d")
            {
                cout << fixed;
                cout.precision(2);
            }
            for (int i = 0; i < listaInicial.size(); i++)
            {
                if (i != listaInicial.size() - 1)
                    cout << listaInicial[i] << ", ";
                else
                    cout << listaInicial[i];
            }
            contadorCQ = 0;
            cout << endl;
            menuBusqueda(listaInicial);
            break;
        }
        case 5:
        {
            // Se empieza a tomar el tiempo de ejecuci¢n
            auto start = chrono::high_resolution_clock::now();
            // Se ordena la lista
            mergeSort(listaInicial, listaInicial.size());
            // Se termina de tomar el tiempo de ejecuci¢n
            auto end = chrono::high_resolution_clock::now();
            tiempo = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
            tiempo *= 1e-9;
            cout << fixed;
            cout.precision(6);
            cout << "Tiempo de ejecuci¢n: " << tiempo << " segundos " << endl;
            cout << "La cantidad de comparaciones realizadas fue: " << contadorCM << endl;
            cout << "Lista Ordenada: " << endl;
            string tipoDato = typeid(listaInicial[0]).name();
            // Se imprime la lista ordenada
            if (tipoDato == "d")
            {
                cout << fixed;
                cout.precision(2);
            }
            for (int i = 0; i < listaInicial.size(); i++)
            {
                if (i != listaInicial.size() - 1)
                    cout << listaInicial[i] << ", ";
                else
                    cout << listaInicial[i];
            }
            contadorCM = 0;
            cout << endl;
            menuBusqueda(listaInicial);
            break;
        }
        default:
        {
            if (opcion < 1 || opcion > 6)
                cout << "Por favor elegir: 1, 2, 3, 4, 5 o 6";
        }
        }
        cout << endl;
    } while (opcion != 6);
    cout << endl;
}

// M‚todo main
int main(int argc, char const *argv[])
{
    // Opci¢n que se eligir  en el men£
    int opcion = 0;
    // Cantidad de elementos en el arreglo
    int cantidad;
    do
    {
        cout << "\nMen£ de Arreglos\n";
        cout << "1) Arreglo de Enteros\n";
        cout << "2) Arreglo de Doubles\n";
        cout << "3) Arreglo de Caracteres\n";
        cout << "4) Arreglo de Strings\n";
        cout << "5) Salir\n";
        cin >> opcion;
        cout << endl;
        // Switch que dependiendo de la opci¢n te pide un arreglo de tipo distinto
        switch (opcion)
        {
        // M‚todo que pide un arreglo de enteros y manda a llamar el m‚todo de men£ de ordenamiento
        case 1:
        {
            cout << "Ingresa la cantidad de Enteros: ";
            cin >> cantidad;
            vector<int> lista;
            int datoIngresado;
            for (int i = 0; i < cantidad; i++)
            {
                cout << "Ingresa el Entero #" << i + 1 << ": ";
                cin >> datoIngresado;
                lista.push_back(datoIngresado);
            }
            menuOrdenamiento(lista);
            break;
        }
        // M‚todo que pide un arreglo de doubles y manda a llamar el m‚todo de men£ de ordenamiento
        case 2:
        {
            cout << "Ingresa la cantidad de Doubles: ";
            cin >> cantidad;
            vector<double> lista;
            double datoIngresado;
            for (int i = 0; i < cantidad; i++)
            {
                cout << "Ingresa el Double #" << i + 1 << ": ";
                cin >> datoIngresado;
                lista.push_back(datoIngresado);
            }
            menuOrdenamiento(lista);
            break;
        }
        // M‚todo que pide un arreglo de caracteres y manda a llamar el m‚todo de men£ de ordenamiento
        case 3:
        {
            cout << "Ingresa la cantidad de Caracteres: ";
            cin >> cantidad;
            vector<char> lista;
            char datoIngresado;
            for (int i = 0; i < cantidad; i++)
            {
                cout << "Ingresa el Caracter #" << i + 1 << ": ";
                cin >> datoIngresado;
                lista.push_back(datoIngresado);
            }
            menuOrdenamiento(lista);
            break;
        }
        // M‚todo que pide un arreglo de strings y manda a llamar el m‚todo de men£ de ordenamiento
        case 4:
        {
            cout << "Ingresa la cantidad de Strings: ";
            cin >> cantidad;
            vector<string> lista;
            string datoIngresado;
            for (int i = 0; i < cantidad; i++)
            {
                cout << "Ingresa el String #" << i + 1 << ": ";
                cin >> datoIngresado;
                lista.push_back(datoIngresado);
            }
            menuOrdenamiento(lista);
            break;
        }
        default:
        {
            if (opcion < 1 || opcion > 5)
                cout << "Por favor elegir: 1, 2, 3, 4 o 5";
        }
        }
        cout << endl;
        // No sale del men£ hasta que presionen 5
    } while (opcion != 5);
    return 0;
}