#include <iostream>
using namespace std;
template<class T>
class LSLSE;

class Alumno
{
private:
    string Nombre;
    string Carrera;
    int TotalMaterias;
    float Promedio;
public:
    Alumno();
    void operator=(Alumno& x);
    Alumno(string N,string C, int TM,float Prm);
    friend std::ostream& operator<<( std::ostream&, Alumno&);
    friend std::istream& operator>>( std::istream&, Alumno&);
    bool operator==(Alumno&p)
    {
        return p.Nombre==Nombre&&p.Carrera==Carrera&&p.Promedio==Promedio&&p.TotalMaterias==TotalMaterias;
    }
    bool operator<(const Alumno& p) const
    {
        return Promedio < p.Promedio;
    }
    bool operator<=(const Alumno& p) const
    {
        return Promedio < p.Promedio;
    }
    bool operator>=(const Alumno& p) const
    {
        return Promedio < p.Promedio;
    }
};
//***************************************************************************************



//****************************Definicion de la clase Pila****************************
//***********************************************************************************



Alumno::Alumno()
{
    Nombre="";
    Carrera="";
    TotalMaterias = 0;
    Promedio = 0;
}

Alumno::Alumno(string N,string C, int TM,float Prm): Nombre(N),Carrera(C),TotalMaterias(TM), Promedio(Prm) {}
void Alumno::operator=(Alumno& x)
{
    Nombre=x.Nombre;
    Carrera = x.Carrera;
    TotalMaterias=x.TotalMaterias;
    Promedio=x.Promedio;
}

std::ostream& operator<<( std::ostream& o, Alumno& p)
{
    o<<"Nombre: "<<p.Nombre<<"\nCarrera: "<<p.Carrera<<"\nTotal de Materias: "<<p.TotalMaterias<<"\nPromedio: "<<p.Promedio<<endl;
    return o;
}
std::istream& operator>>( std::istream& o, Alumno& p)
{
    std::cout<<"\n Inserta nombre: ";
    getline (o,p.Nombre);
    std::cout<<"\n Inserta Carrera: ";
    getline (o,p.Carrera);
    std::cout<<"\n Inserta Total de Materias: ";
    o>>p.TotalMaterias;
    std::cout<<"\n Inserta Promedio: ";
    o>>p.Promedio;
    return o;
}





template<class T>
class node
{
private:
    T data;
    node<T>* sig;
public:
    node():sig(nullptr) {};
    friend class LSLSE<T>;
};

template<class T>
class LSLSE
{
private:
    node<T>* lista;
public:
    LSLSE():lista(nullptr) {};
    bool vacia()const;
    node<T>* ultimo()const;
    node<T>* primero()const;
    node<T>* anterior(node<T>* pos)const;
    void insertar(node<T>* pos, T elem);
    bool eliminar(node<T>* pos);
    void imprimir()const;
    void imprimirTodo()const;
    void agregar(T elem);
    node<T>* buscar(T elem) const;
    void encolar(T elem);
    void desencolar();
};

template<class T>
void LSLSE<T>::desencolar()
{
    //valida si cola esta vacia
    if(vacia() )
    {
        cout<<"Cola Vacia.\n";
    }
    else
    {
        node<T>* aux_borrar = lista; //Nodo a borrar y esta apuntando lo que esta apuntando lista
        lista= lista->sig;
        cout<<"Datos.\n"<<aux_borrar->data<<"\n\n";
        delete aux_borrar;
    }
}


template<class T>
void LSLSE<T>::encolar(T elem)
{
    if(vacia())
    {
        //primero
        node<T>* aux = new node<T>;
        aux->data = elem;
        aux->sig = lista;
        lista = aux;
    }
    else
    {
        //seguientes en ser agregados
        node<T>* aux = new node<T>;
        aux->data = elem;
        aux->sig = nullptr;
        ultimo()->sig = aux;
    }
}


template<class T>
void LSLSE<T>::agregar(T elem)
{
    node<T>* aux = new node<T>;
    aux->data = elem;
    aux->sig = lista;
    lista = aux;

}

template<class T>
node<T>* LSLSE<T>::buscar(T elem) const
{
    node<T>* aux = lista;
    while (aux != nullptr)
    {
        if (aux->data == elem)
        {
            return aux;
        }
        aux = aux->sig;
    }
    return nullptr;
}

template<class T>
void LSLSE<T>::imprimir()const
{
    node<T>* aux=lista;
    while(aux!=nullptr)
    {
        std::cout<<"\n"<<aux->data<<"\n \n";
        aux=aux->sig;
    }
}


template<class T>
void LSLSE<T>::imprimirTodo()const
{
    int cont =0;
    node<T>* aux=lista;
    while(aux!=nullptr)
    {
        aux=aux->sig;
        cont++;
    }
    cout<<"Total:"<<cont<<endl;
}

template<class T>
bool LSLSE<T>::eliminar(node<T>* pos)
{
    if(vacia() || pos==nullptr)
    {
        return false;
    }

    if(pos==lista)
    {
        lista=lista->sig;
    }
    else
    {
        anterior(pos)->sig=pos->sig;
    }
    delete pos;
    return true;
}

template<class T>
void LSLSE<T>::insertar(node<T>* pos, T elem)
{
    node<T>* aux= new node<T>;
    aux->data=elem;
    if(pos==nullptr)
    {
        aux->sig=lista;
        lista=aux;
    }
    else
    {
        aux->sig=pos->sig;
        pos->sig=aux;
    }
}

template<class T>
node<T>* LSLSE<T>::anterior(node<T>* pos)const
{
    if(vacia() || pos==nullptr)
    {
        return nullptr;
    }
    node<T>* aux=lista;
    while(aux!=nullptr && aux->sig!=pos)
    {
        aux=aux->sig;
    }
    return aux;
}

template<class T>
node<T>* LSLSE<T>::primero()const
{
    if(vacia())
    {
        return nullptr;
    }
    return lista;
}


template<class T>
node<T>* LSLSE<T>::ultimo()const
{
    if(vacia())
    {
        return nullptr;
    }
    node<T>* aux=lista;
    while(aux->sig!=nullptr)
    {
        aux=aux->sig;
    }
    return aux;
}

template<class T>
bool LSLSE<T>::vacia()const
{
    if(lista==nullptr)
        return true;
    return false;
}

int main()
{
    LSLSE<Alumno> MiLista;
    Alumno MiAlumno;
    //node<Alumno>* SocioEncontrado;
    //int a=0;
    int opc=0;
    do
    {
        cout<<"_________-*-_________\n";
        cout<<"1. Dar de alta la solicitud de un alumno.\n";
        cout<<"2. Elaborar una constancia.\n";
        cout<<"3. Generar un reporte con los datos de todos los Alumnos.\n";
        // cout<<"4. Buscar por nombre y domicilio a un socio del club.\n";
        //cout<<"5. Calcular e imprimir el total de socios registrados.\n";
        cout<<"_________-*-_________\n";

        cout<<">>";
        cin>>opc;
        cin.ignore();
        switch(opc)
        {
        case 1:
            cout<<"Ingrese los datos del Alumno\n";
            cin>>MiAlumno;
            MiLista.encolar(MiAlumno);

            break;

        case 2:
            cout<<"Se elaboro la contacia\n\n";
            MiLista.desencolar();

            break;
        case 3:
            cout<<"3.Se genero el reporte \n";
            MiLista.imprimir();
            break;/*
        case 4:
            cout<<"Ingrese nombre y domicilio \n";
            cin>>MiSocio;
            cin.ignore();
            SocioEncontrado=MiLista.buscar(MiSocio);
            if (SocioEncontrado != nullptr)
            {
                cout<<"\n\nSocio Encontrado.\n";
                cout<<MiSocio;

            }
            else
            {
                std::cout << "\n\nSocio:\n" << MiSocio << "\nNo encontrado en la lista." << std::endl;
            }
            break;
        case 5:
            MiLista.imprimirTodo();
            break;*/
        }
    }
    while(opc!=4);

    return 0;
}
