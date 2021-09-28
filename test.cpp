#include "pch.h"

#include "../HuntTheWumpus/ListaCuevasAdy.h"
#include "../HuntTheWumpus/Cueva.h"
#include "../HuntTheWumpus/Cazador.h"
#include "../HuntTheWumpus/Laberinto.h"
#include "../HuntTheWumpus/Wumpus.h"

class HuntTheWumpusPrueba : public ::testing::Test {
protected:
	/* DATOS COMUNES A CASOS DE PRUEBA */
	ListaCuevasAdy trp;
	// Constructor inicializador del suite de pruebas.
	HuntTheWumpusPrueba();
	// Destructor del suite de pruebas.
	~HuntTheWumpusPrueba() override;
	/* INICIALIZACION DE LAS PRUEBAS, puede eliminarse si no se usa.*/
	// se invoca al iniciar cada prueba del accesorio.00
	void SetUp() override;
	/* FINALIZACION DE LAS PRUEBAS, puede eliminarse si no se usa*/
	// se invoca al finalizar cada prueba del accesorio.
	void TearDown() override;
};
/* DEFINICI�N DE LOS M�TODOS B�SICOS DEL ACCESORIO */
HuntTheWumpusPrueba::HuntTheWumpusPrueba()
{}
HuntTheWumpusPrueba::~HuntTheWumpusPrueba()
{}
void HuntTheWumpusPrueba::SetUp()
{}
void HuntTheWumpusPrueba::TearDown()
{}





/* CASOS DE PRUEBA */
//Caso 1.1
//CAMBIAr a la lista de Jeremy una vez el constructor este hecho
TEST_F(HuntTheWumpusPrueba, InicializacionCorrecta)
{
	trp.obtAdyacencias();
	EXPECT_EQ(trp.obtAdyacencias(), 1);
}
//Caso 1.2.1
TEST_F(HuntTheWumpusPrueba, agregarUnElemento)
{
	trp.agrIdCuevaAdy(1);
	//EXPECT DE  tamanio lista uno mas
	EXPECT_EQ(trp.obtCantidadAdy(), 1);
}
//Caso 1.2.2
TEST_F(HuntTheWumpusPrueba, agregarDosElementos)
{
	trp.agrIdCuevaAdy(1);
	trp.agrIdCuevaAdy(2);
	//EXPECT DE  tamanio lista uno mas
	EXPECT_EQ(trp.obtCantidadAdy(), 2);
}
//Caso 1.2.3
TEST_F(HuntTheWumpusPrueba, agregarTresElementos)
{
	trp.agrIdCuevaAdy(1);
	trp.agrIdCuevaAdy(2);
	trp.agrIdCuevaAdy(3);
	//EXPECT DE  tamanio lista uno mas
	EXPECT_EQ(trp.obtCantidadAdy(), 3);
}

// caso 1.3
//falta hacer (Programar las pruebas del constructor de copias abarcando listas de 0, 1, 2 y 3 elementos.)
//NOTA: comprobar usando : toString() y obtCantidadAdy().
TEST_F(HuntTheWumpusPrueba, constructorDeCopias)
{

}

//caso 5.1
// no s� como probar el funcionamiento del mapa DRA
TEST_F(HuntTheWumpusPrueba, funcionamientoDRA)
{

}
//laberinto poliedro constructor no esta hecho todavia
TEST_F(HuntTheWumpusPrueba, labPoliedro)
{

}
// caso 5.4 2 arch(con cinco y con diez cuevas, 3 y 4 adyacencias).
TEST_F(HuntTheWumpusPrueba, lectorDeArchivos)
{

}
//Las del constructor de copias. Abarcar diferentes grafos originales: el DRA y
//al menos otro poliedro regular, as� como un laberinto irregular.
//NOTA: en todos los casos anteriores comprobar cantidad de cuevas y adyacencias por
//cueva con obtCuevasAdy(...).
TEST_F(HuntTheWumpusPrueba, constructorDeCopias)
{

}
//caso 5.5 Las del m�todo void asgEscenario(), comprobar cantidad de pozos, murci�lagos, posici�n del Wumpus y del cazador.
TEST_F(HuntTheWumpusPrueba, metAsgEscenario)
{
	//activar el asg escenario
	// //variable local de posicion wumpus ejm, si despues de Moverwumpus la posicion wumpus es diferente true
	//solicitar posicion pozos, murcielago, wumpus ty cazador