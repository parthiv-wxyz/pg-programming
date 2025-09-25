#include<iostream>
using namespace std;
class polynomial
{
	int coeff[10],exp[10],n;
	public:
		void read();
		polynomial add (polynomial);
		void display();
};
void polynomial::read()
{
	cout<<"\n enter the number of terms:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"\n enter the coefficient:";
		  cin>>coeff[i];
		  cout<<"\n enter the exponent:";
		  cin>>exp[i];
	}
}
polynomial polynomial::add(polynomial p2)
{
	polynomial temp;
	int i=0,j=0,k=0;
	while((i<n)&&(j<p2.n))
	{
		if(exp[i]==p2.exp[j])
		{
			temp.coeff[k]=coeff[i]+p2.coeff[j];
			temp.exp[k]=exp[i];
			i++;
			j++;
		}
		else if(exp[i]>p2.exp[j])
		{
			temp.coeff[k]=coeff[i];
			temp.exp[k]=p2.exp[i];
			i++;
		}
		else
		{
			temp.coeff[k]=p2.coeff[j];
			temp.exp[k]=p2.exp[j];
			j++;
		}
 		k++;
	}
	while(i!=n)
	{
		temp.coeff[k]=coeff[i];
		temp.exp[k]=exp[i];
		i++;
		k++;
	}

	while(j!=p2.n)
	{
	 	temp.coeff[k]=p2.coeff[j];
		temp.exp[k]=p2.exp[j];
		j++;
		k++;
	}
	temp.n=k;
	return(temp);
}

void polynomial::display()
{ 
	int i;
	for(i=0;i<n;i++)
	{
	  cout<<coeff[i]<<"x^"<<exp[i]<<"+";
	}
}
int main()
{
	 polynomial p1,p2,p3;
	 cout<<"Enter first polynomial: ";
	 p1.read();
	 cout<<"Enter second polynomial: ";
	 p2.read();
	 p3=p1.add(p2);
	 cout<<"\n First polynomial: ";
	 p1.display();
	 cout<<"\nSecond Polynomial: ";
	 p2.display();
	 cout<<"\nThe added value is: ";
	 p3.display();
	 return 0;
}