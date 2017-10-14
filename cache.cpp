#include "cache.h"

using namespace std;

/**
*@brief Constructor por defecto
*/
template<typename T>
List1<T>::List1()
{
    m_num_nodes = 0;
    m_head = NULL;
}

/**
*@brief Insertar al inicio
*@param data_ dato
*@param key_ llave
*/
template<typename T>
void List1<T>::add_head(T data_, T key_)
{
    if(m_num_nodes == 5){
        del_by_position(5);
    }
    Node<T> *new_node = new Node<T> (data_, key_);
    Node<T> *temp = m_head;

    if (!m_head) {
        m_head = new_node;
    } else {
        new_node->next = m_head;
        m_head = new_node;

        while (temp) {
            temp = temp->next;
        }
    }
    m_num_nodes++;
}
/**
*@brief Elimina todos los nodos
*/
template<typename T>
void List1<T>::del_all()
{
    m_head->delete_all();
    m_head = 0;
}
/**
*@brief Indica la cantidad de nodos actuales de la memoria
*@return cantidad de nodos
*/
template<typename T>
int List1<T>::cant()
{
    return m_num_nodes;
}
/**
*@brief Elimina por data
*@param data_
*/
template<typename T>
void List1<T>::del_by_data(T key_)
{
    Node<T> *temp = m_head;
    Node<T> *temp1 = m_head->next;

    int cont = 0;

    if (m_head->key == key_) {
        m_head = temp->next;
    } else {
        while (temp1) {
            if (temp1->key == key_) {
                Node<T> *aux_node = temp1;
                temp->next = temp1->next;
                delete aux_node;
                cont++;
                m_num_nodes--;
            }
            temp = temp->next;
            temp1 = temp1->next;
        }
    }

    if (cont == 0) {
        cout << "No existe el dato " << endl;
    }
}

/**
*@brief Elimina un nodo por su posicion
*@param pos
*/
template<typename T>
void List1<T>::del_by_position(int pos)
{
    Node<T> *temp = m_head;
    Node<T> *temp1 = temp->next;

    if (pos < 1 || pos > m_num_nodes) {
        cout << "Fuera de rango " << endl;
    } else if (pos == 1) {
        m_head = temp->next;
    } else {
        for (int i = 2; i <= pos; i++) {
            if (i == pos) {
                Node<T> *aux_node = temp1;
                temp->next = temp1->next;
                delete aux_node;
                m_num_nodes--;
            }
            temp = temp->next;
            temp1 = temp1->next;
        }
    }
}
template<typename T>
string List1<T>::getkey(int pos)
{
    Node<T> *temp = m_head;

    for (int i = 0; i < pos; i++) {
            if (i+1 == pos) {
                return temp->key;
            }
            temp = temp->next;
        }
}
template<typename T>
string List1<T>::getvalue(int pos)
{
    Node<T> *temp = m_head;

    for (int i = 0; i < pos; i++) {
            if (i+1 == pos) {
                return temp->data;
            }
            temp = temp->next;
        }
}
/**
*@brief Printea la lista
*/
template<typename T>
void List1<T>::print()
{
    Node<T> *temp = m_head;
    if (!m_head) {
        cout << "La Lista está vacía " << endl;
    } else {
        while (temp) {
            temp->print();
            if (!temp->next) cout << "NULL";
                temp = temp->next;
        }
  }
  cout << endl << endl;
}

/**
*@brief Busca un nodo por key
*@param key
*@return 1 si lo encuentra o 0 si no lo hace
*/
template<typename T>
int List1<T>::search(T key_)
{
    Node<T> *temp = m_head;
    int cont = 1;
    int cont2 = 0;

    while (temp) {
        if (temp->key == key_) {
            return 1;
            cont2++;
            break;
        }
        temp = temp->next;
        cont++;
    }

    if (cont2 == 0) {
        return 0;
    }
}

template<typename T>
List1<T>::~List1() {}
