#include "Juego.h"

Juego::Juego(const Mapa& mapa) : _mapa(mapa) {
}

const Mapa &Juego::ObtenerMapa() const {
    return _mapa;
}

void Juego::AgregarPokemon(Pokemon pk, Coordenada c) {
    /*
    _cantPokemons++;
    if(_pokemons.Definido(pk)){
        aed2::Nat nuevaCant = _pokemons.Obtener(pk) + 1;
        _pokemons.Definir(pk, nuevaCant);
    }else{
        _pokemons.Definir(pk, 1);
    }
    _grillaPos[c.latitud][c.longitud].hayPokemon = true;
    _grillaPos[c.latitud][c.longitud].pokemon = pk;
    _grillaPos[c.latitud][c.longitud].contadorCaptura = 0;
    //TODO: ACA HAY QUE BORRAR LA COLA ANTERIOR
     */
}

aed2::Nat Juego::AgregarJugador() {
    aed2::Nat res = _jugadores.Longitud();
    infoJugador* jugador = new infoJugador();
    _jugadores.AgregarAtras(jugador);
    return res;
}

void Juego::Conectarse(Jugador j, Coordenada c) {
    _jugadores[j]->conectado = true;
    _jugadores[j]->posicion = c;
    _grillaPos[c.latitud][c.longitud].jugsEnPos.Agregar(j);
    AgregarACola(j);
    ResetearContadores(j);
}

void Juego::Desconectarse(Jugador j) {
    Coordenada c = _jugadores[j]->posicion;
    _jugadores[j]->conectado = false;
    _grillaPos[c.latitud][c.longitud].jugsEnPos.Borrar(j);
}

bool Juego::EstaConectado(Jugador j) const {
    return _jugadores[j]->conectado;
}

aed2::Nat Juego::Sanciones(Jugador j) const {
    return _jugadores[j]->sanciones;
}

Coordenada Juego::Posicion(Jugador j) const {
    return _jugadores[j]->posicion;
}

const aed2::Conj<Coordenada> &Juego::PosConPokemons() const {
    return _posConPokemons;
}

const Pokemon &Juego::PokemonEnPos(Coordenada c) const {
    return _grillaPos[c.latitud][c.longitud].pokemon;
}

bool Juego::PuedoAgregarPokemon(Coordenada c) const {
    return _mapa.PosExistente(c);//TODO: && _mapa.HayPokemonEnDistancia(c, 5);
}






























