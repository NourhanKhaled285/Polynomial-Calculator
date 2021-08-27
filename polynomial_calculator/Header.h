
class node {

public:
	int coef;
	int exp;
	node* next;
	node(int c, int e);


};

class poly_list {
	int type_op;
	node* h1;
	node* t1;

	node* h2;
	node* t2;

	node* h3;
	node* t3;

	int s1;
	int s2;
	int s3;

public:
	poly_list();
	void insert_pol1(int v1, int v2);
	void insert_pol2(int v1, int v2);
	void calc_result(int v1, int v2);


	void add_poly();
	void sub_poly();
	void multi_poly();
	void del(int pos);
	void display_result();
	void insert_polynominal_1();
	void insert_polynominal_2();

};
