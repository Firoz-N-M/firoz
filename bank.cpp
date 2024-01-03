#include<iostream>
#include<string>
using namespace std;
class bankempolyee{
	private:
		string name;
		int accountno;
		double balance;

	public:
		bankempolyee(string e ,int ano,double ib)
		{
			name=e;
			accountno=ano;
			balance=ib;
		}
		void printdetails()
		{
			cout<<"empolyee name:"<<name<<endl;
			cout<<"account number :"<<accountno<<endl;
			cout<<"balance:"<<balance<<endl;
		}
		void withdraw(double amount){ 
			if(amount>balance ){

			cout<<"invalid balance .insufficent funds"<<endl;}
			else {
				balance-=amount;
				cout<<"deposit sucessful new balance:"<<balance<<endl;}
		}
		void deposit(double amount ){
			balance+=amount;
			cout<<"deposit sucessful.new balance:"<<balance<<endl;
		}};
int main(){
	string empolyeename;
	int accountnumber;
	double intialbalance;
	cout<<"enter empolyee name:"<<endl;
	getline(cin,empolyeename);
	cout<<"enter account number:"<<endl;
	cin>>accountnumber;
	cout<<"enter the intial balance:"<<endl;
	cin>>intialbalance;
	bankempolyee emp(empolyeename,accountnumber,intialbalance);
	emp.printdetails();
	double withdrawamount,depositamount;
	cout<<"enter the amount to withdraw"<<endl;
	cin>>withdrawamount;
	emp.withdraw(withdrawamount);
	cout<<"enter the deposit amount:"<<endl;
	cin>>depositamount;
        emp.deposit(depositamount);
	return 0;}


