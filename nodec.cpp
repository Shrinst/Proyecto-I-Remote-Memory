/*
 * Copyright (C) 2009 Ronny Yabar Aizcorbe <ronnycontacto@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU Lesser General Public License,
 * version 2.1, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
 * more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "nodec.h"

/**
*@brief Constructor principal
*/
template<typename T>

Nodec<T>::Nodec()
{
    data = NULL;
    next = NULL;
    key = NULL;
}

/**
*@brief Constructor por parametro
*/
template<typename T>
Nodec<T>::Nodec(T data_, T key_)
{
    data = data_;
    key = key_;
    next = NULL;
}

/**
*@brief Elimina todos los nodos
*/
template<typename T>
void Nodec<T>::delete_all()
{
    if (next)
        next->delete_all();
    delete this;
}

/**
*@brief Imprime los nodos existentes
*/
template<typename T>
void Nodec<T>::print()
{
    //cout << "Node-> " << "Dato: " << dato << " Direcion: " << this << " Siguiente: " << next << endl;
    cout << key << "-> ";
}

template<typename T>
Nodec<T>::~Nodec() {}
