#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Persona
	{ 
		private:
		string nombre, direccion;
		int telefono;

		public:
		Persona ();
		Persona (string, string, int);
		void SetNombre (string);
		void SetDireccion (string);
		void SetTelefono (int);
		string GetNombre ( );
		string GetDireccion ( );
		int GetTelefono ( );
	};

Persona::Persona ( )
	{
		this->nombre = this->direccion = "";
		this->telefono = 0;
	}

Persona::Persona (string nombre, string direccion, int telefono)
	{
		this->nombre = nombre;
		this->direccion = direccion;
		this->telefono = telefono;
	}
	
void Persona::SetNombre (string nombre)
	{
		this->nombre = nombre;
	}

void Persona::SetDireccion (string direccion)
	{
		this->direccion = direccion;
	}
	
void Persona::SetTelefono (int telefono)
	{
		this->telefono = telefono;
	}

string Persona::GetNombre ( )
	{
		return (this->nombre);
	}

string Persona::GetDireccion ( )
	{
		return (this->direccion);
	}
	
int Persona::GetTelefono ( )
	{
		return (this->telefono);
	}


class Guia
	{ 
		private:
		Persona *agenda;
		int num_personas, max_personas;
 
		public:
		Guia (int);
		int GetNum_personas ( );
		int GetMax_personas ( );
		bool AgregarPersona (Persona);
		int Buscar (string);
		string Buscar (int);
		string Buscar (int, string);
	};
	
Guia::Guia (int max_personas)
	{
		this->max_personas = max_personas;
		this->num_personas = 0;
		this->agenda = new Persona [max_personas];
	}
	
int Guia::GetNum_personas ( )
	{
		return (num_personas);
	}
	
int Guia::GetMax_personas ( )
	{
		return (max_personas);
	}

bool Guia::AgregarPersona (Persona nueva)
	{
		if (this->num_personas == this->max_personas)
		return (false); // No hay espacio en la agenda
		else
		{ 
			this->agenda [this->num_personas] = nueva;
			++ this->num_personas;
			return (true);
		}
	}
	
int Guia::Buscar (string nombre)
	{ 
		int ix;
		for (ix = 0; ix < this->num_personas; ++ ix)
			{ 
				if (this->agenda[ix].GetNombre ( ) == nombre)
				return (this->agenda[ix].GetTelefono ( ));
			}
			
		return (-1); // Nombre no encontrado
	}
	
string Guia::Buscar (int telefono)
	{
		int ix;
		for (ix = 0; ix < this->num_personas; ++ ix)
			{ 
				if (this->agenda[ix].GetTelefono ( ) == telefono)
				return (this->agenda[ix].GetDireccion ( ));
			}
		return (""); // Telefono no encontrado
	}
	
string Guia::Buscar (int telefono, string direccion)
	{ 
		int ix;
		for (ix = 0; ix < this->num_personas; ++ ix)
			{ 
				if (this->agenda[ix].GetTelefono ( ) == telefono &&
				this->agenda[ix].GetDireccion ( )== direccion)
				return (this->agenda[ix].GetNombre ( ));
			}
		return (""); // Telefono y direccion no encontrados
}






		
		int main (int argc, char *argv [ ])
		{ 
			int max, telefono;
			string opcion, nombre, direccion, valor;
			bool fin;
			cout << "Guia de telefonos ++\n";
			cout << "Ingrese maximo de personas en la guia: ";
			getline (cin, valor); stringstream (valor) >> max;
			Guia blanca (max);
			fin = false;
			while (!fin)
				{
					cout << endl
						 << "Opciones disponibles:" << endl
						 << " a: agregar persona" << endl
						 << " b: buscar telefono por nombre" << endl
						 << " d: buscar direccion por telefono" << endl
						 << " n: buscar nombre por direccion y telefono" << endl
						 << " f: fin del proceso" << endl
						 << "Ingrese opcion: ";
						 getline (cin, opcion);
					if (opcion == "a")
						{
							cout << "Ingrese nombre : "; getline (cin, nombre);
							cout << "Ingrese direccion: "; getline (cin, direccion);
							cout << "Ingrese telefono : "; getline (cin, valor);
							stringstream (valor) >> telefono;
							Persona nueva (nombre, direccion, telefono);
							if (blanca.AgregarPersona (nueva))
								cout << ">>> Ingreso exitoso\n";
							else
								cout << ">>> Error en ingreso de persona\n";
						}
					else if (opcion == "b")
						{
								cout << "Ingrese nombre: "; getline (cin, nombre);
								telefono = blanca.Buscar (nombre);
								if (telefono == -1)
								cout << ">>> Ese nombre no tiene telefono\n";
								else
								cout << ">>> Telefono es: " << telefono << endl;
						}
					else if (opcion == "d")
					{ 
								cout << "Ingrese telefono: ";
								getline (cin, valor); stringstream (valor) >> telefono;
								valor = blanca.Buscar (telefono);
					if (valor == "")
								cout << ">>> Telefono no registrado en la guia\n";
					else
								cout << ">>> La direccion es: " << valor << endl;
					}
 
					else if (opcion == "n")
					{ 
						cout << "Ingrese direccion: "; getline (cin, direccion);
						cout << "Ingrese telefono: "; getline (cin, valor);
						stringstream (valor) >> telefono;
						valor = blanca.Buscar (telefono, direccion);
					if (valor == "")
						cout << ">>> Direccion y telefono no encontrados\n";
					else
						cout << ">>> El nombre es: " << valor << endl;
					}
					else if (opcion == "f")
						fin = true;
					else
						cout << ">>> Opcion erronea, trate de nuevo\n";
			}
			
		cout << endl << "Numero de personas en la guia: "
		<< blanca.GetNum_personas ( ) << endl;
		cout << "Cerramos la Guia ++" << endl;
		return (0);
}
