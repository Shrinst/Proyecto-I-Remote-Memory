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

#ifndef NODEC_H
#define NODEC_H

#include <iostream>

using namespace std;

template <class T>

class Nodec
{
    public:
        Nodec();
        Nodec(T, T);
        ~Nodec();

        Nodec *next;
        T data;
        T key;

        void delete_all();
        void print();
};

#endif // NODE_H
