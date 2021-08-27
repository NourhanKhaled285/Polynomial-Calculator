#include "Header.h"
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int v = 0;
node::node(int c, int e) {

	coef = c;
	exp = e;
	next = nullptr;


}

poly_list::poly_list() {
	type_op = 1;
	h1 = t1 = nullptr;
	h2 = t2 = nullptr;
	h3 = t3 = nullptr;
	s1 = 0;
	s2 = 0;
	s3 = 0;

}



void poly_list::insert_pol1(int v1, int v2) {
	node* tmp;


	node* n = new node(v1, v2);
	if (h1 == nullptr) {

		h1 = t1 = n;


	}
	else {

		t1->next = n;
		t1 = t1->next;
	}
	s1++;


}


void poly_list::insert_pol2(int v1, int v2) {


	node* n = new node(v1, v2);
	if (h2 == nullptr) {

		h2 = t2 = n;

	}
	else {

		t2->next = n;
		t2 = t2->next;
	}
	s2++;


}
void poly_list::calc_result(int v1, int v2) {

	node* n = new node(v1, v2);
	if (h3 == nullptr) {

		h3 = t3 = n;


	}
	else {

		t3->next = n;
		t3 = t3->next;
	}
	s3++;


}

void poly_list::insert_polynominal_1()
{
	string x;
	cout << "please enter the first polynominal equation " << endl;
	cin >> x;
	for (int i = 0; i < x.length(); i = i + 5) {
		if (x[i] == '+') {

			insert_pol1(+1 * (x[i + 1] - 48), x[i + 4] - 48);
		}
		else if (x[i] == '-') {

			insert_pol1(-1 * (x[i + 1] - 48), x[i + 4] - 48);
		}

	}
	cout << endl;

}

void poly_list::insert_polynominal_2()
{
	string y;
	cout << "please enter the second polynominal equation " << endl;
	cin >> y;
	for (int i = 0; i < y.length(); i = i + 5) {
		if (y[i] == '+') {
			insert_pol2(+1 * (y[i + 1] - 48), y[i + 4] - 48);
		}
		else if (y[i] == '-') {

			insert_pol2(-1 * (y[i + 1] - 48), y[i + 4] - 48);
		}
		cout << endl;
	}

}


void poly_list::del(int pos) {
	node* tmp = h2;
	if (pos == 0) {
		h2 = h2->next;
		delete tmp;

	}

	else {

		for (int i = 0; i < pos - 1; i++)
			tmp = tmp->next;
		node* del = tmp->next;
		tmp->next = del->next;


		delete del;
		if (pos == s2 - 1) {

			t2 = tmp;
		}
	}
	s2--;


}




void poly_list::add_poly() {


	node* p = h1;

	node* q;

	while (p != nullptr) {
		q = h2;
		int pos_node = 0;
		if (p->exp == q->exp) {

			calc_result(p->coef + q->coef, p->exp);


			del(pos_node);
		}
		else if (p->exp > q->exp || p->exp < q->exp)
		{
			while (true) {

				if (p->exp == q->exp) {

					calc_result(p->coef + q->coef, p->exp);
					del(pos_node);
					break;
				}
				else {
					q = q->next;
					pos_node++;
					if (q == nullptr) {
						calc_result(p->coef, p->exp);
						break;
					}
				}

			}



		}

		p = p->next;


	}


	display_result();

}



/*


void poly_list::sub_poly(){


	node*p=h1;

	node*q;

	while(p!=nullptr){
		q=h2;
	int pos_node=0;
 if(p->exp==q->exp){

	 calc_result(p->coef-q->coef,p->exp);


	del(pos_node);
}
 else if(p->exp>q->exp||p->exp<q->exp)
 {
		 while(true ){

	  if(p->exp==q->exp){

		  calc_result(p->coef-q->coef,p->exp);
		 del(pos_node);
		 break;
		   }
	  else{
		  q=q->next;
		  pos_node++;
		  if(q==nullptr){
			  calc_result(p->coef,p->exp);
			  break;
		  }
	  }

		 }



	 }

   p=p->next;


 }
		cout<<"the subtracting of the polynominals is : "<<endl;
		display_result();
	}


	*/


void poly_list::sub_poly() {
	type_op = 2;
	node* tmp = h2;
	while (tmp != nullptr) {
		tmp->coef = -1 * tmp->coef;
		tmp = tmp->next;

	}
	add_poly();

}




void poly_list::multi_poly() {
	v = -1;
	type_op = 3;
	int i = 0;
	node* p = h1;

	int* arr = new int[100];

	while (p != nullptr) {
		node* q = h2;
		while (q != nullptr) {
			arr[i] = p->coef * q->coef;

			arr[i + 1] = p->exp + q->exp;

			i = i + 2;
			q = q->next;


		}
		p = p->next;

	}




	for (int x = 1; x < i; x = x + 2) {
		int r = 0;
		bool b = false;
		bool s = false;
		for (int y = x + 2; y < i; y = y + 2) {
			if (arr[x] == arr[y]) {
				b = true;

				r = (arr[x - 1] + arr[y - 1]);

			}

		}
		if (b == true) {
			calc_result(r, arr[x]);
		}
		else if (b == false) {
			for (int z = 1; z < x; z = z + 2) {
				if (arr[x] == arr[z]) {
					s = true;

				}

			}
			if (s == false) {
				calc_result(arr[x - 1], arr[x]);
			}
		}

	}

	display_result();
}





void poly_list::display_result() {
	node* tm2 = h2;
	node* tm3 = h3;
	if (type_op == 1) {
		cout << "the addition of polynominals is : " << endl;
	}
	else if (type_op == 2) {
		cout << "the subtracting of polynominals is : " << endl;
	}
	else if (type_op == 3) {
		cout << "the multiplication of polynominals is : " << endl;
	}

	while (tm3 != nullptr) {
		if (tm3->coef >= 0) {
			cout << "+";
		}
		cout << tm3->coef << " x^ " << tm3->exp;



		tm3 = tm3->next;
	}
	if (v != -1) {
		while (tm2 != nullptr) {
			if (tm2->coef >= 0) {
				cout << "+";
			}
			cout << tm2->coef << " x^ " << tm2->exp;

			tm2 = tm2->next;

		}
	}
	cout << endl;
	cout << endl;

}
/*
node*tmp=h3;
cout<<"the multiplication of polynominals is : "<<endl;
while(tmp!=nullptr){
	if(tmp->coef>=0){
	cout<<"+";
}
	cout<<tmp->coef<<" x^ "<<tmp->exp;

	tmp=tmp->next;

}
cout<<endl;
cout<<endl;
*/