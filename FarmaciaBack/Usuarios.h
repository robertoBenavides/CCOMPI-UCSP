#pragma once
#include "TipoUsuarios.h"
#include "Usuario.h"
#include "vector"
class Usuarios
{
private:
	vector<Usuario> usuarios;
	TipoUsuarios *tipousuarios;
	int bBusca(vector<Usuario>, int, int, int);
	void loadData();
	int getIndexById(int);
public:
	Usuarios();
	Usuarios(TipoUsuarios *);
	void createUser(Usuario);
	void updateUser(Usuario);
	void deleteUser(int);
	Usuario* getById(int);
	void toString();
	void saveData();
};

