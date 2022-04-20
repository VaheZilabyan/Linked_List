#include <iostream>

using namespace std;

struct usanox {
	char azganun[20];
	int gnahatakan;
	int bacakayutyun;
	int nkatoxutyun;
};

struct node
{
	usanox a;
	node *next;
	node *prev;
};

class list
{
private:
	node *head;
	
public:
	
	list():head(NULL) {}
	int length();
	void add_first();
	void add_last();
	void add_med();
    void del_first();
    void del_last();
    void del_med();
    void show();
    void information();
    void swap();
    int nkatoxutyunner();
    void nor_cucak();
    usanox nermucel();
   ~list();
};

int list::length()
{
	node *temp = head;
	int l = 0;
	while (temp != NULL)
	{
		l++;
		temp = temp->next;
	}

	return l;
}

usanox list::nermucel()
{
	usanox  y;
	cout << endl;
	cout << "Nermucel Usanoxi tvyalnery`" << endl;
	cout << "Azganun:";
	cin >> y.azganun;
	
	do {
		cout << "Gnahatakan:";
		cin >> y.gnahatakan;
	} while (y.gnahatakan < 0 || y.gnahatakan>100);
	
	do
	{
		cout << "Bacakayutyun:";
		cin >> y.bacakayutyun;
	} while (y.bacakayutyun < 0);
	
	do
	{
		cout << "Nkatoxutyun:";
		cin >> y.nkatoxutyun;
	} while (y.nkatoxutyun < 0);
	
	return y;
}

int list::nkatoxutyunner()
{

	node *temp = head;
	int l = 0;
	if (temp != NULL)
	{
		while (temp != NULL)
		{
			l += temp->a.nkatoxutyun;
			temp = temp->next;
		}

		cout << "@ndhanur nkatoxutyunner = "<< l <<endl;
		return l;
	}
	else
	{
		cout << "datark e" << endl;
		return 0;
	}

}
void list::nor_cucak()
{
	node *temp = head;
	node *nor = new node;
	int l = length();
	int n,q=0;
	int m = 0;
	if (temp != NULL)
	{
		cout<<"Nermucel tiv: ";
		cin>>n;
		for (int i = 0; i < l; i++)
		{
			if (temp->a.nkatoxutyun > n)
			{		
				nor->a = temp->a;
				cout <<"["<< nor->a.azganun << " " << nor->a.gnahatakan <<" "<<nor->a.bacakayutyun<<" "<<nor->a.nkatoxutyun<<"]"<< endl;		
				m++;		
			}
		
			temp = temp->next;	
		}
		if (m == 0)
		cout << "Cucakum aydpisi tarr chka"<<endl;
	} 	
	else
	{
		cout << "Cucaky datark e" << endl;
	}
	
}


void list::information()
{
	node *temp = head;
	int d;

	if (temp != NULL)
	{
		do
		{
			cout << "dirq=";
			cin >> d;
		} while (d<1 || d > length());
		for (int i = 1; i < d; i++) temp = temp->next;
		int l;
		cout << "1.azganun" << endl;
		cout << "2.gnahatakan" << endl;
		cout << "3.bacakayutyun" << endl;
		cout << "4.nkatoxutyun" << endl;
		cout << "5.elq" << endl;
		do
		{
			cout << "gorcoxutyun="; cin >> l;
			switch (l)
			{
			case 1:
			{
				cout << "Azganun:" << temp->a.azganun << endl;
				break;
			}
			case 2:
			{
				cout << "Gnahatakan:" << temp->a.gnahatakan << endl;
				break;
			}
			case 3:
			{
				cout << "Bacakayutyun:" << temp->a.bacakayutyun << endl;
				break;
			}
			case 4:
			{
				cout << "Nkatoxutyun:" << temp->a.nkatoxutyun << endl;
				break;
			}
			}
		} while (l != 5); if (l == 5) cout << "durs ekav" << endl;;

	}
	else
		cout << "datark e" << endl;
}

void list::add_first()
{

	node *temp = new node;
	temp->a = nermucel();
	temp->prev = NULL;
	if (head != NULL)
	{
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	else
	{
		temp->next = NULL;
		head = temp;
	}
}

void list::add_last()
{

	node *temp1 = head;
	node *temp = new node;
	
	temp->a = nermucel();
	if (head!=NULL)
	{
		while (temp1->next != NULL) temp1 = temp1->next;
		temp->next = NULL;
		temp1->next = temp;
		temp->prev = temp1;
	}
	else
	{
		temp->prev = NULL;
		head = temp;
	}

}
void list::add_med()
{
	node *head1 = head;
	node *head2 = head;

	if (head != NULL)
	{
		int dirq;
		do {
			cout << "dirq=";
			cin >> dirq;
		} while (dirq<1 || dirq>length() + 1);
		if (dirq == 1)
		{
			add_first();
			return;
		}
		if (dirq == length() + 1)
		{
			add_last();
			return;
		} 
		{
			for (int i = 1; i < dirq - 1; i++)
				head1 = head1->next;
			node *temp = new node;
			
			node *head2 = head1->next;
			head1->next = temp;
			temp->prev = head1;
			temp->next = head2;
			head2->prev = temp;
			temp->a = nermucel();
			return;
		}
	}
	else
	{
		node *temp = new node;
		temp->next = NULL;
		temp->a = nermucel();
		head = temp;
	}

	{
		return;
	}
}

void list::del_first()
{
	int l = length();
	node* temp = head;
	if (temp != NULL)
	{

		if (l == 1)
		{
			head = NULL;
			delete head;
			return;
		}
		
		temp = head->next;
		temp->prev = NULL;
		delete head;
		head = temp;
	}
	else cout << "datarkic jnjel chi kareli" << endl;
}


void list::del_last() {

	int l = 0;
	node* temp = head;
	node* temp1 = head;

	if (head != NULL) {
		if (length() == 1)
		{
			cout << "cucak@ datarkvec" << endl;
			head = NULL;
			delete head;
			return;
		}

		do {
			temp1 = temp1->next;
			l++;
		} while (temp1->next != NULL);

		for (int i = 1; i<l; i++)
			temp = temp->next;

		temp->next = NULL;
		delete temp->next;

	}
	else
	{
		cout << "datarkic jnjel chi kareli" << endl; //return;
	}
}


void list::del_med()
{
	int tex;

	if (head != NULL)
	{
		if (length() == 1)
		{
			head = NULL;
			delete head;
			cout << "miaky jnjvec" << endl; 
			return;
		}
		do
		{
			cout << "dirq=";
			cin >> tex;
		} while (tex<1 || tex>length());

		node *temp = head;
		node *temp1 = head;
		node *temp2 = head;
		if (tex == 1)
		{
			del_first();
			return;
		}
		if (tex == length())
		{
			del_last();
			return;
		}

		{
			for (int i = 1; i < tex; i++)
				temp = temp->next;
			for (int i = 1; i < tex - 1; i++)
				temp1 = temp1->next;
			for (int i = 1; i < tex + 1; i++)
				temp2 = temp2->next;
		}
		temp1->next = temp2;
		temp2->prev = temp1;
		delete temp;
	}
	else cout << "datarkic jnjel chi kareli" << endl;
}

void list::show()
{
	node *temp = head;
	if (temp != NULL) {

		while (temp != NULL)
		{
			cout <<"["<< temp->a.azganun << " " << temp->a.gnahatakan <<" "<<temp->a.bacakayutyun<<" "<<temp->a.nkatoxutyun<<"]"<< endl;
			temp = temp->next;
		}
	}
	else cout << "datark e" << endl;
}

void list::swap()
{
	int l, k;
	node *temp = head;
	node *temp1 = head;
	if (length() >= 2)
	{
		do {
			cout << "l="; cin >> l;
			cout << "k="; cin >> k;
		} while (l<1 || l>length() || k<1 || k>length());
		if (l < k)
		{
			for (int i = 1; i < l; i++)
				temp = temp->next;
			for (int i = 1; i < k; i++)
				temp1 = temp1->next;

			usanox t;
			t = temp->a;
			temp->a = temp1->a;
			temp1->a = t;
		}
		else {

			for (int i = 1; i < k; i++)
				temp = temp->next;
			for (int i = 1; i < l; i++)
				temp1 = temp1->next;

			usanox t;
			t = temp->a;
			temp->a = temp1->a;
			temp1->a = t;
		}
		if (l == k) cout << "ban chpoxvec" << endl;
	}
	else cout << "bavakan tarrer chkan";
}

list::~list()
{
	while (head)
	{
		delete head;
		head = head->next;
	}
};


int main()
{
	int l;
	list ob;

	cout << "       Menu      " << endl;
	cout << "1.Cucaky tpox funkcia" << endl;
	cout << "2.Cucaki skzbic cucaki miavor avelacnox funkcia" << endl;
	cout << "3.Cucaki verjic cucaki miavor avelacnox funkcia" << endl;
	cout << "4.Cucaki trvac texum cucaki miavor avelacnox funkcia" << endl;
	cout << "5.Cucaki skzbic cucaki miavor heracnox funkcia" << endl;
	cout << "6.Cucaki verjic cucaki miavor heracnox funkcia" << endl;
	cout << "7.Cucaki trvac texic cucaki miavor heracnox funkcia" << endl;
	cout << "8.Cucaki erku kamayakan miavor poxanakox funkcia" << endl;
	cout << "9.Pntrvox arjeq" << endl;
	cout << "10.Usanoxneri yndhanur nkatoxutyunner" << endl;
	cout << "11.Trvac qanakic avel nkatoxutyun unecox usanoxneri cucak" << endl;
	cout << "12.Elq" << endl;
	do
	{
		cin >> l;
		switch (l)
		{
			case 1:
			{
				ob.show();
				break;
			}
			case 2:
			{
				ob.add_first();
				break;
			}
			case 3:
			{
				ob.add_last();
				break;
			}
			case 4:
			{
				ob.add_med();
				break;
			}
			case 5:
			{
				ob.del_first();
				break;
			}
			case 6:
			{
				ob.del_last();
				break;
			}
			case 7:
			{
				ob.del_med();
				break;
			}
			case 8:
			{
				ob.swap();
				break;
			}
			case 9:
			{
				ob.information();
				break;
			}
			case 10:
			{
				ob.nkatoxutyunner();
				break;
			}
			case 11:
			{
				ob.nor_cucak();
				break;
			}
			default:
			{
				cout << "sxal e yntrvel" << endl;
				break;
			}
		}
	} while (l != 12);

	return 0;
}
