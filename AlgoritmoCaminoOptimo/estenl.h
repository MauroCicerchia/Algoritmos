#include <iostream>
template <typename t> struct Nodo {
	t info;
	Nodo *sig;
};

template <typename t> Nodo<t> *crearNodo(t info) {
	Nodo<t> *p = new Nodo<t>();
	p->info = info;
	return p;
}

/*Pila*/

template <typename t> t push(Nodo<t> *&p, t info) {
	Nodo<t> *q = crearNodo<t>(info);
	q->sig = p;
	p = q;
}

template <typename t> t pop(Nodo<t> *&p) {
	Nodo<t> *q = p->sig;
	t info = p->info;
	delete p;
	p = q;
	return info;
}

template <typename t> void vaciarPila(Nodo<t> *&p) {
	while(p != NULL) {
		pop<t>(p);
	}
}

/*Cola*/

template <typename t> void agregar(Nodo<t> *&p, Nodo<t> *&f, t info) {
	if(p == NULL) {
		p = crearNodo<t>(info);
		p->sig = NULL;
		f = p;
	} else {
		Nodo<t> *q = crearNodo<t>(info);
		f->sig = q;
		f = q;
	}
}

template <typename t> t suprimir(Nodo<t> *&p, Nodo<t> *&f) {
	if(p != NULL) {
		Nodo<t> *q = p;
		p = p->sig;
		t info = q->info;
		if(q->sig == NULL) {
			f = NULL;
		}
		delete q;
		return info;
	}
}

template <typename t> void vaciarCola(Nodo<t> *&p, Nodo<t> *&f) {
	while(p != NULL) {
		suprimir<t>(p, f);
	}
}

/*Lista*/

template <typename t> void insertar(Nodo<t> *&p, t info) {
	if(p == NULL) {
		p = crearNodo<t>(info);
		p->sig = NULL;
	} else {
		Nodo<t> *q = p, *r = crearNodo<t>(info);
		if(r->info < p->info) {
			r->sig = p;
			p = r;
		} else {
			while(q->sig != NULL && r->info > q->sig->info) {
				q = q->sig;
			}
			r->sig = q->sig;
			q->sig = r;
		}
	}
}

template <typename t> int eliminar(Nodo<t> *&p, t info) {
	if(p != NULL) {
		Nodo<t> *q = p, *r;
		
		if(info == p->info) {
			p = p->sig;
			delete q;
			return 1;
		} else {
			while(q->sig != NULL && q->sig->info != info) {
				q = q->sig;
			}
			r = q->sig;
			if(r != NULL) {
				q->sig = r->sig;
				delete r;
				return 1;
			} else {
				return 0;
			}
		}
	} else return 0;
}

template <typename t> void swap(Nodo<t> *&p, int p1, int p2) {
	Nodo<t> *q = p, *r = p;
	for(int i = 0; i < p1; i++) {
		q = q->sig;
	}
	for(int i = 0; i < p2; i++) {
		r = r->sig;
	}
	t aux = q->info;
	q->info = r->info;
	r->info = aux;
}

template <typename t> void mostrar(Nodo<t> *p) {
	while(p->sig != NULL) {
		std::cout << p->info << ", ";
		p = p->sig;
	}
	std::cout << p->info;
}
