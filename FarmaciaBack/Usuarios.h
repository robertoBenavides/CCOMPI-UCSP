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
public:
	Usuarios();
	Usuarios(TipoUsuarios *);
	void createUser(Usuario);
	void updateUser(Usuario);
	void deleteUser(int);
	int getById(int);
	void toString();
	void saveData();
};

